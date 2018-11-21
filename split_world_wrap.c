#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define K_COMPUTER //enable for compilation on K computer

#ifndef _EXTERN_C_
#ifdef __cplusplus
#define _EXTERN_C_ extern "C"
#else /* __cplusplus */
#define _EXTERN_C_
#endif /* __cplusplus */
#endif /* _EXTERN_C_ */

#ifdef MPICH_HAS_C2F
_EXTERN_C_ void *MPIR_ToPointer(int);
#endif // MPICH_HAS_C2F

#ifdef PIC
/* For shared libraries, declare these weak and figure out which one was linked
   based on which init wrapper was called.  See mpi_init wrappers.  */
#pragma weak pmpi_init
#pragma weak PMPI_INIT
#pragma weak pmpi_init_
#pragma weak pmpi_init__
#endif /* PIC */

_EXTERN_C_ void pmpi_init(MPI_Fint *ierr);
_EXTERN_C_ void PMPI_INIT(MPI_Fint *ierr);
_EXTERN_C_ void pmpi_init_(MPI_Fint *ierr);
_EXTERN_C_ void pmpi_init__(MPI_Fint *ierr);

#if MPI_VERSION >= 3
    #define MPI_CONST const
#else
    #define MPI_CONST
#endif


/*Variables*/
static MPI_Comm MY_COMM_WORLD=MPI_COMM_NULL;
static int split_run = 0;
static int plevel = 1; //enabled by default

static int split_comm(int argc, char**argv)
{
	int err;
	int color=-1, rank;
	void *val;
	int flag;

	err = PMPI_Comm_get_attr( MPI_COMM_WORLD, MPI_APPNUM, &val, &flag );
	if(flag){
		color = *(int*)val; 
	} else {
		char *s = getenv("MPMD_COMP");
		if(s != 0){
			color = atoi(s);
			//printf("I am component %d\n", color);
		}
	} 
	
	if(color == -1)
		color = MPI_UNDEFINED;

	//printf("Will split global world into subworlds\n");
	PMPI_Comm_rank(MPI_COMM_WORLD, &rank);
	err = PMPI_Comm_split(MPI_COMM_WORLD, color, rank, &MY_COMM_WORLD);
	if(err != MPI_SUCCESS)
		printf("Error: error splitting global communicator for individual components\n");
		
	if(MY_COMM_WORLD == MPI_COMM_NULL)
		MY_COMM_WORLD = MPI_COMM_WORLD;
		
	//PMPI_Comm_size(MPI_COMM_WORLD, &nw1);
	//PMPI_Comm_size(MY_COMM_WORLD, &nw2);
	//if(nw1 == nw2)
		//printf("Warning: please do not use parameter -dtf-comp-%%id if you execute each component with a separate mpirun or mpiexec.\n");
	
	return err;
	
}

/* ================== C Wrappers for MPI_Pcontrol ================== */
_EXTERN_C_ int PMPI_Pcontrol(MPI_CONST int level, ...);
_EXTERN_C_ int MPI_Pcontrol(MPI_CONST int level, ...) { 
    int _wrap_py_return_val = 0;
  
  plevel = level;
  
  _wrap_py_return_val = PMPI_Pcontrol(level);
    return _wrap_py_return_val;
}


/* ================== C Wrappers for MPI_Init ================== */
_EXTERN_C_ int PMPI_Init(int *argc, char ***argv);
_EXTERN_C_ int MPI_Init(int *argc, char ***argv) 
{ 
  int err = 0;
    
  err = PMPI_Init(argc, argv);
  
  if(err == MPI_SUCCESS && plevel){
	if(argc != NULL && argv !=NULL)
		err = split_comm(*argc, *argv);	
	else MY_COMM_WORLD = MPI_COMM_WORLD;
  }
  return err;
}

/* ================== C Wrappers for MPI_Init_thread ================== */
_EXTERN_C_ int PMPI_Init_thread(int *argc, char ***argv, int required, int *provided);
_EXTERN_C_ int MPI_Init_thread(int *argc, char ***argv, int required, int *provided) { 
    int err = 0;
 
  err = PMPI_Init_thread(argc, argv, required, provided);
  
  if(err == MPI_SUCCESS && plevel){
  	if(argc != NULL && argv !=NULL)
		err = split_comm(*argc, *argv);	
	else MY_COMM_WORLD = MPI_COMM_WORLD;
  }
  
  return err;
}

/* ================== C Wrappers for MPI_Finalize ================== */
_EXTERN_C_ int PMPI_Finalize();
_EXTERN_C_ int MPI_Finalize() { 
    int err = 0;
	
	if(plevel && split_run)
		err = PMPI_Comm_free(&MY_COMM_WORLD);
	
	err = PMPI_Finalize();
    
    return err;
}

/* ================== C Wrappers for MPI_Comm_rank ================== */
_EXTERN_C_ int PMPI_Comm_rank(MPI_Comm comm, int *rank);
_EXTERN_C_ int MPI_Comm_rank(MPI_Comm comm, int *rank) { 
    int _wrap_py_return_val = 0;
 
    if(plevel && (comm == MPI_COMM_WORLD))
		comm = MY_COMM_WORLD;
   _wrap_py_return_val = PMPI_Comm_rank(comm, rank);

    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Comm_size ================== */
_EXTERN_C_ int PMPI_Comm_size(MPI_Comm comm, int *size);
_EXTERN_C_ int MPI_Comm_size(MPI_Comm comm, int *size) { 
   int _wrap_py_return_val = 0;
   if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Comm_size(comm, size);

    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Abort ================== */
_EXTERN_C_ int PMPI_Abort(MPI_Comm comm, int errorcode);
_EXTERN_C_ int MPI_Abort(MPI_Comm comm, int errorcode) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Abort(comm, errorcode);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Allgather ================== */
_EXTERN_C_ int PMPI_Allgather(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm);
_EXTERN_C_ int MPI_Allgather(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Allgatherv ================== */
_EXTERN_C_ int PMPI_Allgatherv(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_CONST int recvcounts[], MPI_CONST int displs[], MPI_Datatype recvtype, MPI_Comm comm);
_EXTERN_C_ int MPI_Allgatherv(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_CONST int recvcounts[], MPI_CONST int displs[], MPI_Datatype recvtype, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Allreduce ================== */
_EXTERN_C_ int PMPI_Allreduce(MPI_CONST void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);
_EXTERN_C_ int MPI_Allreduce(MPI_CONST void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Allreduce(sendbuf, recvbuf, count, datatype, op, comm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Alltoall ================== */
_EXTERN_C_ int PMPI_Alltoall(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm);
_EXTERN_C_ int MPI_Alltoall(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Alltoallv ================== */
_EXTERN_C_ int PMPI_Alltoallv(MPI_CONST void *sendbuf, MPI_CONST int sendcounts[], MPI_CONST int sdispls[], MPI_Datatype sendtype, void *recvbuf, MPI_CONST int recvcounts[], MPI_CONST int rdispls[], MPI_Datatype recvtype, MPI_Comm comm);
_EXTERN_C_ int MPI_Alltoallv(MPI_CONST void *sendbuf, MPI_CONST int sendcounts[], MPI_CONST int sdispls[], MPI_Datatype sendtype, void *recvbuf, MPI_CONST int recvcounts[], MPI_CONST int rdispls[], MPI_Datatype recvtype, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Alltoallw ================== */
_EXTERN_C_ int PMPI_Alltoallw(MPI_CONST void *sendbuf, MPI_CONST int sendcounts[], MPI_CONST int sdispls[], MPI_CONST MPI_Datatype sendtypes[], void *recvbuf, MPI_CONST int recvcounts[], MPI_CONST int rdispls[], MPI_CONST MPI_Datatype recvtypes[], MPI_Comm comm);
_EXTERN_C_ int MPI_Alltoallw(MPI_CONST void *sendbuf, MPI_CONST int sendcounts[], MPI_CONST int sdispls[], MPI_CONST MPI_Datatype sendtypes[], void *recvbuf, MPI_CONST int recvcounts[], MPI_CONST int rdispls[], MPI_CONST MPI_Datatype recvtypes[], MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Barrier ================== */
_EXTERN_C_ int PMPI_Barrier(MPI_Comm comm);
_EXTERN_C_ int MPI_Barrier(MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Barrier(comm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Bcast ================== */
_EXTERN_C_ int PMPI_Bcast(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm);
_EXTERN_C_ int MPI_Bcast(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Bcast(buffer, count, datatype, root, comm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Bsend ================== */
_EXTERN_C_ int PMPI_Bsend(MPI_CONST void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm);
_EXTERN_C_ int MPI_Bsend(MPI_CONST void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Bsend(buf, count, datatype, dest, tag, comm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Bsend_init ================== */
_EXTERN_C_ int PMPI_Bsend_init(MPI_CONST void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Bsend_init(MPI_CONST void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Bsend_init(buf, count, datatype, dest, tag, comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Cart_coords ================== */
_EXTERN_C_ int PMPI_Cart_coords(MPI_Comm comm, int rank, int maxdims, int coords[]);
_EXTERN_C_ int MPI_Cart_coords(MPI_Comm comm, int rank, int maxdims, int coords[]) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Cart_coords(comm, rank, maxdims, coords);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Cart_create ================== */
_EXTERN_C_ int PMPI_Cart_create(MPI_Comm old_comm, int ndims, MPI_CONST int dims[], MPI_CONST int periods[], int reorder, MPI_Comm *comm_cart);
_EXTERN_C_ int MPI_Cart_create(MPI_Comm old_comm, int ndims, MPI_CONST int dims[], MPI_CONST int periods[], int reorder, MPI_Comm *comm_cart) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (old_comm == MPI_COMM_WORLD))
	old_comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Cart_create(old_comm, ndims, dims, periods, reorder, comm_cart);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Cart_get ================== */
_EXTERN_C_ int PMPI_Cart_get(MPI_Comm comm, int maxdims, int dims[], int periods[], int coords[]);
_EXTERN_C_ int MPI_Cart_get(MPI_Comm comm, int maxdims, int dims[], int periods[], int coords[]) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Cart_get(comm, maxdims, dims, periods, coords);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Cart_map ================== */
_EXTERN_C_ int PMPI_Cart_map(MPI_Comm comm, int ndims, MPI_CONST int dims[], MPI_CONST int periods[], int *newrank);
_EXTERN_C_ int MPI_Cart_map(MPI_Comm comm, int ndims, MPI_CONST int dims[], MPI_CONST int periods[], int *newrank) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Cart_map(comm, ndims, dims, periods, newrank);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Cart_rank ================== */
_EXTERN_C_ int PMPI_Cart_rank(MPI_Comm comm, MPI_CONST int coords[], int *rank);
_EXTERN_C_ int MPI_Cart_rank(MPI_Comm comm, MPI_CONST int coords[], int *rank) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Cart_rank(comm, coords, rank);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Cart_shift ================== */
_EXTERN_C_ int PMPI_Cart_shift(MPI_Comm comm, int direction, int disp, int *rank_source, int *rank_dest);
_EXTERN_C_ int MPI_Cart_shift(MPI_Comm comm, int direction, int disp, int *rank_source, int *rank_dest) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Cart_shift(comm, direction, disp, rank_source, rank_dest);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Cart_sub ================== */
_EXTERN_C_ int PMPI_Cart_sub(MPI_Comm comm, MPI_CONST int remain_dims[], MPI_Comm *new_comm);
_EXTERN_C_ int MPI_Cart_sub(MPI_Comm comm, MPI_CONST int remain_dims[], MPI_Comm *new_comm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Cart_sub(comm, remain_dims, new_comm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Cartdim_get ================== */
_EXTERN_C_ int PMPI_Cartdim_get(MPI_Comm comm, int *ndims);
_EXTERN_C_ int MPI_Cartdim_get(MPI_Comm comm, int *ndims) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Cartdim_get(comm, ndims);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Comm_accept ================== */
_EXTERN_C_ int PMPI_Comm_accept(MPI_CONST char *port_name, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *newcomm);
_EXTERN_C_ int MPI_Comm_accept(MPI_CONST char *port_name, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *newcomm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Comm_accept(port_name, info, root, comm, newcomm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Comm_call_errhandler ================== */
_EXTERN_C_ int PMPI_Comm_call_errhandler(MPI_Comm comm, int errorcode);
_EXTERN_C_ int MPI_Comm_call_errhandler(MPI_Comm comm, int errorcode) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Comm_call_errhandler(comm, errorcode);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Comm_compare ================== */
_EXTERN_C_ int PMPI_Comm_compare(MPI_Comm comm1, MPI_Comm comm2, int *result);
_EXTERN_C_ int MPI_Comm_compare(MPI_Comm comm1, MPI_Comm comm2, int *result) { 
    int _wrap_py_return_val = 0;
   if(plevel){
	  if(comm1 == MPI_COMM_WORLD)
		comm1 = MY_COMM_WORLD;
	  if(comm2 == MPI_COMM_WORLD)
		comm2 = MY_COMM_WORLD;
	}
  _wrap_py_return_val = PMPI_Comm_compare(comm1, comm2, result);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Comm_connect ================== */
_EXTERN_C_ int PMPI_Comm_connect(MPI_CONST char *port_name, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *newcomm);
_EXTERN_C_ int MPI_Comm_connect(MPI_CONST char *port_name, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *newcomm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Comm_connect(port_name, info, root, comm, newcomm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Comm_create ================== */
_EXTERN_C_ int PMPI_Comm_create(MPI_Comm comm, MPI_Group group, MPI_Comm *newcomm);
_EXTERN_C_ int MPI_Comm_create(MPI_Comm comm, MPI_Group group, MPI_Comm *newcomm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Comm_create(comm, group, newcomm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Comm_delete_attr ================== */
_EXTERN_C_ int PMPI_Comm_delete_attr(MPI_Comm comm, int comm_keyval);
_EXTERN_C_ int MPI_Comm_delete_attr(MPI_Comm comm, int comm_keyval) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Comm_delete_attr(comm, comm_keyval);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Comm_disconnect ================== */
_EXTERN_C_ int PMPI_Comm_disconnect(MPI_Comm *comm);
_EXTERN_C_ int MPI_Comm_disconnect(MPI_Comm *comm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (*comm == MPI_COMM_WORLD))
	*comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Comm_disconnect(comm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Comm_dup ================== */
_EXTERN_C_ int PMPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm);
_EXTERN_C_ int MPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Comm_dup(comm, newcomm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Comm_get_attr ================== */
_EXTERN_C_ int PMPI_Comm_get_attr(MPI_Comm comm, int comm_keyval, void *attribute_val, int *flag);
_EXTERN_C_ int MPI_Comm_get_attr(MPI_Comm comm, int comm_keyval, void *attribute_val, int *flag) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Comm_get_attr(comm, comm_keyval, attribute_val, flag);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Comm_get_errhandler ================== */
_EXTERN_C_ int PMPI_Comm_get_errhandler(MPI_Comm comm, MPI_Errhandler *erhandler);
_EXTERN_C_ int MPI_Comm_get_errhandler(MPI_Comm comm, MPI_Errhandler *erhandler) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Comm_get_errhandler(comm, erhandler);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Comm_get_name ================== */
_EXTERN_C_ int PMPI_Comm_get_name(MPI_Comm comm, char *comm_name, int *resultlen);
_EXTERN_C_ int MPI_Comm_get_name(MPI_Comm comm, char *comm_name, int *resultlen) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Comm_get_name(comm, comm_name, resultlen);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Comm_group ================== */
_EXTERN_C_ int PMPI_Comm_group(MPI_Comm comm, MPI_Group *group);
_EXTERN_C_ int MPI_Comm_group(MPI_Comm comm, MPI_Group *group) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Comm_group(comm, group);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Comm_join ================== */
_EXTERN_C_ int PMPI_Comm_join(int fd, MPI_Comm *intercomm);
_EXTERN_C_ int MPI_Comm_join(int fd, MPI_Comm *intercomm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (*intercomm == MPI_COMM_WORLD))
	*intercomm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Comm_join(fd, intercomm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Comm_remote_group ================== */
_EXTERN_C_ int PMPI_Comm_remote_group(MPI_Comm comm, MPI_Group *group);
_EXTERN_C_ int MPI_Comm_remote_group(MPI_Comm comm, MPI_Group *group) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Comm_remote_group(comm, group);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Comm_remote_size ================== */
_EXTERN_C_ int PMPI_Comm_remote_size(MPI_Comm comm, int *size);
_EXTERN_C_ int MPI_Comm_remote_size(MPI_Comm comm, int *size) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Comm_remote_size(comm, size);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Comm_set_attr ================== */
_EXTERN_C_ int PMPI_Comm_set_attr(MPI_Comm comm, int comm_keyval, void *attribute_val);
_EXTERN_C_ int MPI_Comm_set_attr(MPI_Comm comm, int comm_keyval, void *attribute_val) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Comm_set_attr(comm, comm_keyval, attribute_val);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Comm_set_errhandler ================== */
_EXTERN_C_ int PMPI_Comm_set_errhandler(MPI_Comm comm, MPI_Errhandler errhandler);
_EXTERN_C_ int MPI_Comm_set_errhandler(MPI_Comm comm, MPI_Errhandler errhandler) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Comm_set_errhandler(comm, errhandler);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Comm_set_name ================== */
_EXTERN_C_ int PMPI_Comm_set_name(MPI_Comm comm, MPI_CONST char *comm_name);
_EXTERN_C_ int MPI_Comm_set_name(MPI_Comm comm, MPI_CONST char *comm_name) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Comm_set_name(comm, comm_name);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Comm_split ================== */
_EXTERN_C_ int PMPI_Comm_split(MPI_Comm comm, int color, int key, MPI_Comm *newcomm);
_EXTERN_C_ int MPI_Comm_split(MPI_Comm comm, int color, int key, MPI_Comm *newcomm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Comm_split(comm, color, key, newcomm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Comm_test_inter ================== */
_EXTERN_C_ int PMPI_Comm_test_inter(MPI_Comm comm, int *flag);
_EXTERN_C_ int MPI_Comm_test_inter(MPI_Comm comm, int *flag) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Comm_test_inter(comm, flag);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Dist_graph_create ================== */
_EXTERN_C_ int PMPI_Dist_graph_create(MPI_Comm comm_old, int n, MPI_CONST int nodes[], MPI_CONST int degrees[], MPI_CONST int targets[], MPI_CONST int weights[], MPI_Info info, int reorder, MPI_Comm *newcomm);
_EXTERN_C_ int MPI_Dist_graph_create(MPI_Comm comm_old, int n, MPI_CONST int nodes[], MPI_CONST int degrees[], MPI_CONST int targets[], MPI_CONST int weights[], MPI_Info info, int reorder, MPI_Comm *newcomm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm_old == MPI_COMM_WORLD))
	comm_old = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Dist_graph_create(comm_old, n, nodes, degrees, targets, weights, info, reorder, newcomm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Dist_graph_create_adjacent ================== */
_EXTERN_C_ int PMPI_Dist_graph_create_adjacent(MPI_Comm comm_old, int indegree, MPI_CONST int sources[], MPI_CONST int sourceweights[], int outdegree, MPI_CONST int destinations[], MPI_CONST int destweights[], MPI_Info info, int reorder, MPI_Comm *comm_dist_graph);
_EXTERN_C_ int MPI_Dist_graph_create_adjacent(MPI_Comm comm_old, int indegree, MPI_CONST int sources[], MPI_CONST int sourceweights[], int outdegree, MPI_CONST int destinations[], MPI_CONST int destweights[], MPI_Info info, int reorder, MPI_Comm *comm_dist_graph) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm_old == MPI_COMM_WORLD))
	comm_old = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Dist_graph_create_adjacent(comm_old, indegree, sources, sourceweights, outdegree, destinations, destweights, info, reorder, comm_dist_graph);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Dist_graph_neighbors ================== */
_EXTERN_C_ int PMPI_Dist_graph_neighbors(MPI_Comm comm, int maxindegree, int sources[], int sourceweights[], int maxoutdegree, int destinations[], int destweights[]);
_EXTERN_C_ int MPI_Dist_graph_neighbors(MPI_Comm comm, int maxindegree, int sources[], int sourceweights[], int maxoutdegree, int destinations[], int destweights[]) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Dist_graph_neighbors(comm, maxindegree, sources, sourceweights, maxoutdegree, destinations, destweights);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Dist_graph_neighbors_count ================== */
_EXTERN_C_ int PMPI_Dist_graph_neighbors_count(MPI_Comm comm, int *inneighbors, int *outneighbors, int *weighted);
_EXTERN_C_ int MPI_Dist_graph_neighbors_count(MPI_Comm comm, int *inneighbors, int *outneighbors, int *weighted) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Dist_graph_neighbors_count(comm, inneighbors, outneighbors, weighted);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Exscan ================== */
_EXTERN_C_ int PMPI_Exscan(MPI_CONST void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);
_EXTERN_C_ int MPI_Exscan(MPI_CONST void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Exscan(sendbuf, recvbuf, count, datatype, op, comm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_File_open ================== */
_EXTERN_C_ int PMPI_File_open(MPI_Comm comm, MPI_CONST char *filename, int amode, MPI_Info info, MPI_File *fh);
_EXTERN_C_ int MPI_File_open(MPI_Comm comm, MPI_CONST char *filename, int amode, MPI_Info info, MPI_File *fh) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_File_open(comm, filename, amode, info, fh);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Gather ================== */
_EXTERN_C_ int PMPI_Gather(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm);
_EXTERN_C_ int MPI_Gather(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Gather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Gatherv ================== */
_EXTERN_C_ int PMPI_Gatherv(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_CONST int recvcounts[], MPI_CONST int displs[], MPI_Datatype recvtype, int root, MPI_Comm comm);
_EXTERN_C_ int MPI_Gatherv(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_CONST int recvcounts[], MPI_CONST int displs[], MPI_Datatype recvtype, int root, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Gatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Graph_create ================== */
_EXTERN_C_ int PMPI_Graph_create(MPI_Comm comm_old, int nnodes, MPI_CONST int index[], MPI_CONST int edges[], int reorder, MPI_Comm *comm_graph);
_EXTERN_C_ int MPI_Graph_create(MPI_Comm comm_old, int nnodes, MPI_CONST int index[], MPI_CONST int edges[], int reorder, MPI_Comm *comm_graph) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm_old == MPI_COMM_WORLD))
	comm_old = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Graph_create(comm_old, nnodes, index, edges, reorder, comm_graph);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Graph_get ================== */
_EXTERN_C_ int PMPI_Graph_get(MPI_Comm comm, int maxindex, int maxedges, int index[], int edges[]);
_EXTERN_C_ int MPI_Graph_get(MPI_Comm comm, int maxindex, int maxedges, int index[], int edges[]) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Graph_get(comm, maxindex, maxedges, index, edges);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Graph_map ================== */
_EXTERN_C_ int PMPI_Graph_map(MPI_Comm comm, int nnodes, MPI_CONST int index[], MPI_CONST int edges[], int *newrank);
_EXTERN_C_ int MPI_Graph_map(MPI_Comm comm, int nnodes, MPI_CONST int index[], MPI_CONST int edges[], int *newrank) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Graph_map(comm, nnodes, index, edges, newrank);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Graph_neighbors ================== */
_EXTERN_C_ int PMPI_Graph_neighbors(MPI_Comm comm, int rank, int maxneighbors, int neighbors[]);
_EXTERN_C_ int MPI_Graph_neighbors(MPI_Comm comm, int rank, int maxneighbors, int neighbors[]) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Graph_neighbors(comm, rank, maxneighbors, neighbors);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Graph_neighbors_count ================== */
_EXTERN_C_ int PMPI_Graph_neighbors_count(MPI_Comm comm, int rank, int *nneighbors);
_EXTERN_C_ int MPI_Graph_neighbors_count(MPI_Comm comm, int rank, int *nneighbors) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Graph_neighbors_count(comm, rank, nneighbors);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Graphdims_get ================== */
_EXTERN_C_ int PMPI_Graphdims_get(MPI_Comm comm, int *nnodes, int *nedges);
_EXTERN_C_ int MPI_Graphdims_get(MPI_Comm comm, int *nnodes, int *nedges) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Graphdims_get(comm, nnodes, nedges);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Iallgather ================== */
_EXTERN_C_ int PMPI_Iallgather(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Iallgather(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Iallgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Iallgatherv ================== */
_EXTERN_C_ int PMPI_Iallgatherv(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_CONST int recvcounts[], MPI_CONST int displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Iallgatherv(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_CONST int recvcounts[], MPI_CONST int displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Iallgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Iallreduce ================== */
_EXTERN_C_ int PMPI_Iallreduce(MPI_CONST void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Iallreduce(MPI_CONST void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Iallreduce(sendbuf, recvbuf, count, datatype, op, comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Ialltoall ================== */
_EXTERN_C_ int PMPI_Ialltoall(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Ialltoall(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Ialltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Ialltoallv ================== */
_EXTERN_C_ int PMPI_Ialltoallv(MPI_CONST void *sendbuf, MPI_CONST int sendcounts[], MPI_CONST int sdispls[], MPI_Datatype sendtype, void *recvbuf, MPI_CONST int recvcounts[], MPI_CONST int rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Ialltoallv(MPI_CONST void *sendbuf, MPI_CONST int sendcounts[], MPI_CONST int sdispls[], MPI_Datatype sendtype, void *recvbuf, MPI_CONST int recvcounts[], MPI_CONST int rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Ialltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Ialltoallw ================== */
_EXTERN_C_ int PMPI_Ialltoallw(MPI_CONST void *sendbuf, MPI_CONST int sendcounts[], MPI_CONST int sdispls[], MPI_CONST MPI_Datatype sendtypes[], void *recvbuf, MPI_CONST int recvcounts[], MPI_CONST int rdispls[], MPI_CONST MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Ialltoallw(MPI_CONST void *sendbuf, MPI_CONST int sendcounts[], MPI_CONST int sdispls[], MPI_CONST MPI_Datatype sendtypes[], void *recvbuf, MPI_CONST int recvcounts[], MPI_CONST int rdispls[], MPI_CONST MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Ialltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Ibarrier ================== */
_EXTERN_C_ int PMPI_Ibarrier(MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Ibarrier(MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Ibarrier(comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Ibcast ================== */
_EXTERN_C_ int PMPI_Ibcast(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Ibcast(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Ibcast(buffer, count, datatype, root, comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Ibsend ================== */
_EXTERN_C_ int PMPI_Ibsend(MPI_CONST void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Ibsend(MPI_CONST void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Ibsend(buf, count, datatype, dest, tag, comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Iexscan ================== */
_EXTERN_C_ int PMPI_Iexscan(MPI_CONST void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Iexscan(MPI_CONST void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Iexscan(sendbuf, recvbuf, count, datatype, op, comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Igather ================== */
_EXTERN_C_ int PMPI_Igather(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Igather(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Igather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Igatherv ================== */
_EXTERN_C_ int PMPI_Igatherv(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_CONST int recvcounts[], MPI_CONST int displs[], MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Igatherv(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_CONST int recvcounts[], MPI_CONST int displs[], MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Igatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Improbe ================== */
_EXTERN_C_ int PMPI_Improbe(int source, int tag, MPI_Comm comm, int *flag, MPI_Message *message, MPI_Status *status);
_EXTERN_C_ int MPI_Improbe(int source, int tag, MPI_Comm comm, int *flag, MPI_Message *message, MPI_Status *status) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Improbe(source, tag, comm, flag, message, status);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Intercomm_create ================== */
_EXTERN_C_ int PMPI_Intercomm_create(MPI_Comm local_comm, int local_leader, MPI_Comm bridge_comm, int remote_leader, int tag, MPI_Comm *newintercomm);
_EXTERN_C_ int MPI_Intercomm_create(MPI_Comm local_comm, int local_leader, MPI_Comm bridge_comm, int remote_leader, int tag, MPI_Comm *newintercomm) { 
    int _wrap_py_return_val = 0;
   if(plevel){
	  if(local_comm == MPI_COMM_WORLD)
		local_comm = MY_COMM_WORLD;
	  if(bridge_comm == MPI_COMM_WORLD)
		bridge_comm = MY_COMM_WORLD;
	}
  _wrap_py_return_val = PMPI_Intercomm_create(local_comm, local_leader, bridge_comm, remote_leader, tag, newintercomm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Intercomm_merge ================== */
_EXTERN_C_ int PMPI_Intercomm_merge(MPI_Comm intercomm, int high, MPI_Comm *newintercomm);
_EXTERN_C_ int MPI_Intercomm_merge(MPI_Comm intercomm, int high, MPI_Comm *newintercomm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (intercomm == MPI_COMM_WORLD))
	intercomm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Intercomm_merge(intercomm, high, newintercomm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Iprobe ================== */
_EXTERN_C_ int PMPI_Iprobe(int source, int tag, MPI_Comm comm, int *flag, MPI_Status *status);
_EXTERN_C_ int MPI_Iprobe(int source, int tag, MPI_Comm comm, int *flag, MPI_Status *status) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Iprobe(source, tag, comm, flag, status);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Irecv ================== */
_EXTERN_C_ int PMPI_Irecv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Irecv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Irecv(buf, count, datatype, source, tag, comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Ireduce ================== */
_EXTERN_C_ int PMPI_Ireduce(MPI_CONST void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Ireduce(MPI_CONST void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Ireduce(sendbuf, recvbuf, count, datatype, op, root, comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Ireduce_scatter ================== */
_EXTERN_C_ int PMPI_Ireduce_scatter(MPI_CONST void *sendbuf, void *recvbuf, MPI_CONST int recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Ireduce_scatter(MPI_CONST void *sendbuf, void *recvbuf, MPI_CONST int recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Ireduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Ireduce_scatter_block ================== */
_EXTERN_C_ int PMPI_Ireduce_scatter_block(MPI_CONST void *sendbuf, void *recvbuf, int recvcount, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Ireduce_scatter_block(MPI_CONST void *sendbuf, void *recvbuf, int recvcount, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Ireduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op, comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Irsend ================== */
_EXTERN_C_ int PMPI_Irsend(MPI_CONST void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Irsend(MPI_CONST void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Irsend(buf, count, datatype, dest, tag, comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Iscan ================== */
_EXTERN_C_ int PMPI_Iscan(MPI_CONST void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Iscan(MPI_CONST void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Iscan(sendbuf, recvbuf, count, datatype, op, comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Iscatter ================== */
_EXTERN_C_ int PMPI_Iscatter(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Iscatter(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Iscatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Iscatterv ================== */
_EXTERN_C_ int PMPI_Iscatterv(MPI_CONST void *sendbuf, MPI_CONST int sendcounts[], MPI_CONST int displs[], MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Iscatterv(MPI_CONST void *sendbuf, MPI_CONST int sendcounts[], MPI_CONST int displs[], MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Iscatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Isend ================== */
_EXTERN_C_ int PMPI_Isend(MPI_CONST void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Isend(MPI_CONST void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Isend(buf, count, datatype, dest, tag, comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Issend ================== */
_EXTERN_C_ int PMPI_Issend(MPI_CONST void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Issend(MPI_CONST void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Issend(buf, count, datatype, dest, tag, comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Mprobe ================== */
_EXTERN_C_ int PMPI_Mprobe(int source, int tag, MPI_Comm comm, MPI_Message *message, MPI_Status *status);
_EXTERN_C_ int MPI_Mprobe(int source, int tag, MPI_Comm comm, MPI_Message *message, MPI_Status *status) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Mprobe(source, tag, comm, message, status);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Pack ================== */
_EXTERN_C_ int PMPI_Pack(MPI_CONST void *inbuf, int incount, MPI_Datatype datatype, void *outbuf, int outsize, int *position, MPI_Comm comm);
_EXTERN_C_ int MPI_Pack(MPI_CONST void *inbuf, int incount, MPI_Datatype datatype, void *outbuf, int outsize, int *position, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Pack(inbuf, incount, datatype, outbuf, outsize, position, comm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Pack_size ================== */
_EXTERN_C_ int PMPI_Pack_size(int incount, MPI_Datatype datatype, MPI_Comm comm, int *size);
_EXTERN_C_ int MPI_Pack_size(int incount, MPI_Datatype datatype, MPI_Comm comm, int *size) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Pack_size(incount, datatype, comm, size);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Probe ================== */
_EXTERN_C_ int PMPI_Probe(int source, int tag, MPI_Comm comm, MPI_Status *status);
_EXTERN_C_ int MPI_Probe(int source, int tag, MPI_Comm comm, MPI_Status *status) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Probe(source, tag, comm, status);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Recv ================== */
_EXTERN_C_ int PMPI_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status);
_EXTERN_C_ int MPI_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Recv(buf, count, datatype, source, tag, comm, status);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Recv_init ================== */
_EXTERN_C_ int PMPI_Recv_init(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Recv_init(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Recv_init(buf, count, datatype, source, tag, comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Reduce ================== */
_EXTERN_C_ int PMPI_Reduce(MPI_CONST void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm);
_EXTERN_C_ int MPI_Reduce(MPI_CONST void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Reduce(sendbuf, recvbuf, count, datatype, op, root, comm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Reduce_scatter ================== */
_EXTERN_C_ int PMPI_Reduce_scatter(MPI_CONST void *sendbuf, void *recvbuf, MPI_CONST int recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);
_EXTERN_C_ int MPI_Reduce_scatter(MPI_CONST void *sendbuf, void *recvbuf, MPI_CONST int recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Reduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Reduce_scatter_block ================== */
_EXTERN_C_ int PMPI_Reduce_scatter_block(MPI_CONST void *sendbuf, void *recvbuf, int recvcount, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);
_EXTERN_C_ int MPI_Reduce_scatter_block(MPI_CONST void *sendbuf, void *recvbuf, int recvcount, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Reduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op, comm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Rsend ================== */
_EXTERN_C_ int PMPI_Rsend(MPI_CONST void *ibuf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm);
_EXTERN_C_ int MPI_Rsend(MPI_CONST void *ibuf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Rsend(ibuf, count, datatype, dest, tag, comm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Rsend_init ================== */
_EXTERN_C_ int PMPI_Rsend_init(MPI_CONST void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Rsend_init(MPI_CONST void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Rsend_init(buf, count, datatype, dest, tag, comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Scan ================== */
_EXTERN_C_ int PMPI_Scan(MPI_CONST void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);
_EXTERN_C_ int MPI_Scan(MPI_CONST void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Scan(sendbuf, recvbuf, count, datatype, op, comm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Scatter ================== */
_EXTERN_C_ int PMPI_Scatter(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm);
_EXTERN_C_ int MPI_Scatter(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Scatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Scatterv ================== */
_EXTERN_C_ int PMPI_Scatterv(MPI_CONST void *sendbuf, MPI_CONST int sendcounts[], MPI_CONST int displs[], MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm);
_EXTERN_C_ int MPI_Scatterv(MPI_CONST void *sendbuf, MPI_CONST int sendcounts[], MPI_CONST int displs[], MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Scatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Send ================== */
_EXTERN_C_ int PMPI_Send(MPI_CONST void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm);
_EXTERN_C_ int MPI_Send(MPI_CONST void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Send(buf, count, datatype, dest, tag, comm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Send_init ================== */
_EXTERN_C_ int PMPI_Send_init(MPI_CONST void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Send_init(MPI_CONST void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Send_init(buf, count, datatype, dest, tag, comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Sendrecv ================== */
_EXTERN_C_ int PMPI_Sendrecv(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, int dest, int sendtag, void *recvbuf, int recvcount, MPI_Datatype recvtype, int source, int recvtag, MPI_Comm comm, MPI_Status *status);
_EXTERN_C_ int MPI_Sendrecv(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, int dest, int sendtag, void *recvbuf, int recvcount, MPI_Datatype recvtype, int source, int recvtag, MPI_Comm comm, MPI_Status *status) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Sendrecv(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, status);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Sendrecv_replace ================== */
_EXTERN_C_ int PMPI_Sendrecv_replace(void *buf, int count, MPI_Datatype datatype, int dest, int sendtag, int source, int recvtag, MPI_Comm comm, MPI_Status *status);
_EXTERN_C_ int MPI_Sendrecv_replace(void *buf, int count, MPI_Datatype datatype, int dest, int sendtag, int source, int recvtag, MPI_Comm comm, MPI_Status *status) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Sendrecv_replace(buf, count, datatype, dest, sendtag, source, recvtag, comm, status);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Ssend ================== */
_EXTERN_C_ int PMPI_Ssend(MPI_CONST void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm);
_EXTERN_C_ int MPI_Ssend(MPI_CONST void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Ssend(buf, count, datatype, dest, tag, comm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Ssend_init ================== */
_EXTERN_C_ int PMPI_Ssend_init(MPI_CONST void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Ssend_init(MPI_CONST void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Ssend_init(buf, count, datatype, dest, tag, comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Unpack ================== */
_EXTERN_C_ int PMPI_Unpack(MPI_CONST void *inbuf, int insize, int *position, void *outbuf, int outcount, MPI_Datatype datatype, MPI_Comm comm);
_EXTERN_C_ int MPI_Unpack(MPI_CONST void *inbuf, int insize, int *position, void *outbuf, int outcount, MPI_Datatype datatype, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Unpack(inbuf, insize, position, outbuf, outcount, datatype, comm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Win_create ================== */
_EXTERN_C_ int PMPI_Win_create(void *base, MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, MPI_Win *win);
_EXTERN_C_ int MPI_Win_create(void *base, MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, MPI_Win *win) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Win_create(base, size, disp_unit, info, comm, win);
    return _wrap_py_return_val;
}


#ifndef K_COMPUTER

/* ================== C Wrappers for MPI_Win_allocate ================== */
_EXTERN_C_ int PMPI_Win_allocate(MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, void *baseptr, MPI_Win *win);
_EXTERN_C_ int MPI_Win_allocate(MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, void *baseptr, MPI_Win *win) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Win_allocate(size, disp_unit, info, comm, baseptr, win);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Win_allocate_shared ================== */
_EXTERN_C_ int PMPI_Win_allocate_shared(MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, void *baseptr, MPI_Win *win);
_EXTERN_C_ int MPI_Win_allocate_shared(MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, void *baseptr, MPI_Win *win) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Win_allocate_shared(size, disp_unit, info, comm, baseptr, win);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Win_create_dynamic ================== */
_EXTERN_C_ int PMPI_Win_create_dynamic(MPI_Info info, MPI_Comm comm, MPI_Win *win);
_EXTERN_C_ int MPI_Win_create_dynamic(MPI_Info info, MPI_Comm comm, MPI_Win *win) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Win_create_dynamic(info, comm, win);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Comm_create_group ================== */
_EXTERN_C_ int PMPI_Comm_create_group(MPI_Comm comm, MPI_Group group, int tag, MPI_Comm *newcomm);
_EXTERN_C_ int MPI_Comm_create_group(MPI_Comm comm, MPI_Group group, int tag, MPI_Comm *newcomm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Comm_create_group(comm, group, tag, newcomm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Comm_dup_with_info ================== */
_EXTERN_C_ int PMPI_Comm_dup_with_info(MPI_Comm comm, MPI_Info info, MPI_Comm *newcomm);
_EXTERN_C_ int MPI_Comm_dup_with_info(MPI_Comm comm, MPI_Info info, MPI_Comm *newcomm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Comm_dup_with_info(comm, info, newcomm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Comm_get_info ================== */
_EXTERN_C_ int PMPI_Comm_get_info(MPI_Comm comm, MPI_Info *info_used);
_EXTERN_C_ int MPI_Comm_get_info(MPI_Comm comm, MPI_Info *info_used) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Comm_get_info(comm, info_used);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Comm_idup ================== */
_EXTERN_C_ int PMPI_Comm_idup(MPI_Comm comm, MPI_Comm *newcomm, MPI_Request *request);
_EXTERN_C_ int MPI_Comm_idup(MPI_Comm comm, MPI_Comm *newcomm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Comm_idup(comm, newcomm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Comm_set_info ================== */
_EXTERN_C_ int PMPI_Comm_set_info(MPI_Comm comm, MPI_Info info);
_EXTERN_C_ int MPI_Comm_set_info(MPI_Comm comm, MPI_Info info) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Comm_set_info(comm, info);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Comm_split_type ================== */
_EXTERN_C_ int PMPI_Comm_split_type(MPI_Comm comm, int split_type, int key, MPI_Info info, MPI_Comm *newcomm);
_EXTERN_C_ int MPI_Comm_split_type(MPI_Comm comm, int split_type, int key, MPI_Info info, MPI_Comm *newcomm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Comm_split_type(comm, split_type, key, info, newcomm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Neighbor_allgather ================== */
_EXTERN_C_ int PMPI_Neighbor_allgather(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm);
_EXTERN_C_ int MPI_Neighbor_allgather(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Neighbor_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Ineighbor_allgatherv ================== */
_EXTERN_C_ int PMPI_Ineighbor_allgatherv(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_CONST int recvcounts[], MPI_CONST int displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Ineighbor_allgatherv(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_CONST int recvcounts[], MPI_CONST int displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Ineighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Ineighbor_allgather ================== */
_EXTERN_C_ int PMPI_Ineighbor_allgather(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Ineighbor_allgather(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Ineighbor_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Ineighbor_alltoall ================== */
_EXTERN_C_ int PMPI_Ineighbor_alltoall(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Ineighbor_alltoall(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Ineighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Ineighbor_alltoallv ================== */
_EXTERN_C_ int PMPI_Ineighbor_alltoallv(MPI_CONST void *sendbuf, MPI_CONST int sendcounts[], MPI_CONST int sdispls[], MPI_Datatype sendtype, void *recvbuf, MPI_CONST int recvcounts[], MPI_CONST int rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Ineighbor_alltoallv(MPI_CONST void *sendbuf, MPI_CONST int sendcounts[], MPI_CONST int sdispls[], MPI_Datatype sendtype, void *recvbuf, MPI_CONST int recvcounts[], MPI_CONST int rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Ineighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Ineighbor_alltoallw ================== */
_EXTERN_C_ int PMPI_Ineighbor_alltoallw(MPI_CONST void *sendbuf, MPI_CONST int sendcounts[], MPI_CONST MPI_Aint sdispls[], MPI_CONST MPI_Datatype sendtypes[], void *recvbuf, MPI_CONST int recvcounts[], MPI_CONST MPI_Aint rdispls[], MPI_CONST MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Ineighbor_alltoallw(MPI_CONST void *sendbuf, MPI_CONST int sendcounts[], MPI_CONST MPI_Aint sdispls[], MPI_CONST MPI_Datatype sendtypes[], void *recvbuf, MPI_CONST int recvcounts[], MPI_CONST MPI_Aint rdispls[], MPI_CONST MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Ineighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Neighbor_allgatherv ================== */
_EXTERN_C_ int PMPI_Neighbor_allgatherv(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_CONST int recvcounts[], MPI_CONST int displs[], MPI_Datatype recvtype, MPI_Comm comm);
_EXTERN_C_ int MPI_Neighbor_allgatherv(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_CONST int recvcounts[], MPI_CONST int displs[], MPI_Datatype recvtype, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Neighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Neighbor_alltoall ================== */
_EXTERN_C_ int PMPI_Neighbor_alltoall(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm);
_EXTERN_C_ int MPI_Neighbor_alltoall(MPI_CONST void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Neighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Neighbor_alltoallv ================== */
_EXTERN_C_ int PMPI_Neighbor_alltoallv(MPI_CONST void *sendbuf, MPI_CONST int sendcounts[], MPI_CONST int sdispls[], MPI_Datatype sendtype, void *recvbuf, MPI_CONST int recvcounts[], MPI_CONST int rdispls[], MPI_Datatype recvtype, MPI_Comm comm);
_EXTERN_C_ int MPI_Neighbor_alltoallv(MPI_CONST void *sendbuf, MPI_CONST int sendcounts[], MPI_CONST int sdispls[], MPI_Datatype sendtype, void *recvbuf, MPI_CONST int recvcounts[], MPI_CONST int rdispls[], MPI_Datatype recvtype, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Neighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm);
    return _wrap_py_return_val;
}

/* ================== C Wrappers for MPI_Neighbor_alltoallw ================== */
_EXTERN_C_ int PMPI_Neighbor_alltoallw(MPI_CONST void *sendbuf, MPI_CONST int sendcounts[], MPI_CONST MPI_Aint sdispls[], MPI_CONST MPI_Datatype sendtypes[], void *recvbuf, MPI_CONST int recvcounts[], MPI_CONST MPI_Aint rdispls[], MPI_CONST MPI_Datatype recvtypes[], MPI_Comm comm);
_EXTERN_C_ int MPI_Neighbor_alltoallw(MPI_CONST void *sendbuf, MPI_CONST int sendcounts[], MPI_CONST MPI_Aint sdispls[], MPI_CONST MPI_Datatype sendtypes[], void *recvbuf, MPI_CONST int recvcounts[], MPI_CONST MPI_Aint rdispls[], MPI_CONST MPI_Datatype recvtypes[], MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
 
  if(plevel && (comm == MPI_COMM_WORLD))
	comm = MY_COMM_WORLD;
  _wrap_py_return_val = PMPI_Neighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm);
    return _wrap_py_return_val;
}

#endif
