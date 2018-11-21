#include <mpi.h>


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

#if MPI_VERSION >= 3
    #define MPI_CONST const
#else
    #define MPI_CONST
#endif

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


/* =============== Fortran Wrappers for MPI_Pcontrol =============== */
static void MPI_Pcontrol_fortran_wrapper(MPI_Fint *level, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
    _wrap_py_return_val = MPI_Pcontrol(*level);
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_PCONTROL(MPI_Fint *level, MPI_Fint *ierr) { 
    MPI_Pcontrol_fortran_wrapper(level, ierr);
}

_EXTERN_C_ void mpi_pcontrol(MPI_Fint *level, MPI_Fint *ierr) { 
    MPI_Pcontrol_fortran_wrapper(level, ierr);
}

_EXTERN_C_ void mpi_pcontrol_(MPI_Fint *level, MPI_Fint *ierr) { 
    MPI_Pcontrol_fortran_wrapper(level, ierr);
}

_EXTERN_C_ void mpi_pcontrol__(MPI_Fint *level, MPI_Fint *ierr) { 
    MPI_Pcontrol_fortran_wrapper(level, ierr);
}

/* ================= End Wrappers for MPI_Pcontrol ================= */


static int fortran_init = 0;
/* =============== Fortran Wrappers for MPI_Init =============== */
static void MPI_Init_fortran_wrapper(MPI_Fint *ierr) { 
    int argc = 0;
    char ** argv = NULL;
    int _wrap_py_return_val = 0;
    _wrap_py_return_val = MPI_Init(&argc, &argv);
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_INIT(MPI_Fint *ierr) { 
    fortran_init = 1;
    MPI_Init_fortran_wrapper(ierr);
}

_EXTERN_C_ void mpi_init(MPI_Fint *ierr) { 
    fortran_init = 2;
    MPI_Init_fortran_wrapper(ierr);
}

_EXTERN_C_ void mpi_init_(MPI_Fint *ierr) { 
    fortran_init = 3;
    MPI_Init_fortran_wrapper(ierr);
}

_EXTERN_C_ void mpi_init__(MPI_Fint *ierr) { 
    fortran_init = 4;
    MPI_Init_fortran_wrapper(ierr);
}

/* ================= End Wrappers for MPI_Init ================= */


/* =============== Fortran Wrappers for MPI_Init_thread =============== */
static void MPI_Init_thread_fortran_wrapper(MPI_Fint *argc, MPI_Fint ***argv, MPI_Fint *required, MPI_Fint *provided, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
    _wrap_py_return_val = MPI_Init_thread((int*)argc, (char***)argv, *required, (int*)provided);
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_INIT_THREAD(MPI_Fint *argc, MPI_Fint ***argv, MPI_Fint *required, MPI_Fint *provided, MPI_Fint *ierr) { 
    MPI_Init_thread_fortran_wrapper(argc, argv, required, provided, ierr);
}

_EXTERN_C_ void mpi_init_thread(MPI_Fint *argc, MPI_Fint ***argv, MPI_Fint *required, MPI_Fint *provided, MPI_Fint *ierr) { 
    MPI_Init_thread_fortran_wrapper(argc, argv, required, provided, ierr);
}

_EXTERN_C_ void mpi_init_thread_(MPI_Fint *argc, MPI_Fint ***argv, MPI_Fint *required, MPI_Fint *provided, MPI_Fint *ierr) { 
    MPI_Init_thread_fortran_wrapper(argc, argv, required, provided, ierr);
}

_EXTERN_C_ void mpi_init_thread__(MPI_Fint *argc, MPI_Fint ***argv, MPI_Fint *required, MPI_Fint *provided, MPI_Fint *ierr) { 
    MPI_Init_thread_fortran_wrapper(argc, argv, required, provided, ierr);
}

/* ================= End Wrappers for MPI_Init_thread ================= */


/* =============== Fortran Wrappers for MPI_Finalize =============== */
static void MPI_Finalize_fortran_wrapper(MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
    _wrap_py_return_val = MPI_Finalize();
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FINALIZE(MPI_Fint *ierr) { 
    MPI_Finalize_fortran_wrapper(ierr);
}

_EXTERN_C_ void mpi_finalize(MPI_Fint *ierr) { 
    MPI_Finalize_fortran_wrapper(ierr);
}

_EXTERN_C_ void mpi_finalize_(MPI_Fint *ierr) { 
    MPI_Finalize_fortran_wrapper(ierr);
}

_EXTERN_C_ void mpi_finalize__(MPI_Fint *ierr) { 
    MPI_Finalize_fortran_wrapper(ierr);
}

/* ================= End Wrappers for MPI_Finalize ================= */


/* =============== Fortran Wrappers for MPI_Comm_rank =============== */
static void MPI_Comm_rank_fortran_wrapper(MPI_Fint *comm, MPI_Fint *rank, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_rank((MPI_Comm)(*comm), (int*)rank);
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Comm_rank(MPI_Comm_f2c(*comm), (int*)rank);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_RANK(MPI_Fint *comm, MPI_Fint *rank, MPI_Fint *ierr) { 
    MPI_Comm_rank_fortran_wrapper(comm, rank, ierr);
}

_EXTERN_C_ void mpi_comm_rank(MPI_Fint *comm, MPI_Fint *rank, MPI_Fint *ierr) { 
    MPI_Comm_rank_fortran_wrapper(comm, rank, ierr);
}

_EXTERN_C_ void mpi_comm_rank_(MPI_Fint *comm, MPI_Fint *rank, MPI_Fint *ierr) { 
    MPI_Comm_rank_fortran_wrapper(comm, rank, ierr);
}

_EXTERN_C_ void mpi_comm_rank__(MPI_Fint *comm, MPI_Fint *rank, MPI_Fint *ierr) { 
    MPI_Comm_rank_fortran_wrapper(comm, rank, ierr);
}

/* ================= End Wrappers for MPI_Comm_rank ================= */


/* =============== Fortran Wrappers for MPI_Comm_size =============== */
static void MPI_Comm_size_fortran_wrapper(MPI_Fint *comm, MPI_Fint *size, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_size((MPI_Comm)(*comm), (int*)size);
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Comm_size(MPI_Comm_f2c(*comm), (int*)size);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_SIZE(MPI_Fint *comm, MPI_Fint *size, MPI_Fint *ierr) { 
    MPI_Comm_size_fortran_wrapper(comm, size, ierr);
}

_EXTERN_C_ void mpi_comm_size(MPI_Fint *comm, MPI_Fint *size, MPI_Fint *ierr) { 
    MPI_Comm_size_fortran_wrapper(comm, size, ierr);
}

_EXTERN_C_ void mpi_comm_size_(MPI_Fint *comm, MPI_Fint *size, MPI_Fint *ierr) { 
    MPI_Comm_size_fortran_wrapper(comm, size, ierr);
}

_EXTERN_C_ void mpi_comm_size__(MPI_Fint *comm, MPI_Fint *size, MPI_Fint *ierr) { 
    MPI_Comm_size_fortran_wrapper(comm, size, ierr);
}

/* ================= End Wrappers for MPI_Comm_size ================= */


/* =============== Fortran Wrappers for MPI_Abort =============== */
static void MPI_Abort_fortran_wrapper(MPI_Fint *comm, MPI_Fint *errorcode, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Abort((MPI_Comm)(*comm), *errorcode);
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Abort(MPI_Comm_f2c(*comm), *errorcode);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_ABORT(MPI_Fint *comm, MPI_Fint *errorcode, MPI_Fint *ierr) { 
    MPI_Abort_fortran_wrapper(comm, errorcode, ierr);
}

_EXTERN_C_ void mpi_abort(MPI_Fint *comm, MPI_Fint *errorcode, MPI_Fint *ierr) { 
    MPI_Abort_fortran_wrapper(comm, errorcode, ierr);
}

_EXTERN_C_ void mpi_abort_(MPI_Fint *comm, MPI_Fint *errorcode, MPI_Fint *ierr) { 
    MPI_Abort_fortran_wrapper(comm, errorcode, ierr);
}

_EXTERN_C_ void mpi_abort__(MPI_Fint *comm, MPI_Fint *errorcode, MPI_Fint *ierr) { 
    MPI_Abort_fortran_wrapper(comm, errorcode, ierr);
}

/* ================= End Wrappers for MPI_Abort ================= */


/* =============== Fortran Wrappers for MPI_Allgather =============== */
static void MPI_Allgather_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Allgather((MPI_CONST void*)sendbuf, *sendcount, (MPI_Datatype)(*sendtype), (void*)recvbuf, *recvcount, (MPI_Datatype)(*recvtype), (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Allgather((MPI_CONST void*)sendbuf, *sendcount, MPI_Type_f2c(*sendtype), (void*)recvbuf, *recvcount, MPI_Type_f2c(*recvtype), MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_ALLGATHER(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Allgather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_allgather(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Allgather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_allgather_(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Allgather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_allgather__(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Allgather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}

/* ================= End Wrappers for MPI_Allgather ================= */


/* =============== Fortran Wrappers for MPI_Allgatherv =============== */
static void MPI_Allgatherv_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint displs[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Allgatherv((MPI_CONST void*)sendbuf, *sendcount, (MPI_Datatype)(*sendtype), (void*)recvbuf, (MPI_CONST int*)recvcounts, (MPI_CONST int*)displs, (MPI_Datatype)(*recvtype), (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Allgatherv((MPI_CONST void*)sendbuf, *sendcount, MPI_Type_f2c(*sendtype), (void*)recvbuf, (MPI_CONST int*)recvcounts, (MPI_CONST int*)displs, MPI_Type_f2c(*recvtype), MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_ALLGATHERV(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint displs[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Allgatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_allgatherv(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint displs[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Allgatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_allgatherv_(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint displs[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Allgatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_allgatherv__(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint displs[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Allgatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierr);
}

/* ================= End Wrappers for MPI_Allgatherv ================= */


/* =============== Fortran Wrappers for MPI_Allreduce =============== */
static void MPI_Allreduce_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Allreduce((MPI_CONST void*)sendbuf, (void*)recvbuf, *count, (MPI_Datatype)(*datatype), (MPI_Op)(*op), (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Allreduce((MPI_CONST void*)sendbuf, (void*)recvbuf, *count, MPI_Type_f2c(*datatype), MPI_Op_f2c(*op), MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_ALLREDUCE(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Allreduce_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}

_EXTERN_C_ void mpi_allreduce(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Allreduce_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}

_EXTERN_C_ void mpi_allreduce_(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Allreduce_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}

_EXTERN_C_ void mpi_allreduce__(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Allreduce_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}

/* ================= End Wrappers for MPI_Allreduce ================= */


/* =============== Fortran Wrappers for MPI_Alltoall =============== */
static void MPI_Alltoall_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Alltoall((MPI_CONST void*)sendbuf, *sendcount, (MPI_Datatype)(*sendtype), (void*)recvbuf, *recvcount, (MPI_Datatype)(*recvtype), (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Alltoall((MPI_CONST void*)sendbuf, *sendcount, MPI_Type_f2c(*sendtype), (void*)recvbuf, *recvcount, MPI_Type_f2c(*recvtype), MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_ALLTOALL(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Alltoall_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_alltoall(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Alltoall_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_alltoall_(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Alltoall_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_alltoall__(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Alltoall_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}

/* ================= End Wrappers for MPI_Alltoall ================= */


/* =============== Fortran Wrappers for MPI_Alltoallv =============== */
static void MPI_Alltoallv_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Alltoallv((MPI_CONST void*)sendbuf, (MPI_CONST int*)sendcounts, (MPI_CONST int*)sdispls, (MPI_Datatype)(*sendtype), (void*)recvbuf, (MPI_CONST int*)recvcounts, (MPI_CONST int*)rdispls, (MPI_Datatype)(*recvtype), (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Alltoallv((MPI_CONST void*)sendbuf, (MPI_CONST int*)sendcounts, (MPI_CONST int*)sdispls, MPI_Type_f2c(*sendtype), (void*)recvbuf, (MPI_CONST int*)recvcounts, (MPI_CONST int*)rdispls, MPI_Type_f2c(*recvtype), MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_ALLTOALLV(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Alltoallv_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_alltoallv(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Alltoallv_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_alltoallv_(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Alltoallv_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_alltoallv__(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Alltoallv_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierr);
}

/* ================= End Wrappers for MPI_Alltoallv ================= */


/* =============== Fortran Wrappers for MPI_Alltoallw =============== */
static void MPI_Alltoallw_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint sendtypes[], MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint recvtypes[], MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Alltoallw((MPI_CONST void*)sendbuf, (MPI_CONST int*)sendcounts, (MPI_CONST int*)sdispls, (MPI_CONST MPI_Datatype*)sendtypes, (void*)recvbuf, (MPI_CONST int*)recvcounts, (MPI_CONST int*)rdispls, (MPI_CONST MPI_Datatype*)recvtypes, (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Alltoallw((MPI_CONST void*)sendbuf, (MPI_CONST int*)sendcounts, (MPI_CONST int*)sdispls, (MPI_CONST MPI_Datatype*)sendtypes, (void*)recvbuf, (MPI_CONST int*)recvcounts, (MPI_CONST int*)rdispls, (MPI_CONST MPI_Datatype*)recvtypes, MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_ALLTOALLW(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint sendtypes[], MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint recvtypes[], MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Alltoallw_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierr);
}

_EXTERN_C_ void mpi_alltoallw(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint sendtypes[], MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint recvtypes[], MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Alltoallw_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierr);
}

_EXTERN_C_ void mpi_alltoallw_(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint sendtypes[], MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint recvtypes[], MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Alltoallw_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierr);
}

_EXTERN_C_ void mpi_alltoallw__(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint sendtypes[], MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint recvtypes[], MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Alltoallw_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierr);
}

/* ================= End Wrappers for MPI_Alltoallw ================= */


/* =============== Fortran Wrappers for MPI_Barrier =============== */
static void MPI_Barrier_fortran_wrapper(MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Barrier((MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Barrier(MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_BARRIER(MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Barrier_fortran_wrapper(comm, ierr);
}

_EXTERN_C_ void mpi_barrier(MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Barrier_fortran_wrapper(comm, ierr);
}

_EXTERN_C_ void mpi_barrier_(MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Barrier_fortran_wrapper(comm, ierr);
}

_EXTERN_C_ void mpi_barrier__(MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Barrier_fortran_wrapper(comm, ierr);
}

/* ================= End Wrappers for MPI_Barrier ================= */


/* =============== Fortran Wrappers for MPI_Bcast =============== */
static void MPI_Bcast_fortran_wrapper(MPI_Fint *buffer, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Bcast((void*)buffer, *count, (MPI_Datatype)(*datatype), *root, (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Bcast((void*)buffer, *count, MPI_Type_f2c(*datatype), *root, MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_BCAST(MPI_Fint *buffer, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Bcast_fortran_wrapper(buffer, count, datatype, root, comm, ierr);
}

_EXTERN_C_ void mpi_bcast(MPI_Fint *buffer, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Bcast_fortran_wrapper(buffer, count, datatype, root, comm, ierr);
}

_EXTERN_C_ void mpi_bcast_(MPI_Fint *buffer, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Bcast_fortran_wrapper(buffer, count, datatype, root, comm, ierr);
}

_EXTERN_C_ void mpi_bcast__(MPI_Fint *buffer, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Bcast_fortran_wrapper(buffer, count, datatype, root, comm, ierr);
}

/* ================= End Wrappers for MPI_Bcast ================= */


/* =============== Fortran Wrappers for MPI_Bsend =============== */
static void MPI_Bsend_fortran_wrapper(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Bsend((MPI_CONST void*)buf, *count, (MPI_Datatype)(*datatype), *dest, *tag, (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Bsend((MPI_CONST void*)buf, *count, MPI_Type_f2c(*datatype), *dest, *tag, MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_BSEND(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Bsend_fortran_wrapper(buf, count, datatype, dest, tag, comm, ierr);
}

_EXTERN_C_ void mpi_bsend(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Bsend_fortran_wrapper(buf, count, datatype, dest, tag, comm, ierr);
}

_EXTERN_C_ void mpi_bsend_(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Bsend_fortran_wrapper(buf, count, datatype, dest, tag, comm, ierr);
}

_EXTERN_C_ void mpi_bsend__(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Bsend_fortran_wrapper(buf, count, datatype, dest, tag, comm, ierr);
}

/* ================= End Wrappers for MPI_Bsend ================= */


/* =============== Fortran Wrappers for MPI_Bsend_init =============== */
static void MPI_Bsend_init_fortran_wrapper(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Bsend_init((MPI_CONST void*)buf, *count, (MPI_Datatype)(*datatype), *dest, *tag, (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Bsend_init((MPI_CONST void*)buf, *count, MPI_Type_f2c(*datatype), *dest, *tag, MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_BSEND_INIT(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Bsend_init_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_bsend_init(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Bsend_init_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_bsend_init_(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Bsend_init_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_bsend_init__(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Bsend_init_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Bsend_init ================= */


/* =============== Fortran Wrappers for MPI_Cart_coords =============== */
static void MPI_Cart_coords_fortran_wrapper(MPI_Fint *comm, MPI_Fint *rank, MPI_Fint *maxdims, MPI_Fint coords[], MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Cart_coords((MPI_Comm)(*comm), *rank, *maxdims, (int*)coords);
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Cart_coords(MPI_Comm_f2c(*comm), *rank, *maxdims, (int*)coords);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_CART_COORDS(MPI_Fint *comm, MPI_Fint *rank, MPI_Fint *maxdims, MPI_Fint coords[], MPI_Fint *ierr) { 
    MPI_Cart_coords_fortran_wrapper(comm, rank, maxdims, coords, ierr);
}

_EXTERN_C_ void mpi_cart_coords(MPI_Fint *comm, MPI_Fint *rank, MPI_Fint *maxdims, MPI_Fint coords[], MPI_Fint *ierr) { 
    MPI_Cart_coords_fortran_wrapper(comm, rank, maxdims, coords, ierr);
}

_EXTERN_C_ void mpi_cart_coords_(MPI_Fint *comm, MPI_Fint *rank, MPI_Fint *maxdims, MPI_Fint coords[], MPI_Fint *ierr) { 
    MPI_Cart_coords_fortran_wrapper(comm, rank, maxdims, coords, ierr);
}

_EXTERN_C_ void mpi_cart_coords__(MPI_Fint *comm, MPI_Fint *rank, MPI_Fint *maxdims, MPI_Fint coords[], MPI_Fint *ierr) { 
    MPI_Cart_coords_fortran_wrapper(comm, rank, maxdims, coords, ierr);
}

/* ================= End Wrappers for MPI_Cart_coords ================= */


/* =============== Fortran Wrappers for MPI_Cart_create =============== */
static void MPI_Cart_create_fortran_wrapper(MPI_Fint *old_comm, MPI_Fint *ndims, MPI_Fint dims[], MPI_Fint periods[], MPI_Fint *reorder, MPI_Fint *comm_cart, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Cart_create((MPI_Comm)(*old_comm), *ndims, (MPI_CONST int*)dims, (MPI_CONST int*)periods, *reorder, (MPI_Comm*)comm_cart);
#else /* MPI-2 safe call */
    MPI_Comm temp_comm_cart;
    temp_comm_cart = MPI_Comm_f2c(*comm_cart);
    _wrap_py_return_val = MPI_Cart_create(MPI_Comm_f2c(*old_comm), *ndims, (MPI_CONST int*)dims, (MPI_CONST int*)periods, *reorder, &temp_comm_cart);
    *comm_cart = MPI_Comm_c2f(temp_comm_cart);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_CART_CREATE(MPI_Fint *old_comm, MPI_Fint *ndims, MPI_Fint dims[], MPI_Fint periods[], MPI_Fint *reorder, MPI_Fint *comm_cart, MPI_Fint *ierr) { 
    MPI_Cart_create_fortran_wrapper(old_comm, ndims, dims, periods, reorder, comm_cart, ierr);
}

_EXTERN_C_ void mpi_cart_create(MPI_Fint *old_comm, MPI_Fint *ndims, MPI_Fint dims[], MPI_Fint periods[], MPI_Fint *reorder, MPI_Fint *comm_cart, MPI_Fint *ierr) { 
    MPI_Cart_create_fortran_wrapper(old_comm, ndims, dims, periods, reorder, comm_cart, ierr);
}

_EXTERN_C_ void mpi_cart_create_(MPI_Fint *old_comm, MPI_Fint *ndims, MPI_Fint dims[], MPI_Fint periods[], MPI_Fint *reorder, MPI_Fint *comm_cart, MPI_Fint *ierr) { 
    MPI_Cart_create_fortran_wrapper(old_comm, ndims, dims, periods, reorder, comm_cart, ierr);
}

_EXTERN_C_ void mpi_cart_create__(MPI_Fint *old_comm, MPI_Fint *ndims, MPI_Fint dims[], MPI_Fint periods[], MPI_Fint *reorder, MPI_Fint *comm_cart, MPI_Fint *ierr) { 
    MPI_Cart_create_fortran_wrapper(old_comm, ndims, dims, periods, reorder, comm_cart, ierr);
}

/* ================= End Wrappers for MPI_Cart_create ================= */


/* =============== Fortran Wrappers for MPI_Cart_get =============== */
static void MPI_Cart_get_fortran_wrapper(MPI_Fint *comm, MPI_Fint *maxdims, MPI_Fint dims[], MPI_Fint periods[], MPI_Fint coords[], MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Cart_get((MPI_Comm)(*comm), *maxdims, (int*)dims, (int*)periods, (int*)coords);
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Cart_get(MPI_Comm_f2c(*comm), *maxdims, (int*)dims, (int*)periods, (int*)coords);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_CART_GET(MPI_Fint *comm, MPI_Fint *maxdims, MPI_Fint dims[], MPI_Fint periods[], MPI_Fint coords[], MPI_Fint *ierr) { 
    MPI_Cart_get_fortran_wrapper(comm, maxdims, dims, periods, coords, ierr);
}

_EXTERN_C_ void mpi_cart_get(MPI_Fint *comm, MPI_Fint *maxdims, MPI_Fint dims[], MPI_Fint periods[], MPI_Fint coords[], MPI_Fint *ierr) { 
    MPI_Cart_get_fortran_wrapper(comm, maxdims, dims, periods, coords, ierr);
}

_EXTERN_C_ void mpi_cart_get_(MPI_Fint *comm, MPI_Fint *maxdims, MPI_Fint dims[], MPI_Fint periods[], MPI_Fint coords[], MPI_Fint *ierr) { 
    MPI_Cart_get_fortran_wrapper(comm, maxdims, dims, periods, coords, ierr);
}

_EXTERN_C_ void mpi_cart_get__(MPI_Fint *comm, MPI_Fint *maxdims, MPI_Fint dims[], MPI_Fint periods[], MPI_Fint coords[], MPI_Fint *ierr) { 
    MPI_Cart_get_fortran_wrapper(comm, maxdims, dims, periods, coords, ierr);
}

/* ================= End Wrappers for MPI_Cart_get ================= */


/* =============== Fortran Wrappers for MPI_Cart_map =============== */
static void MPI_Cart_map_fortran_wrapper(MPI_Fint *comm, MPI_Fint *ndims, MPI_Fint dims[], MPI_Fint periods[], MPI_Fint *newrank, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Cart_map((MPI_Comm)(*comm), *ndims, (MPI_CONST int*)dims, (MPI_CONST int*)periods, (int*)newrank);
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Cart_map(MPI_Comm_f2c(*comm), *ndims, (MPI_CONST int*)dims, (MPI_CONST int*)periods, (int*)newrank);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_CART_MAP(MPI_Fint *comm, MPI_Fint *ndims, MPI_Fint dims[], MPI_Fint periods[], MPI_Fint *newrank, MPI_Fint *ierr) { 
    MPI_Cart_map_fortran_wrapper(comm, ndims, dims, periods, newrank, ierr);
}

_EXTERN_C_ void mpi_cart_map(MPI_Fint *comm, MPI_Fint *ndims, MPI_Fint dims[], MPI_Fint periods[], MPI_Fint *newrank, MPI_Fint *ierr) { 
    MPI_Cart_map_fortran_wrapper(comm, ndims, dims, periods, newrank, ierr);
}

_EXTERN_C_ void mpi_cart_map_(MPI_Fint *comm, MPI_Fint *ndims, MPI_Fint dims[], MPI_Fint periods[], MPI_Fint *newrank, MPI_Fint *ierr) { 
    MPI_Cart_map_fortran_wrapper(comm, ndims, dims, periods, newrank, ierr);
}

_EXTERN_C_ void mpi_cart_map__(MPI_Fint *comm, MPI_Fint *ndims, MPI_Fint dims[], MPI_Fint periods[], MPI_Fint *newrank, MPI_Fint *ierr) { 
    MPI_Cart_map_fortran_wrapper(comm, ndims, dims, periods, newrank, ierr);
}

/* ================= End Wrappers for MPI_Cart_map ================= */


/* =============== Fortran Wrappers for MPI_Cart_rank =============== */
static void MPI_Cart_rank_fortran_wrapper(MPI_Fint *comm, MPI_Fint coords[], MPI_Fint *rank, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Cart_rank((MPI_Comm)(*comm), (MPI_CONST int*)coords, (int*)rank);
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Cart_rank(MPI_Comm_f2c(*comm), (MPI_CONST int*)coords, (int*)rank);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_CART_RANK(MPI_Fint *comm, MPI_Fint coords[], MPI_Fint *rank, MPI_Fint *ierr) { 
    MPI_Cart_rank_fortran_wrapper(comm, coords, rank, ierr);
}

_EXTERN_C_ void mpi_cart_rank(MPI_Fint *comm, MPI_Fint coords[], MPI_Fint *rank, MPI_Fint *ierr) { 
    MPI_Cart_rank_fortran_wrapper(comm, coords, rank, ierr);
}

_EXTERN_C_ void mpi_cart_rank_(MPI_Fint *comm, MPI_Fint coords[], MPI_Fint *rank, MPI_Fint *ierr) { 
    MPI_Cart_rank_fortran_wrapper(comm, coords, rank, ierr);
}

_EXTERN_C_ void mpi_cart_rank__(MPI_Fint *comm, MPI_Fint coords[], MPI_Fint *rank, MPI_Fint *ierr) { 
    MPI_Cart_rank_fortran_wrapper(comm, coords, rank, ierr);
}

/* ================= End Wrappers for MPI_Cart_rank ================= */


/* =============== Fortran Wrappers for MPI_Cart_shift =============== */
static void MPI_Cart_shift_fortran_wrapper(MPI_Fint *comm, MPI_Fint *direction, MPI_Fint *disp, MPI_Fint *rank_source, MPI_Fint *rank_dest, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Cart_shift((MPI_Comm)(*comm), *direction, *disp, (int*)rank_source, (int*)rank_dest);
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Cart_shift(MPI_Comm_f2c(*comm), *direction, *disp, (int*)rank_source, (int*)rank_dest);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_CART_SHIFT(MPI_Fint *comm, MPI_Fint *direction, MPI_Fint *disp, MPI_Fint *rank_source, MPI_Fint *rank_dest, MPI_Fint *ierr) { 
    MPI_Cart_shift_fortran_wrapper(comm, direction, disp, rank_source, rank_dest, ierr);
}

_EXTERN_C_ void mpi_cart_shift(MPI_Fint *comm, MPI_Fint *direction, MPI_Fint *disp, MPI_Fint *rank_source, MPI_Fint *rank_dest, MPI_Fint *ierr) { 
    MPI_Cart_shift_fortran_wrapper(comm, direction, disp, rank_source, rank_dest, ierr);
}

_EXTERN_C_ void mpi_cart_shift_(MPI_Fint *comm, MPI_Fint *direction, MPI_Fint *disp, MPI_Fint *rank_source, MPI_Fint *rank_dest, MPI_Fint *ierr) { 
    MPI_Cart_shift_fortran_wrapper(comm, direction, disp, rank_source, rank_dest, ierr);
}

_EXTERN_C_ void mpi_cart_shift__(MPI_Fint *comm, MPI_Fint *direction, MPI_Fint *disp, MPI_Fint *rank_source, MPI_Fint *rank_dest, MPI_Fint *ierr) { 
    MPI_Cart_shift_fortran_wrapper(comm, direction, disp, rank_source, rank_dest, ierr);
}

/* ================= End Wrappers for MPI_Cart_shift ================= */


/* =============== Fortran Wrappers for MPI_Cart_sub =============== */
static void MPI_Cart_sub_fortran_wrapper(MPI_Fint *comm, MPI_Fint remain_dims[], MPI_Fint *new_comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Cart_sub((MPI_Comm)(*comm), (MPI_CONST int*)remain_dims, (MPI_Comm*)new_comm);
#else /* MPI-2 safe call */
    MPI_Comm temp_new_comm;
    temp_new_comm = MPI_Comm_f2c(*new_comm);
    _wrap_py_return_val = MPI_Cart_sub(MPI_Comm_f2c(*comm), (MPI_CONST int*)remain_dims, &temp_new_comm);
    *new_comm = MPI_Comm_c2f(temp_new_comm);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_CART_SUB(MPI_Fint *comm, MPI_Fint remain_dims[], MPI_Fint *new_comm, MPI_Fint *ierr) { 
    MPI_Cart_sub_fortran_wrapper(comm, remain_dims, new_comm, ierr);
}

_EXTERN_C_ void mpi_cart_sub(MPI_Fint *comm, MPI_Fint remain_dims[], MPI_Fint *new_comm, MPI_Fint *ierr) { 
    MPI_Cart_sub_fortran_wrapper(comm, remain_dims, new_comm, ierr);
}

_EXTERN_C_ void mpi_cart_sub_(MPI_Fint *comm, MPI_Fint remain_dims[], MPI_Fint *new_comm, MPI_Fint *ierr) { 
    MPI_Cart_sub_fortran_wrapper(comm, remain_dims, new_comm, ierr);
}

_EXTERN_C_ void mpi_cart_sub__(MPI_Fint *comm, MPI_Fint remain_dims[], MPI_Fint *new_comm, MPI_Fint *ierr) { 
    MPI_Cart_sub_fortran_wrapper(comm, remain_dims, new_comm, ierr);
}

/* ================= End Wrappers for MPI_Cart_sub ================= */


/* =============== Fortran Wrappers for MPI_Cartdim_get =============== */
static void MPI_Cartdim_get_fortran_wrapper(MPI_Fint *comm, MPI_Fint *ndims, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Cartdim_get((MPI_Comm)(*comm), (int*)ndims);
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Cartdim_get(MPI_Comm_f2c(*comm), (int*)ndims);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_CARTDIM_GET(MPI_Fint *comm, MPI_Fint *ndims, MPI_Fint *ierr) { 
    MPI_Cartdim_get_fortran_wrapper(comm, ndims, ierr);
}

_EXTERN_C_ void mpi_cartdim_get(MPI_Fint *comm, MPI_Fint *ndims, MPI_Fint *ierr) { 
    MPI_Cartdim_get_fortran_wrapper(comm, ndims, ierr);
}

_EXTERN_C_ void mpi_cartdim_get_(MPI_Fint *comm, MPI_Fint *ndims, MPI_Fint *ierr) { 
    MPI_Cartdim_get_fortran_wrapper(comm, ndims, ierr);
}

_EXTERN_C_ void mpi_cartdim_get__(MPI_Fint *comm, MPI_Fint *ndims, MPI_Fint *ierr) { 
    MPI_Cartdim_get_fortran_wrapper(comm, ndims, ierr);
}

/* ================= End Wrappers for MPI_Cartdim_get ================= */


/* =============== Fortran Wrappers for MPI_Comm_accept =============== */
static void MPI_Comm_accept_fortran_wrapper(MPI_Fint *port_name, MPI_Fint *info, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_accept((MPI_CONST char*)port_name, (MPI_Info)(*info), *root, (MPI_Comm)(*comm), (MPI_Comm*)newcomm);
#else /* MPI-2 safe call */
    MPI_Comm temp_newcomm;
    temp_newcomm = MPI_Comm_f2c(*newcomm);
    _wrap_py_return_val = MPI_Comm_accept((MPI_CONST char*)port_name, MPI_Info_f2c(*info), *root, MPI_Comm_f2c(*comm), &temp_newcomm);
    *newcomm = MPI_Comm_c2f(temp_newcomm);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_ACCEPT(MPI_Fint *port_name, MPI_Fint *info, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_accept_fortran_wrapper(port_name, info, root, comm, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_accept(MPI_Fint *port_name, MPI_Fint *info, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_accept_fortran_wrapper(port_name, info, root, comm, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_accept_(MPI_Fint *port_name, MPI_Fint *info, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_accept_fortran_wrapper(port_name, info, root, comm, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_accept__(MPI_Fint *port_name, MPI_Fint *info, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_accept_fortran_wrapper(port_name, info, root, comm, newcomm, ierr);
}

/* ================= End Wrappers for MPI_Comm_accept ================= */


/* =============== Fortran Wrappers for MPI_Comm_call_errhandler =============== */
static void MPI_Comm_call_errhandler_fortran_wrapper(MPI_Fint *comm, MPI_Fint *errorcode, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_call_errhandler((MPI_Comm)(*comm), *errorcode);
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Comm_call_errhandler(MPI_Comm_f2c(*comm), *errorcode);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_CALL_ERRHANDLER(MPI_Fint *comm, MPI_Fint *errorcode, MPI_Fint *ierr) { 
    MPI_Comm_call_errhandler_fortran_wrapper(comm, errorcode, ierr);
}

_EXTERN_C_ void mpi_comm_call_errhandler(MPI_Fint *comm, MPI_Fint *errorcode, MPI_Fint *ierr) { 
    MPI_Comm_call_errhandler_fortran_wrapper(comm, errorcode, ierr);
}

_EXTERN_C_ void mpi_comm_call_errhandler_(MPI_Fint *comm, MPI_Fint *errorcode, MPI_Fint *ierr) { 
    MPI_Comm_call_errhandler_fortran_wrapper(comm, errorcode, ierr);
}

_EXTERN_C_ void mpi_comm_call_errhandler__(MPI_Fint *comm, MPI_Fint *errorcode, MPI_Fint *ierr) { 
    MPI_Comm_call_errhandler_fortran_wrapper(comm, errorcode, ierr);
}

/* ================= End Wrappers for MPI_Comm_call_errhandler ================= */


/* =============== Fortran Wrappers for MPI_Comm_compare =============== */
static void MPI_Comm_compare_fortran_wrapper(MPI_Fint *comm1, MPI_Fint *comm2, MPI_Fint *result, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_compare((MPI_Comm)(*comm1), (MPI_Comm)(*comm2), (int*)result);
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Comm_compare(MPI_Comm_f2c(*comm1), MPI_Comm_f2c(*comm2), (int*)result);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_COMPARE(MPI_Fint *comm1, MPI_Fint *comm2, MPI_Fint *result, MPI_Fint *ierr) { 
    MPI_Comm_compare_fortran_wrapper(comm1, comm2, result, ierr);
}

_EXTERN_C_ void mpi_comm_compare(MPI_Fint *comm1, MPI_Fint *comm2, MPI_Fint *result, MPI_Fint *ierr) { 
    MPI_Comm_compare_fortran_wrapper(comm1, comm2, result, ierr);
}

_EXTERN_C_ void mpi_comm_compare_(MPI_Fint *comm1, MPI_Fint *comm2, MPI_Fint *result, MPI_Fint *ierr) { 
    MPI_Comm_compare_fortran_wrapper(comm1, comm2, result, ierr);
}

_EXTERN_C_ void mpi_comm_compare__(MPI_Fint *comm1, MPI_Fint *comm2, MPI_Fint *result, MPI_Fint *ierr) { 
    MPI_Comm_compare_fortran_wrapper(comm1, comm2, result, ierr);
}

/* ================= End Wrappers for MPI_Comm_compare ================= */


/* =============== Fortran Wrappers for MPI_Comm_connect =============== */
static void MPI_Comm_connect_fortran_wrapper(MPI_Fint *port_name, MPI_Fint *info, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_connect((MPI_CONST char*)port_name, (MPI_Info)(*info), *root, (MPI_Comm)(*comm), (MPI_Comm*)newcomm);
#else /* MPI-2 safe call */
    MPI_Comm temp_newcomm;
    temp_newcomm = MPI_Comm_f2c(*newcomm);
    _wrap_py_return_val = MPI_Comm_connect((MPI_CONST char*)port_name, MPI_Info_f2c(*info), *root, MPI_Comm_f2c(*comm), &temp_newcomm);
    *newcomm = MPI_Comm_c2f(temp_newcomm);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_CONNECT(MPI_Fint *port_name, MPI_Fint *info, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_connect_fortran_wrapper(port_name, info, root, comm, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_connect(MPI_Fint *port_name, MPI_Fint *info, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_connect_fortran_wrapper(port_name, info, root, comm, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_connect_(MPI_Fint *port_name, MPI_Fint *info, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_connect_fortran_wrapper(port_name, info, root, comm, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_connect__(MPI_Fint *port_name, MPI_Fint *info, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_connect_fortran_wrapper(port_name, info, root, comm, newcomm, ierr);
}

/* ================= End Wrappers for MPI_Comm_connect ================= */


/* =============== Fortran Wrappers for MPI_Comm_create =============== */
static void MPI_Comm_create_fortran_wrapper(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_create((MPI_Comm)(*comm), (MPI_Group)(*group), (MPI_Comm*)newcomm);
#else /* MPI-2 safe call */
    MPI_Comm temp_newcomm;
    temp_newcomm = MPI_Comm_f2c(*newcomm);
    _wrap_py_return_val = MPI_Comm_create(MPI_Comm_f2c(*comm), MPI_Group_f2c(*group), &temp_newcomm);
    *newcomm = MPI_Comm_c2f(temp_newcomm);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_CREATE(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_create_fortran_wrapper(comm, group, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_create(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_create_fortran_wrapper(comm, group, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_create_(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_create_fortran_wrapper(comm, group, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_create__(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_create_fortran_wrapper(comm, group, newcomm, ierr);
}

/* ================= End Wrappers for MPI_Comm_create ================= */


/* =============== Fortran Wrappers for MPI_Comm_delete_attr =============== */
static void MPI_Comm_delete_attr_fortran_wrapper(MPI_Fint *comm, MPI_Fint *comm_keyval, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_delete_attr((MPI_Comm)(*comm), *comm_keyval);
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Comm_delete_attr(MPI_Comm_f2c(*comm), *comm_keyval);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_DELETE_ATTR(MPI_Fint *comm, MPI_Fint *comm_keyval, MPI_Fint *ierr) { 
    MPI_Comm_delete_attr_fortran_wrapper(comm, comm_keyval, ierr);
}

_EXTERN_C_ void mpi_comm_delete_attr(MPI_Fint *comm, MPI_Fint *comm_keyval, MPI_Fint *ierr) { 
    MPI_Comm_delete_attr_fortran_wrapper(comm, comm_keyval, ierr);
}

_EXTERN_C_ void mpi_comm_delete_attr_(MPI_Fint *comm, MPI_Fint *comm_keyval, MPI_Fint *ierr) { 
    MPI_Comm_delete_attr_fortran_wrapper(comm, comm_keyval, ierr);
}

_EXTERN_C_ void mpi_comm_delete_attr__(MPI_Fint *comm, MPI_Fint *comm_keyval, MPI_Fint *ierr) { 
    MPI_Comm_delete_attr_fortran_wrapper(comm, comm_keyval, ierr);
}

/* ================= End Wrappers for MPI_Comm_delete_attr ================= */


/* =============== Fortran Wrappers for MPI_Comm_disconnect =============== */
static void MPI_Comm_disconnect_fortran_wrapper(MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_disconnect((MPI_Comm*)comm);
#else /* MPI-2 safe call */
    MPI_Comm temp_comm;
    temp_comm = MPI_Comm_f2c(*comm);
    _wrap_py_return_val = MPI_Comm_disconnect(&temp_comm);
    *comm = MPI_Comm_c2f(temp_comm);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_DISCONNECT(MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Comm_disconnect_fortran_wrapper(comm, ierr);
}

_EXTERN_C_ void mpi_comm_disconnect(MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Comm_disconnect_fortran_wrapper(comm, ierr);
}

_EXTERN_C_ void mpi_comm_disconnect_(MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Comm_disconnect_fortran_wrapper(comm, ierr);
}

_EXTERN_C_ void mpi_comm_disconnect__(MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Comm_disconnect_fortran_wrapper(comm, ierr);
}

/* ================= End Wrappers for MPI_Comm_disconnect ================= */


/* =============== Fortran Wrappers for MPI_Comm_dup =============== */
static void MPI_Comm_dup_fortran_wrapper(MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_dup((MPI_Comm)(*comm), (MPI_Comm*)newcomm);
#else /* MPI-2 safe call */
    MPI_Comm temp_newcomm;
    temp_newcomm = MPI_Comm_f2c(*newcomm);
    _wrap_py_return_val = MPI_Comm_dup(MPI_Comm_f2c(*comm), &temp_newcomm);
    *newcomm = MPI_Comm_c2f(temp_newcomm);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_DUP(MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_dup_fortran_wrapper(comm, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_dup(MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_dup_fortran_wrapper(comm, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_dup_(MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_dup_fortran_wrapper(comm, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_dup__(MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_dup_fortran_wrapper(comm, newcomm, ierr);
}

/* ================= End Wrappers for MPI_Comm_dup ================= */


/* =============== Fortran Wrappers for MPI_Comm_get_attr =============== */
static void MPI_Comm_get_attr_fortran_wrapper(MPI_Fint *comm, MPI_Fint *comm_keyval, MPI_Fint *attribute_val, MPI_Fint *flag, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_get_attr((MPI_Comm)(*comm), *comm_keyval, (void*)attribute_val, (int*)flag);
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Comm_get_attr(MPI_Comm_f2c(*comm), *comm_keyval, (void*)attribute_val, (int*)flag);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_GET_ATTR(MPI_Fint *comm, MPI_Fint *comm_keyval, MPI_Fint *attribute_val, MPI_Fint *flag, MPI_Fint *ierr) { 
    MPI_Comm_get_attr_fortran_wrapper(comm, comm_keyval, attribute_val, flag, ierr);
}

_EXTERN_C_ void mpi_comm_get_attr(MPI_Fint *comm, MPI_Fint *comm_keyval, MPI_Fint *attribute_val, MPI_Fint *flag, MPI_Fint *ierr) { 
    MPI_Comm_get_attr_fortran_wrapper(comm, comm_keyval, attribute_val, flag, ierr);
}

_EXTERN_C_ void mpi_comm_get_attr_(MPI_Fint *comm, MPI_Fint *comm_keyval, MPI_Fint *attribute_val, MPI_Fint *flag, MPI_Fint *ierr) { 
    MPI_Comm_get_attr_fortran_wrapper(comm, comm_keyval, attribute_val, flag, ierr);
}

_EXTERN_C_ void mpi_comm_get_attr__(MPI_Fint *comm, MPI_Fint *comm_keyval, MPI_Fint *attribute_val, MPI_Fint *flag, MPI_Fint *ierr) { 
    MPI_Comm_get_attr_fortran_wrapper(comm, comm_keyval, attribute_val, flag, ierr);
}

/* ================= End Wrappers for MPI_Comm_get_attr ================= */


/* =============== Fortran Wrappers for MPI_Comm_get_errhandler =============== */
static void MPI_Comm_get_errhandler_fortran_wrapper(MPI_Fint *comm, MPI_Fint *erhandler, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_get_errhandler((MPI_Comm)(*comm), (MPI_Errhandler*)erhandler);
#else /* MPI-2 safe call */
    MPI_Errhandler temp_erhandler;
    temp_erhandler = MPI_Errhandler_f2c(*erhandler);
    _wrap_py_return_val = MPI_Comm_get_errhandler(MPI_Comm_f2c(*comm), &temp_erhandler);
    *erhandler = MPI_Errhandler_c2f(temp_erhandler);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_GET_ERRHANDLER(MPI_Fint *comm, MPI_Fint *erhandler, MPI_Fint *ierr) { 
    MPI_Comm_get_errhandler_fortran_wrapper(comm, erhandler, ierr);
}

_EXTERN_C_ void mpi_comm_get_errhandler(MPI_Fint *comm, MPI_Fint *erhandler, MPI_Fint *ierr) { 
    MPI_Comm_get_errhandler_fortran_wrapper(comm, erhandler, ierr);
}

_EXTERN_C_ void mpi_comm_get_errhandler_(MPI_Fint *comm, MPI_Fint *erhandler, MPI_Fint *ierr) { 
    MPI_Comm_get_errhandler_fortran_wrapper(comm, erhandler, ierr);
}

_EXTERN_C_ void mpi_comm_get_errhandler__(MPI_Fint *comm, MPI_Fint *erhandler, MPI_Fint *ierr) { 
    MPI_Comm_get_errhandler_fortran_wrapper(comm, erhandler, ierr);
}

/* ================= End Wrappers for MPI_Comm_get_errhandler ================= */


/* =============== Fortran Wrappers for MPI_Comm_get_name =============== */
static void MPI_Comm_get_name_fortran_wrapper(MPI_Fint *comm, MPI_Fint *comm_name, MPI_Fint *resultlen, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_get_name((MPI_Comm)(*comm), (char*)comm_name, (int*)resultlen);
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Comm_get_name(MPI_Comm_f2c(*comm), (char*)comm_name, (int*)resultlen);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_GET_NAME(MPI_Fint *comm, MPI_Fint *comm_name, MPI_Fint *resultlen, MPI_Fint *ierr) { 
    MPI_Comm_get_name_fortran_wrapper(comm, comm_name, resultlen, ierr);
}

_EXTERN_C_ void mpi_comm_get_name(MPI_Fint *comm, MPI_Fint *comm_name, MPI_Fint *resultlen, MPI_Fint *ierr) { 
    MPI_Comm_get_name_fortran_wrapper(comm, comm_name, resultlen, ierr);
}

_EXTERN_C_ void mpi_comm_get_name_(MPI_Fint *comm, MPI_Fint *comm_name, MPI_Fint *resultlen, MPI_Fint *ierr) { 
    MPI_Comm_get_name_fortran_wrapper(comm, comm_name, resultlen, ierr);
}

_EXTERN_C_ void mpi_comm_get_name__(MPI_Fint *comm, MPI_Fint *comm_name, MPI_Fint *resultlen, MPI_Fint *ierr) { 
    MPI_Comm_get_name_fortran_wrapper(comm, comm_name, resultlen, ierr);
}

/* ================= End Wrappers for MPI_Comm_get_name ================= */


/* =============== Fortran Wrappers for MPI_Comm_group =============== */
static void MPI_Comm_group_fortran_wrapper(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_group((MPI_Comm)(*comm), (MPI_Group*)group);
#else /* MPI-2 safe call */
    MPI_Group temp_group;
    temp_group = MPI_Group_f2c(*group);
    _wrap_py_return_val = MPI_Comm_group(MPI_Comm_f2c(*comm), &temp_group);
    *group = MPI_Group_c2f(temp_group);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_GROUP(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *ierr) { 
    MPI_Comm_group_fortran_wrapper(comm, group, ierr);
}

_EXTERN_C_ void mpi_comm_group(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *ierr) { 
    MPI_Comm_group_fortran_wrapper(comm, group, ierr);
}

_EXTERN_C_ void mpi_comm_group_(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *ierr) { 
    MPI_Comm_group_fortran_wrapper(comm, group, ierr);
}

_EXTERN_C_ void mpi_comm_group__(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *ierr) { 
    MPI_Comm_group_fortran_wrapper(comm, group, ierr);
}

/* ================= End Wrappers for MPI_Comm_group ================= */


/* =============== Fortran Wrappers for MPI_Comm_join =============== */
static void MPI_Comm_join_fortran_wrapper(MPI_Fint *fd, MPI_Fint *intercomm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_join(*fd, (MPI_Comm*)intercomm);
#else /* MPI-2 safe call */
    MPI_Comm temp_intercomm;
    temp_intercomm = MPI_Comm_f2c(*intercomm);
    _wrap_py_return_val = MPI_Comm_join(*fd, &temp_intercomm);
    *intercomm = MPI_Comm_c2f(temp_intercomm);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_JOIN(MPI_Fint *fd, MPI_Fint *intercomm, MPI_Fint *ierr) { 
    MPI_Comm_join_fortran_wrapper(fd, intercomm, ierr);
}

_EXTERN_C_ void mpi_comm_join(MPI_Fint *fd, MPI_Fint *intercomm, MPI_Fint *ierr) { 
    MPI_Comm_join_fortran_wrapper(fd, intercomm, ierr);
}

_EXTERN_C_ void mpi_comm_join_(MPI_Fint *fd, MPI_Fint *intercomm, MPI_Fint *ierr) { 
    MPI_Comm_join_fortran_wrapper(fd, intercomm, ierr);
}

_EXTERN_C_ void mpi_comm_join__(MPI_Fint *fd, MPI_Fint *intercomm, MPI_Fint *ierr) { 
    MPI_Comm_join_fortran_wrapper(fd, intercomm, ierr);
}

/* ================= End Wrappers for MPI_Comm_join ================= */


/* =============== Fortran Wrappers for MPI_Comm_remote_group =============== */
static void MPI_Comm_remote_group_fortran_wrapper(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_remote_group((MPI_Comm)(*comm), (MPI_Group*)group);
#else /* MPI-2 safe call */
    MPI_Group temp_group;
    temp_group = MPI_Group_f2c(*group);
    _wrap_py_return_val = MPI_Comm_remote_group(MPI_Comm_f2c(*comm), &temp_group);
    *group = MPI_Group_c2f(temp_group);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_REMOTE_GROUP(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *ierr) { 
    MPI_Comm_remote_group_fortran_wrapper(comm, group, ierr);
}

_EXTERN_C_ void mpi_comm_remote_group(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *ierr) { 
    MPI_Comm_remote_group_fortran_wrapper(comm, group, ierr);
}

_EXTERN_C_ void mpi_comm_remote_group_(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *ierr) { 
    MPI_Comm_remote_group_fortran_wrapper(comm, group, ierr);
}

_EXTERN_C_ void mpi_comm_remote_group__(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *ierr) { 
    MPI_Comm_remote_group_fortran_wrapper(comm, group, ierr);
}

/* ================= End Wrappers for MPI_Comm_remote_group ================= */


/* =============== Fortran Wrappers for MPI_Comm_remote_size =============== */
static void MPI_Comm_remote_size_fortran_wrapper(MPI_Fint *comm, MPI_Fint *size, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_remote_size((MPI_Comm)(*comm), (int*)size);
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Comm_remote_size(MPI_Comm_f2c(*comm), (int*)size);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_REMOTE_SIZE(MPI_Fint *comm, MPI_Fint *size, MPI_Fint *ierr) { 
    MPI_Comm_remote_size_fortran_wrapper(comm, size, ierr);
}

_EXTERN_C_ void mpi_comm_remote_size(MPI_Fint *comm, MPI_Fint *size, MPI_Fint *ierr) { 
    MPI_Comm_remote_size_fortran_wrapper(comm, size, ierr);
}

_EXTERN_C_ void mpi_comm_remote_size_(MPI_Fint *comm, MPI_Fint *size, MPI_Fint *ierr) { 
    MPI_Comm_remote_size_fortran_wrapper(comm, size, ierr);
}

_EXTERN_C_ void mpi_comm_remote_size__(MPI_Fint *comm, MPI_Fint *size, MPI_Fint *ierr) { 
    MPI_Comm_remote_size_fortran_wrapper(comm, size, ierr);
}

/* ================= End Wrappers for MPI_Comm_remote_size ================= */


/* =============== Fortran Wrappers for MPI_Comm_set_attr =============== */
static void MPI_Comm_set_attr_fortran_wrapper(MPI_Fint *comm, MPI_Fint *comm_keyval, MPI_Fint *attribute_val, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_set_attr((MPI_Comm)(*comm), *comm_keyval, (void*)attribute_val);
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Comm_set_attr(MPI_Comm_f2c(*comm), *comm_keyval, (void*)attribute_val);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_SET_ATTR(MPI_Fint *comm, MPI_Fint *comm_keyval, MPI_Fint *attribute_val, MPI_Fint *ierr) { 
    MPI_Comm_set_attr_fortran_wrapper(comm, comm_keyval, attribute_val, ierr);
}

_EXTERN_C_ void mpi_comm_set_attr(MPI_Fint *comm, MPI_Fint *comm_keyval, MPI_Fint *attribute_val, MPI_Fint *ierr) { 
    MPI_Comm_set_attr_fortran_wrapper(comm, comm_keyval, attribute_val, ierr);
}

_EXTERN_C_ void mpi_comm_set_attr_(MPI_Fint *comm, MPI_Fint *comm_keyval, MPI_Fint *attribute_val, MPI_Fint *ierr) { 
    MPI_Comm_set_attr_fortran_wrapper(comm, comm_keyval, attribute_val, ierr);
}

_EXTERN_C_ void mpi_comm_set_attr__(MPI_Fint *comm, MPI_Fint *comm_keyval, MPI_Fint *attribute_val, MPI_Fint *ierr) { 
    MPI_Comm_set_attr_fortran_wrapper(comm, comm_keyval, attribute_val, ierr);
}

/* ================= End Wrappers for MPI_Comm_set_attr ================= */


/* =============== Fortran Wrappers for MPI_Comm_set_errhandler =============== */
static void MPI_Comm_set_errhandler_fortran_wrapper(MPI_Fint *comm, MPI_Fint *errhandler, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_set_errhandler((MPI_Comm)(*comm), (MPI_Errhandler)(*errhandler));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Comm_set_errhandler(MPI_Comm_f2c(*comm), MPI_Errhandler_f2c(*errhandler));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_SET_ERRHANDLER(MPI_Fint *comm, MPI_Fint *errhandler, MPI_Fint *ierr) { 
    MPI_Comm_set_errhandler_fortran_wrapper(comm, errhandler, ierr);
}

_EXTERN_C_ void mpi_comm_set_errhandler(MPI_Fint *comm, MPI_Fint *errhandler, MPI_Fint *ierr) { 
    MPI_Comm_set_errhandler_fortran_wrapper(comm, errhandler, ierr);
}

_EXTERN_C_ void mpi_comm_set_errhandler_(MPI_Fint *comm, MPI_Fint *errhandler, MPI_Fint *ierr) { 
    MPI_Comm_set_errhandler_fortran_wrapper(comm, errhandler, ierr);
}

_EXTERN_C_ void mpi_comm_set_errhandler__(MPI_Fint *comm, MPI_Fint *errhandler, MPI_Fint *ierr) { 
    MPI_Comm_set_errhandler_fortran_wrapper(comm, errhandler, ierr);
}

/* ================= End Wrappers for MPI_Comm_set_errhandler ================= */


/* =============== Fortran Wrappers for MPI_Comm_set_name =============== */
static void MPI_Comm_set_name_fortran_wrapper(MPI_Fint *comm, MPI_Fint *comm_name, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_set_name((MPI_Comm)(*comm), (MPI_CONST char*)comm_name);
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Comm_set_name(MPI_Comm_f2c(*comm), (MPI_CONST char*)comm_name);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_SET_NAME(MPI_Fint *comm, MPI_Fint *comm_name, MPI_Fint *ierr) { 
    MPI_Comm_set_name_fortran_wrapper(comm, comm_name, ierr);
}

_EXTERN_C_ void mpi_comm_set_name(MPI_Fint *comm, MPI_Fint *comm_name, MPI_Fint *ierr) { 
    MPI_Comm_set_name_fortran_wrapper(comm, comm_name, ierr);
}

_EXTERN_C_ void mpi_comm_set_name_(MPI_Fint *comm, MPI_Fint *comm_name, MPI_Fint *ierr) { 
    MPI_Comm_set_name_fortran_wrapper(comm, comm_name, ierr);
}

_EXTERN_C_ void mpi_comm_set_name__(MPI_Fint *comm, MPI_Fint *comm_name, MPI_Fint *ierr) { 
    MPI_Comm_set_name_fortran_wrapper(comm, comm_name, ierr);
}

/* ================= End Wrappers for MPI_Comm_set_name ================= */


/* =============== Fortran Wrappers for MPI_Comm_split =============== */
static void MPI_Comm_split_fortran_wrapper(MPI_Fint *comm, MPI_Fint *color, MPI_Fint *key, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_split((MPI_Comm)(*comm), *color, *key, (MPI_Comm*)newcomm);
#else /* MPI-2 safe call */
    MPI_Comm temp_newcomm;
    temp_newcomm = MPI_Comm_f2c(*newcomm);
    _wrap_py_return_val = MPI_Comm_split(MPI_Comm_f2c(*comm), *color, *key, &temp_newcomm);
    *newcomm = MPI_Comm_c2f(temp_newcomm);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_SPLIT(MPI_Fint *comm, MPI_Fint *color, MPI_Fint *key, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_split_fortran_wrapper(comm, color, key, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_split(MPI_Fint *comm, MPI_Fint *color, MPI_Fint *key, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_split_fortran_wrapper(comm, color, key, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_split_(MPI_Fint *comm, MPI_Fint *color, MPI_Fint *key, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_split_fortran_wrapper(comm, color, key, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_split__(MPI_Fint *comm, MPI_Fint *color, MPI_Fint *key, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_split_fortran_wrapper(comm, color, key, newcomm, ierr);
}

/* ================= End Wrappers for MPI_Comm_split ================= */


/* =============== Fortran Wrappers for MPI_Comm_test_inter =============== */
static void MPI_Comm_test_inter_fortran_wrapper(MPI_Fint *comm, MPI_Fint *flag, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_test_inter((MPI_Comm)(*comm), (int*)flag);
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Comm_test_inter(MPI_Comm_f2c(*comm), (int*)flag);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_TEST_INTER(MPI_Fint *comm, MPI_Fint *flag, MPI_Fint *ierr) { 
    MPI_Comm_test_inter_fortran_wrapper(comm, flag, ierr);
}

_EXTERN_C_ void mpi_comm_test_inter(MPI_Fint *comm, MPI_Fint *flag, MPI_Fint *ierr) { 
    MPI_Comm_test_inter_fortran_wrapper(comm, flag, ierr);
}

_EXTERN_C_ void mpi_comm_test_inter_(MPI_Fint *comm, MPI_Fint *flag, MPI_Fint *ierr) { 
    MPI_Comm_test_inter_fortran_wrapper(comm, flag, ierr);
}

_EXTERN_C_ void mpi_comm_test_inter__(MPI_Fint *comm, MPI_Fint *flag, MPI_Fint *ierr) { 
    MPI_Comm_test_inter_fortran_wrapper(comm, flag, ierr);
}

/* ================= End Wrappers for MPI_Comm_test_inter ================= */


/* =============== Fortran Wrappers for MPI_Dist_graph_create =============== */
static void MPI_Dist_graph_create_fortran_wrapper(MPI_Fint *comm_old, MPI_Fint *n, MPI_Fint nodes[], MPI_Fint degrees[], MPI_Fint targets[], MPI_Fint weights[], MPI_Fint *info, MPI_Fint *reorder, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Dist_graph_create((MPI_Comm)(*comm_old), *n, (MPI_CONST int*)nodes, (MPI_CONST int*)degrees, (MPI_CONST int*)targets, (MPI_CONST int*)weights, (MPI_Info)(*info), *reorder, (MPI_Comm*)newcomm);
#else /* MPI-2 safe call */
    MPI_Comm temp_newcomm;
    temp_newcomm = MPI_Comm_f2c(*newcomm);
    _wrap_py_return_val = MPI_Dist_graph_create(MPI_Comm_f2c(*comm_old), *n, (MPI_CONST int*)nodes, (MPI_CONST int*)degrees, (MPI_CONST int*)targets, (MPI_CONST int*)weights, MPI_Info_f2c(*info), *reorder, &temp_newcomm);
    *newcomm = MPI_Comm_c2f(temp_newcomm);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_DIST_GRAPH_CREATE(MPI_Fint *comm_old, MPI_Fint *n, MPI_Fint nodes[], MPI_Fint degrees[], MPI_Fint targets[], MPI_Fint weights[], MPI_Fint *info, MPI_Fint *reorder, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Dist_graph_create_fortran_wrapper(comm_old, n, nodes, degrees, targets, weights, info, reorder, newcomm, ierr);
}

_EXTERN_C_ void mpi_dist_graph_create(MPI_Fint *comm_old, MPI_Fint *n, MPI_Fint nodes[], MPI_Fint degrees[], MPI_Fint targets[], MPI_Fint weights[], MPI_Fint *info, MPI_Fint *reorder, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Dist_graph_create_fortran_wrapper(comm_old, n, nodes, degrees, targets, weights, info, reorder, newcomm, ierr);
}

_EXTERN_C_ void mpi_dist_graph_create_(MPI_Fint *comm_old, MPI_Fint *n, MPI_Fint nodes[], MPI_Fint degrees[], MPI_Fint targets[], MPI_Fint weights[], MPI_Fint *info, MPI_Fint *reorder, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Dist_graph_create_fortran_wrapper(comm_old, n, nodes, degrees, targets, weights, info, reorder, newcomm, ierr);
}

_EXTERN_C_ void mpi_dist_graph_create__(MPI_Fint *comm_old, MPI_Fint *n, MPI_Fint nodes[], MPI_Fint degrees[], MPI_Fint targets[], MPI_Fint weights[], MPI_Fint *info, MPI_Fint *reorder, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Dist_graph_create_fortran_wrapper(comm_old, n, nodes, degrees, targets, weights, info, reorder, newcomm, ierr);
}

/* ================= End Wrappers for MPI_Dist_graph_create ================= */


/* =============== Fortran Wrappers for MPI_Dist_graph_create_adjacent =============== */
static void MPI_Dist_graph_create_adjacent_fortran_wrapper(MPI_Fint *comm_old, MPI_Fint *indegree, MPI_Fint sources[], MPI_Fint sourceweights[], MPI_Fint *outdegree, MPI_Fint destinations[], MPI_Fint destweights[], MPI_Fint *info, MPI_Fint *reorder, MPI_Fint *comm_dist_graph, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Dist_graph_create_adjacent((MPI_Comm)(*comm_old), *indegree, (MPI_CONST int*)sources, (MPI_CONST int*)sourceweights, *outdegree, (MPI_CONST int*)destinations, (MPI_CONST int*)destweights, (MPI_Info)(*info), *reorder, (MPI_Comm*)comm_dist_graph);
#else /* MPI-2 safe call */
    MPI_Comm temp_comm_dist_graph;
    temp_comm_dist_graph = MPI_Comm_f2c(*comm_dist_graph);
    _wrap_py_return_val = MPI_Dist_graph_create_adjacent(MPI_Comm_f2c(*comm_old), *indegree, (MPI_CONST int*)sources, (MPI_CONST int*)sourceweights, *outdegree, (MPI_CONST int*)destinations, (MPI_CONST int*)destweights, MPI_Info_f2c(*info), *reorder, &temp_comm_dist_graph);
    *comm_dist_graph = MPI_Comm_c2f(temp_comm_dist_graph);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_DIST_GRAPH_CREATE_ADJACENT(MPI_Fint *comm_old, MPI_Fint *indegree, MPI_Fint sources[], MPI_Fint sourceweights[], MPI_Fint *outdegree, MPI_Fint destinations[], MPI_Fint destweights[], MPI_Fint *info, MPI_Fint *reorder, MPI_Fint *comm_dist_graph, MPI_Fint *ierr) { 
    MPI_Dist_graph_create_adjacent_fortran_wrapper(comm_old, indegree, sources, sourceweights, outdegree, destinations, destweights, info, reorder, comm_dist_graph, ierr);
}

_EXTERN_C_ void mpi_dist_graph_create_adjacent(MPI_Fint *comm_old, MPI_Fint *indegree, MPI_Fint sources[], MPI_Fint sourceweights[], MPI_Fint *outdegree, MPI_Fint destinations[], MPI_Fint destweights[], MPI_Fint *info, MPI_Fint *reorder, MPI_Fint *comm_dist_graph, MPI_Fint *ierr) { 
    MPI_Dist_graph_create_adjacent_fortran_wrapper(comm_old, indegree, sources, sourceweights, outdegree, destinations, destweights, info, reorder, comm_dist_graph, ierr);
}

_EXTERN_C_ void mpi_dist_graph_create_adjacent_(MPI_Fint *comm_old, MPI_Fint *indegree, MPI_Fint sources[], MPI_Fint sourceweights[], MPI_Fint *outdegree, MPI_Fint destinations[], MPI_Fint destweights[], MPI_Fint *info, MPI_Fint *reorder, MPI_Fint *comm_dist_graph, MPI_Fint *ierr) { 
    MPI_Dist_graph_create_adjacent_fortran_wrapper(comm_old, indegree, sources, sourceweights, outdegree, destinations, destweights, info, reorder, comm_dist_graph, ierr);
}

_EXTERN_C_ void mpi_dist_graph_create_adjacent__(MPI_Fint *comm_old, MPI_Fint *indegree, MPI_Fint sources[], MPI_Fint sourceweights[], MPI_Fint *outdegree, MPI_Fint destinations[], MPI_Fint destweights[], MPI_Fint *info, MPI_Fint *reorder, MPI_Fint *comm_dist_graph, MPI_Fint *ierr) { 
    MPI_Dist_graph_create_adjacent_fortran_wrapper(comm_old, indegree, sources, sourceweights, outdegree, destinations, destweights, info, reorder, comm_dist_graph, ierr);
}

/* ================= End Wrappers for MPI_Dist_graph_create_adjacent ================= */


/* =============== Fortran Wrappers for MPI_Dist_graph_neighbors =============== */
static void MPI_Dist_graph_neighbors_fortran_wrapper(MPI_Fint *comm, MPI_Fint *maxindegree, MPI_Fint sources[], MPI_Fint sourceweights[], MPI_Fint *maxoutdegree, MPI_Fint destinations[], MPI_Fint destweights[], MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Dist_graph_neighbors((MPI_Comm)(*comm), *maxindegree, (int*)sources, (int*)sourceweights, *maxoutdegree, (int*)destinations, (int*)destweights);
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Dist_graph_neighbors(MPI_Comm_f2c(*comm), *maxindegree, (int*)sources, (int*)sourceweights, *maxoutdegree, (int*)destinations, (int*)destweights);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_DIST_GRAPH_NEIGHBORS(MPI_Fint *comm, MPI_Fint *maxindegree, MPI_Fint sources[], MPI_Fint sourceweights[], MPI_Fint *maxoutdegree, MPI_Fint destinations[], MPI_Fint destweights[], MPI_Fint *ierr) { 
    MPI_Dist_graph_neighbors_fortran_wrapper(comm, maxindegree, sources, sourceweights, maxoutdegree, destinations, destweights, ierr);
}

_EXTERN_C_ void mpi_dist_graph_neighbors(MPI_Fint *comm, MPI_Fint *maxindegree, MPI_Fint sources[], MPI_Fint sourceweights[], MPI_Fint *maxoutdegree, MPI_Fint destinations[], MPI_Fint destweights[], MPI_Fint *ierr) { 
    MPI_Dist_graph_neighbors_fortran_wrapper(comm, maxindegree, sources, sourceweights, maxoutdegree, destinations, destweights, ierr);
}

_EXTERN_C_ void mpi_dist_graph_neighbors_(MPI_Fint *comm, MPI_Fint *maxindegree, MPI_Fint sources[], MPI_Fint sourceweights[], MPI_Fint *maxoutdegree, MPI_Fint destinations[], MPI_Fint destweights[], MPI_Fint *ierr) { 
    MPI_Dist_graph_neighbors_fortran_wrapper(comm, maxindegree, sources, sourceweights, maxoutdegree, destinations, destweights, ierr);
}

_EXTERN_C_ void mpi_dist_graph_neighbors__(MPI_Fint *comm, MPI_Fint *maxindegree, MPI_Fint sources[], MPI_Fint sourceweights[], MPI_Fint *maxoutdegree, MPI_Fint destinations[], MPI_Fint destweights[], MPI_Fint *ierr) { 
    MPI_Dist_graph_neighbors_fortran_wrapper(comm, maxindegree, sources, sourceweights, maxoutdegree, destinations, destweights, ierr);
}

/* ================= End Wrappers for MPI_Dist_graph_neighbors ================= */


/* =============== Fortran Wrappers for MPI_Dist_graph_neighbors_count =============== */
static void MPI_Dist_graph_neighbors_count_fortran_wrapper(MPI_Fint *comm, MPI_Fint *inneighbors, MPI_Fint *outneighbors, MPI_Fint *weighted, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Dist_graph_neighbors_count((MPI_Comm)(*comm), (int*)inneighbors, (int*)outneighbors, (int*)weighted);
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Dist_graph_neighbors_count(MPI_Comm_f2c(*comm), (int*)inneighbors, (int*)outneighbors, (int*)weighted);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_DIST_GRAPH_NEIGHBORS_COUNT(MPI_Fint *comm, MPI_Fint *inneighbors, MPI_Fint *outneighbors, MPI_Fint *weighted, MPI_Fint *ierr) { 
    MPI_Dist_graph_neighbors_count_fortran_wrapper(comm, inneighbors, outneighbors, weighted, ierr);
}

_EXTERN_C_ void mpi_dist_graph_neighbors_count(MPI_Fint *comm, MPI_Fint *inneighbors, MPI_Fint *outneighbors, MPI_Fint *weighted, MPI_Fint *ierr) { 
    MPI_Dist_graph_neighbors_count_fortran_wrapper(comm, inneighbors, outneighbors, weighted, ierr);
}

_EXTERN_C_ void mpi_dist_graph_neighbors_count_(MPI_Fint *comm, MPI_Fint *inneighbors, MPI_Fint *outneighbors, MPI_Fint *weighted, MPI_Fint *ierr) { 
    MPI_Dist_graph_neighbors_count_fortran_wrapper(comm, inneighbors, outneighbors, weighted, ierr);
}

_EXTERN_C_ void mpi_dist_graph_neighbors_count__(MPI_Fint *comm, MPI_Fint *inneighbors, MPI_Fint *outneighbors, MPI_Fint *weighted, MPI_Fint *ierr) { 
    MPI_Dist_graph_neighbors_count_fortran_wrapper(comm, inneighbors, outneighbors, weighted, ierr);
}

/* ================= End Wrappers for MPI_Dist_graph_neighbors_count ================= */


/* =============== Fortran Wrappers for MPI_Exscan =============== */
static void MPI_Exscan_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Exscan((MPI_CONST void*)sendbuf, (void*)recvbuf, *count, (MPI_Datatype)(*datatype), (MPI_Op)(*op), (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Exscan((MPI_CONST void*)sendbuf, (void*)recvbuf, *count, MPI_Type_f2c(*datatype), MPI_Op_f2c(*op), MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_EXSCAN(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Exscan_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}

_EXTERN_C_ void mpi_exscan(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Exscan_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}

_EXTERN_C_ void mpi_exscan_(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Exscan_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}

_EXTERN_C_ void mpi_exscan__(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Exscan_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}

/* ================= End Wrappers for MPI_Exscan ================= */


/* =============== Fortran Wrappers for MPI_File_open =============== */
static void MPI_File_open_fortran_wrapper(MPI_Fint *comm, MPI_Fint *filename, MPI_Fint *amode, MPI_Fint *info, MPI_Fint *fh, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_open((MPI_Comm)(*comm), (MPI_CONST char*)filename, *amode, (MPI_Info)(*info), (MPI_File*)fh);
#else /* MPI-2 safe call */
    MPI_File temp_fh;
    temp_fh = MPI_File_f2c(*fh);
    _wrap_py_return_val = MPI_File_open(MPI_Comm_f2c(*comm), (MPI_CONST char*)filename, *amode, MPI_Info_f2c(*info), &temp_fh);
    *fh = MPI_File_c2f(temp_fh);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_OPEN(MPI_Fint *comm, MPI_Fint *filename, MPI_Fint *amode, MPI_Fint *info, MPI_Fint *fh, MPI_Fint *ierr) { 
    MPI_File_open_fortran_wrapper(comm, filename, amode, info, fh, ierr);
}

_EXTERN_C_ void mpi_file_open(MPI_Fint *comm, MPI_Fint *filename, MPI_Fint *amode, MPI_Fint *info, MPI_Fint *fh, MPI_Fint *ierr) { 
    MPI_File_open_fortran_wrapper(comm, filename, amode, info, fh, ierr);
}

_EXTERN_C_ void mpi_file_open_(MPI_Fint *comm, MPI_Fint *filename, MPI_Fint *amode, MPI_Fint *info, MPI_Fint *fh, MPI_Fint *ierr) { 
    MPI_File_open_fortran_wrapper(comm, filename, amode, info, fh, ierr);
}

_EXTERN_C_ void mpi_file_open__(MPI_Fint *comm, MPI_Fint *filename, MPI_Fint *amode, MPI_Fint *info, MPI_Fint *fh, MPI_Fint *ierr) { 
    MPI_File_open_fortran_wrapper(comm, filename, amode, info, fh, ierr);
}

/* ================= End Wrappers for MPI_File_open ================= */


/* =============== Fortran Wrappers for MPI_Gather =============== */
static void MPI_Gather_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Gather((MPI_CONST void*)sendbuf, *sendcount, (MPI_Datatype)(*sendtype), (void*)recvbuf, *recvcount, (MPI_Datatype)(*recvtype), *root, (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Gather((MPI_CONST void*)sendbuf, *sendcount, MPI_Type_f2c(*sendtype), (void*)recvbuf, *recvcount, MPI_Type_f2c(*recvtype), *root, MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_GATHER(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Gather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}

_EXTERN_C_ void mpi_gather(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Gather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}

_EXTERN_C_ void mpi_gather_(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Gather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}

_EXTERN_C_ void mpi_gather__(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Gather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}

/* ================= End Wrappers for MPI_Gather ================= */


/* =============== Fortran Wrappers for MPI_Gatherv =============== */
static void MPI_Gatherv_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint displs[], MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Gatherv((MPI_CONST void*)sendbuf, *sendcount, (MPI_Datatype)(*sendtype), (void*)recvbuf, (MPI_CONST int*)recvcounts, (MPI_CONST int*)displs, (MPI_Datatype)(*recvtype), *root, (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Gatherv((MPI_CONST void*)sendbuf, *sendcount, MPI_Type_f2c(*sendtype), (void*)recvbuf, (MPI_CONST int*)recvcounts, (MPI_CONST int*)displs, MPI_Type_f2c(*recvtype), *root, MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_GATHERV(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint displs[], MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Gatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, ierr);
}

_EXTERN_C_ void mpi_gatherv(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint displs[], MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Gatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, ierr);
}

_EXTERN_C_ void mpi_gatherv_(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint displs[], MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Gatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, ierr);
}

_EXTERN_C_ void mpi_gatherv__(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint displs[], MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Gatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, ierr);
}

/* ================= End Wrappers for MPI_Gatherv ================= */


/* =============== Fortran Wrappers for MPI_Graph_create =============== */
static void MPI_Graph_create_fortran_wrapper(MPI_Fint *comm_old, MPI_Fint *nnodes, MPI_Fint index[], MPI_Fint edges[], MPI_Fint *reorder, MPI_Fint *comm_graph, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Graph_create((MPI_Comm)(*comm_old), *nnodes, (MPI_CONST int*)index, (MPI_CONST int*)edges, *reorder, (MPI_Comm*)comm_graph);
#else /* MPI-2 safe call */
    MPI_Comm temp_comm_graph;
    temp_comm_graph = MPI_Comm_f2c(*comm_graph);
    _wrap_py_return_val = MPI_Graph_create(MPI_Comm_f2c(*comm_old), *nnodes, (MPI_CONST int*)index, (MPI_CONST int*)edges, *reorder, &temp_comm_graph);
    *comm_graph = MPI_Comm_c2f(temp_comm_graph);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_GRAPH_CREATE(MPI_Fint *comm_old, MPI_Fint *nnodes, MPI_Fint index[], MPI_Fint edges[], MPI_Fint *reorder, MPI_Fint *comm_graph, MPI_Fint *ierr) { 
    MPI_Graph_create_fortran_wrapper(comm_old, nnodes, index, edges, reorder, comm_graph, ierr);
}

_EXTERN_C_ void mpi_graph_create(MPI_Fint *comm_old, MPI_Fint *nnodes, MPI_Fint index[], MPI_Fint edges[], MPI_Fint *reorder, MPI_Fint *comm_graph, MPI_Fint *ierr) { 
    MPI_Graph_create_fortran_wrapper(comm_old, nnodes, index, edges, reorder, comm_graph, ierr);
}

_EXTERN_C_ void mpi_graph_create_(MPI_Fint *comm_old, MPI_Fint *nnodes, MPI_Fint index[], MPI_Fint edges[], MPI_Fint *reorder, MPI_Fint *comm_graph, MPI_Fint *ierr) { 
    MPI_Graph_create_fortran_wrapper(comm_old, nnodes, index, edges, reorder, comm_graph, ierr);
}

_EXTERN_C_ void mpi_graph_create__(MPI_Fint *comm_old, MPI_Fint *nnodes, MPI_Fint index[], MPI_Fint edges[], MPI_Fint *reorder, MPI_Fint *comm_graph, MPI_Fint *ierr) { 
    MPI_Graph_create_fortran_wrapper(comm_old, nnodes, index, edges, reorder, comm_graph, ierr);
}

/* ================= End Wrappers for MPI_Graph_create ================= */


/* =============== Fortran Wrappers for MPI_Graph_get =============== */
static void MPI_Graph_get_fortran_wrapper(MPI_Fint *comm, MPI_Fint *maxindex, MPI_Fint *maxedges, MPI_Fint index[], MPI_Fint edges[], MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Graph_get((MPI_Comm)(*comm), *maxindex, *maxedges, (int*)index, (int*)edges);
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Graph_get(MPI_Comm_f2c(*comm), *maxindex, *maxedges, (int*)index, (int*)edges);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_GRAPH_GET(MPI_Fint *comm, MPI_Fint *maxindex, MPI_Fint *maxedges, MPI_Fint index[], MPI_Fint edges[], MPI_Fint *ierr) { 
    MPI_Graph_get_fortran_wrapper(comm, maxindex, maxedges, index, edges, ierr);
}

_EXTERN_C_ void mpi_graph_get(MPI_Fint *comm, MPI_Fint *maxindex, MPI_Fint *maxedges, MPI_Fint index[], MPI_Fint edges[], MPI_Fint *ierr) { 
    MPI_Graph_get_fortran_wrapper(comm, maxindex, maxedges, index, edges, ierr);
}

_EXTERN_C_ void mpi_graph_get_(MPI_Fint *comm, MPI_Fint *maxindex, MPI_Fint *maxedges, MPI_Fint index[], MPI_Fint edges[], MPI_Fint *ierr) { 
    MPI_Graph_get_fortran_wrapper(comm, maxindex, maxedges, index, edges, ierr);
}

_EXTERN_C_ void mpi_graph_get__(MPI_Fint *comm, MPI_Fint *maxindex, MPI_Fint *maxedges, MPI_Fint index[], MPI_Fint edges[], MPI_Fint *ierr) { 
    MPI_Graph_get_fortran_wrapper(comm, maxindex, maxedges, index, edges, ierr);
}

/* ================= End Wrappers for MPI_Graph_get ================= */


/* =============== Fortran Wrappers for MPI_Graph_map =============== */
static void MPI_Graph_map_fortran_wrapper(MPI_Fint *comm, MPI_Fint *nnodes, MPI_Fint index[], MPI_Fint edges[], MPI_Fint *newrank, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Graph_map((MPI_Comm)(*comm), *nnodes, (MPI_CONST int*)index, (MPI_CONST int*)edges, (int*)newrank);
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Graph_map(MPI_Comm_f2c(*comm), *nnodes, (MPI_CONST int*)index, (MPI_CONST int*)edges, (int*)newrank);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_GRAPH_MAP(MPI_Fint *comm, MPI_Fint *nnodes, MPI_Fint index[], MPI_Fint edges[], MPI_Fint *newrank, MPI_Fint *ierr) { 
    MPI_Graph_map_fortran_wrapper(comm, nnodes, index, edges, newrank, ierr);
}

_EXTERN_C_ void mpi_graph_map(MPI_Fint *comm, MPI_Fint *nnodes, MPI_Fint index[], MPI_Fint edges[], MPI_Fint *newrank, MPI_Fint *ierr) { 
    MPI_Graph_map_fortran_wrapper(comm, nnodes, index, edges, newrank, ierr);
}

_EXTERN_C_ void mpi_graph_map_(MPI_Fint *comm, MPI_Fint *nnodes, MPI_Fint index[], MPI_Fint edges[], MPI_Fint *newrank, MPI_Fint *ierr) { 
    MPI_Graph_map_fortran_wrapper(comm, nnodes, index, edges, newrank, ierr);
}

_EXTERN_C_ void mpi_graph_map__(MPI_Fint *comm, MPI_Fint *nnodes, MPI_Fint index[], MPI_Fint edges[], MPI_Fint *newrank, MPI_Fint *ierr) { 
    MPI_Graph_map_fortran_wrapper(comm, nnodes, index, edges, newrank, ierr);
}

/* ================= End Wrappers for MPI_Graph_map ================= */


/* =============== Fortran Wrappers for MPI_Graph_neighbors =============== */
static void MPI_Graph_neighbors_fortran_wrapper(MPI_Fint *comm, MPI_Fint *rank, MPI_Fint *maxneighbors, MPI_Fint neighbors[], MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Graph_neighbors((MPI_Comm)(*comm), *rank, *maxneighbors, (int*)neighbors);
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Graph_neighbors(MPI_Comm_f2c(*comm), *rank, *maxneighbors, (int*)neighbors);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_GRAPH_NEIGHBORS(MPI_Fint *comm, MPI_Fint *rank, MPI_Fint *maxneighbors, MPI_Fint neighbors[], MPI_Fint *ierr) { 
    MPI_Graph_neighbors_fortran_wrapper(comm, rank, maxneighbors, neighbors, ierr);
}

_EXTERN_C_ void mpi_graph_neighbors(MPI_Fint *comm, MPI_Fint *rank, MPI_Fint *maxneighbors, MPI_Fint neighbors[], MPI_Fint *ierr) { 
    MPI_Graph_neighbors_fortran_wrapper(comm, rank, maxneighbors, neighbors, ierr);
}

_EXTERN_C_ void mpi_graph_neighbors_(MPI_Fint *comm, MPI_Fint *rank, MPI_Fint *maxneighbors, MPI_Fint neighbors[], MPI_Fint *ierr) { 
    MPI_Graph_neighbors_fortran_wrapper(comm, rank, maxneighbors, neighbors, ierr);
}

_EXTERN_C_ void mpi_graph_neighbors__(MPI_Fint *comm, MPI_Fint *rank, MPI_Fint *maxneighbors, MPI_Fint neighbors[], MPI_Fint *ierr) { 
    MPI_Graph_neighbors_fortran_wrapper(comm, rank, maxneighbors, neighbors, ierr);
}

/* ================= End Wrappers for MPI_Graph_neighbors ================= */


/* =============== Fortran Wrappers for MPI_Graph_neighbors_count =============== */
static void MPI_Graph_neighbors_count_fortran_wrapper(MPI_Fint *comm, MPI_Fint *rank, MPI_Fint *nneighbors, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Graph_neighbors_count((MPI_Comm)(*comm), *rank, (int*)nneighbors);
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Graph_neighbors_count(MPI_Comm_f2c(*comm), *rank, (int*)nneighbors);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_GRAPH_NEIGHBORS_COUNT(MPI_Fint *comm, MPI_Fint *rank, MPI_Fint *nneighbors, MPI_Fint *ierr) { 
    MPI_Graph_neighbors_count_fortran_wrapper(comm, rank, nneighbors, ierr);
}

_EXTERN_C_ void mpi_graph_neighbors_count(MPI_Fint *comm, MPI_Fint *rank, MPI_Fint *nneighbors, MPI_Fint *ierr) { 
    MPI_Graph_neighbors_count_fortran_wrapper(comm, rank, nneighbors, ierr);
}

_EXTERN_C_ void mpi_graph_neighbors_count_(MPI_Fint *comm, MPI_Fint *rank, MPI_Fint *nneighbors, MPI_Fint *ierr) { 
    MPI_Graph_neighbors_count_fortran_wrapper(comm, rank, nneighbors, ierr);
}

_EXTERN_C_ void mpi_graph_neighbors_count__(MPI_Fint *comm, MPI_Fint *rank, MPI_Fint *nneighbors, MPI_Fint *ierr) { 
    MPI_Graph_neighbors_count_fortran_wrapper(comm, rank, nneighbors, ierr);
}

/* ================= End Wrappers for MPI_Graph_neighbors_count ================= */


/* =============== Fortran Wrappers for MPI_Graphdims_get =============== */
static void MPI_Graphdims_get_fortran_wrapper(MPI_Fint *comm, MPI_Fint *nnodes, MPI_Fint *nedges, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Graphdims_get((MPI_Comm)(*comm), (int*)nnodes, (int*)nedges);
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Graphdims_get(MPI_Comm_f2c(*comm), (int*)nnodes, (int*)nedges);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_GRAPHDIMS_GET(MPI_Fint *comm, MPI_Fint *nnodes, MPI_Fint *nedges, MPI_Fint *ierr) { 
    MPI_Graphdims_get_fortran_wrapper(comm, nnodes, nedges, ierr);
}

_EXTERN_C_ void mpi_graphdims_get(MPI_Fint *comm, MPI_Fint *nnodes, MPI_Fint *nedges, MPI_Fint *ierr) { 
    MPI_Graphdims_get_fortran_wrapper(comm, nnodes, nedges, ierr);
}

_EXTERN_C_ void mpi_graphdims_get_(MPI_Fint *comm, MPI_Fint *nnodes, MPI_Fint *nedges, MPI_Fint *ierr) { 
    MPI_Graphdims_get_fortran_wrapper(comm, nnodes, nedges, ierr);
}

_EXTERN_C_ void mpi_graphdims_get__(MPI_Fint *comm, MPI_Fint *nnodes, MPI_Fint *nedges, MPI_Fint *ierr) { 
    MPI_Graphdims_get_fortran_wrapper(comm, nnodes, nedges, ierr);
}

/* ================= End Wrappers for MPI_Graphdims_get ================= */


/* =============== Fortran Wrappers for MPI_Iallgather =============== */
static void MPI_Iallgather_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Iallgather((MPI_CONST void*)sendbuf, *sendcount, (MPI_Datatype)(*sendtype), (void*)recvbuf, *recvcount, (MPI_Datatype)(*recvtype), (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Iallgather((MPI_CONST void*)sendbuf, *sendcount, MPI_Type_f2c(*sendtype), (void*)recvbuf, *recvcount, MPI_Type_f2c(*recvtype), MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_IALLGATHER(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Iallgather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}

_EXTERN_C_ void mpi_iallgather(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Iallgather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}

_EXTERN_C_ void mpi_iallgather_(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Iallgather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}

_EXTERN_C_ void mpi_iallgather__(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Iallgather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Iallgather ================= */


/* =============== Fortran Wrappers for MPI_Iallgatherv =============== */
static void MPI_Iallgatherv_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint displs[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Iallgatherv((MPI_CONST void*)sendbuf, *sendcount, (MPI_Datatype)(*sendtype), (void*)recvbuf, (MPI_CONST int*)recvcounts, (MPI_CONST int*)displs, (MPI_Datatype)(*recvtype), (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Iallgatherv((MPI_CONST void*)sendbuf, *sendcount, MPI_Type_f2c(*sendtype), (void*)recvbuf, (MPI_CONST int*)recvcounts, (MPI_CONST int*)displs, MPI_Type_f2c(*recvtype), MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_IALLGATHERV(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint displs[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Iallgatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request, ierr);
}

_EXTERN_C_ void mpi_iallgatherv(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint displs[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Iallgatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request, ierr);
}

_EXTERN_C_ void mpi_iallgatherv_(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint displs[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Iallgatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request, ierr);
}

_EXTERN_C_ void mpi_iallgatherv__(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint displs[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Iallgatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Iallgatherv ================= */


/* =============== Fortran Wrappers for MPI_Iallreduce =============== */
static void MPI_Iallreduce_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Iallreduce((MPI_CONST void*)sendbuf, (void*)recvbuf, *count, (MPI_Datatype)(*datatype), (MPI_Op)(*op), (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Iallreduce((MPI_CONST void*)sendbuf, (void*)recvbuf, *count, MPI_Type_f2c(*datatype), MPI_Op_f2c(*op), MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_IALLREDUCE(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Iallreduce_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, request, ierr);
}

_EXTERN_C_ void mpi_iallreduce(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Iallreduce_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, request, ierr);
}

_EXTERN_C_ void mpi_iallreduce_(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Iallreduce_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, request, ierr);
}

_EXTERN_C_ void mpi_iallreduce__(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Iallreduce_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Iallreduce ================= */


/* =============== Fortran Wrappers for MPI_Ialltoall =============== */
static void MPI_Ialltoall_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Ialltoall((MPI_CONST void*)sendbuf, *sendcount, (MPI_Datatype)(*sendtype), (void*)recvbuf, *recvcount, (MPI_Datatype)(*recvtype), (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Ialltoall((MPI_CONST void*)sendbuf, *sendcount, MPI_Type_f2c(*sendtype), (void*)recvbuf, *recvcount, MPI_Type_f2c(*recvtype), MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_IALLTOALL(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ialltoall_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}

_EXTERN_C_ void mpi_ialltoall(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ialltoall_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}

_EXTERN_C_ void mpi_ialltoall_(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ialltoall_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}

_EXTERN_C_ void mpi_ialltoall__(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ialltoall_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Ialltoall ================= */


/* =============== Fortran Wrappers for MPI_Ialltoallv =============== */
static void MPI_Ialltoallv_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Ialltoallv((MPI_CONST void*)sendbuf, (MPI_CONST int*)sendcounts, (MPI_CONST int*)sdispls, (MPI_Datatype)(*sendtype), (void*)recvbuf, (MPI_CONST int*)recvcounts, (MPI_CONST int*)rdispls, (MPI_Datatype)(*recvtype), (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Ialltoallv((MPI_CONST void*)sendbuf, (MPI_CONST int*)sendcounts, (MPI_CONST int*)sdispls, MPI_Type_f2c(*sendtype), (void*)recvbuf, (MPI_CONST int*)recvcounts, (MPI_CONST int*)rdispls, MPI_Type_f2c(*recvtype), MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_IALLTOALLV(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ialltoallv_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request, ierr);
}

_EXTERN_C_ void mpi_ialltoallv(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ialltoallv_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request, ierr);
}

_EXTERN_C_ void mpi_ialltoallv_(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ialltoallv_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request, ierr);
}

_EXTERN_C_ void mpi_ialltoallv__(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ialltoallv_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Ialltoallv ================= */


/* =============== Fortran Wrappers for MPI_Ialltoallw =============== */
static void MPI_Ialltoallw_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint sendtypes[], MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint recvtypes[], MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Ialltoallw((MPI_CONST void*)sendbuf, (MPI_CONST int*)sendcounts, (MPI_CONST int*)sdispls, (MPI_CONST MPI_Datatype*)sendtypes, (void*)recvbuf, (MPI_CONST int*)recvcounts, (MPI_CONST int*)rdispls, (MPI_CONST MPI_Datatype*)recvtypes, (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Ialltoallw((MPI_CONST void*)sendbuf, (MPI_CONST int*)sendcounts, (MPI_CONST int*)sdispls, (MPI_CONST MPI_Datatype*)sendtypes, (void*)recvbuf, (MPI_CONST int*)recvcounts, (MPI_CONST int*)rdispls, (MPI_CONST MPI_Datatype*)recvtypes, MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_IALLTOALLW(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint sendtypes[], MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint recvtypes[], MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ialltoallw_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request, ierr);
}

_EXTERN_C_ void mpi_ialltoallw(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint sendtypes[], MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint recvtypes[], MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ialltoallw_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request, ierr);
}

_EXTERN_C_ void mpi_ialltoallw_(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint sendtypes[], MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint recvtypes[], MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ialltoallw_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request, ierr);
}

_EXTERN_C_ void mpi_ialltoallw__(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint sendtypes[], MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint recvtypes[], MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ialltoallw_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Ialltoallw ================= */


/* =============== Fortran Wrappers for MPI_Ibarrier =============== */
static void MPI_Ibarrier_fortran_wrapper(MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Ibarrier((MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Ibarrier(MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_IBARRIER(MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ibarrier_fortran_wrapper(comm, request, ierr);
}

_EXTERN_C_ void mpi_ibarrier(MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ibarrier_fortran_wrapper(comm, request, ierr);
}

_EXTERN_C_ void mpi_ibarrier_(MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ibarrier_fortran_wrapper(comm, request, ierr);
}

_EXTERN_C_ void mpi_ibarrier__(MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ibarrier_fortran_wrapper(comm, request, ierr);
}

/* ================= End Wrappers for MPI_Ibarrier ================= */


/* =============== Fortran Wrappers for MPI_Ibcast =============== */
static void MPI_Ibcast_fortran_wrapper(MPI_Fint *buffer, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Ibcast((void*)buffer, *count, (MPI_Datatype)(*datatype), *root, (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Ibcast((void*)buffer, *count, MPI_Type_f2c(*datatype), *root, MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_IBCAST(MPI_Fint *buffer, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ibcast_fortran_wrapper(buffer, count, datatype, root, comm, request, ierr);
}

_EXTERN_C_ void mpi_ibcast(MPI_Fint *buffer, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ibcast_fortran_wrapper(buffer, count, datatype, root, comm, request, ierr);
}

_EXTERN_C_ void mpi_ibcast_(MPI_Fint *buffer, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ibcast_fortran_wrapper(buffer, count, datatype, root, comm, request, ierr);
}

_EXTERN_C_ void mpi_ibcast__(MPI_Fint *buffer, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ibcast_fortran_wrapper(buffer, count, datatype, root, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Ibcast ================= */


/* =============== Fortran Wrappers for MPI_Ibsend =============== */
static void MPI_Ibsend_fortran_wrapper(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Ibsend((MPI_CONST void*)buf, *count, (MPI_Datatype)(*datatype), *dest, *tag, (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Ibsend((MPI_CONST void*)buf, *count, MPI_Type_f2c(*datatype), *dest, *tag, MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_IBSEND(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ibsend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_ibsend(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ibsend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_ibsend_(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ibsend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_ibsend__(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ibsend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Ibsend ================= */


/* =============== Fortran Wrappers for MPI_Iexscan =============== */
static void MPI_Iexscan_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Iexscan((MPI_CONST void*)sendbuf, (void*)recvbuf, *count, (MPI_Datatype)(*datatype), (MPI_Op)(*op), (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Iexscan((MPI_CONST void*)sendbuf, (void*)recvbuf, *count, MPI_Type_f2c(*datatype), MPI_Op_f2c(*op), MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_IEXSCAN(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Iexscan_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, request, ierr);
}

_EXTERN_C_ void mpi_iexscan(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Iexscan_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, request, ierr);
}

_EXTERN_C_ void mpi_iexscan_(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Iexscan_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, request, ierr);
}

_EXTERN_C_ void mpi_iexscan__(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Iexscan_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Iexscan ================= */


/* =============== Fortran Wrappers for MPI_Igather =============== */
static void MPI_Igather_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Igather((MPI_CONST void*)sendbuf, *sendcount, (MPI_Datatype)(*sendtype), (void*)recvbuf, *recvcount, (MPI_Datatype)(*recvtype), *root, (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Igather((MPI_CONST void*)sendbuf, *sendcount, MPI_Type_f2c(*sendtype), (void*)recvbuf, *recvcount, MPI_Type_f2c(*recvtype), *root, MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_IGATHER(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Igather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierr);
}

_EXTERN_C_ void mpi_igather(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Igather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierr);
}

_EXTERN_C_ void mpi_igather_(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Igather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierr);
}

_EXTERN_C_ void mpi_igather__(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Igather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Igather ================= */


/* =============== Fortran Wrappers for MPI_Igatherv =============== */
static void MPI_Igatherv_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint displs[], MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Igatherv((MPI_CONST void*)sendbuf, *sendcount, (MPI_Datatype)(*sendtype), (void*)recvbuf, (MPI_CONST int*)recvcounts, (MPI_CONST int*)displs, (MPI_Datatype)(*recvtype), *root, (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Igatherv((MPI_CONST void*)sendbuf, *sendcount, MPI_Type_f2c(*sendtype), (void*)recvbuf, (MPI_CONST int*)recvcounts, (MPI_CONST int*)displs, MPI_Type_f2c(*recvtype), *root, MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_IGATHERV(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint displs[], MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Igatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, request, ierr);
}

_EXTERN_C_ void mpi_igatherv(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint displs[], MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Igatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, request, ierr);
}

_EXTERN_C_ void mpi_igatherv_(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint displs[], MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Igatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, request, ierr);
}

_EXTERN_C_ void mpi_igatherv__(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint displs[], MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Igatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Igatherv ================= */


/* =============== Fortran Wrappers for MPI_Improbe =============== */
static void MPI_Improbe_fortran_wrapper(MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *flag, MPI_Fint *message, MPI_Fint *status, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Improbe(*source, *tag, (MPI_Comm)(*comm), (int*)flag, (MPI_Message*)message, (MPI_Status*)status);
#else /* MPI-2 safe call */
    MPI_Status temp_status;
    MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_Improbe(*source, *tag, MPI_Comm_f2c(*comm), (int*)flag, (MPI_Message*)message, &temp_status);
    MPI_Status_c2f(&temp_status, status);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_IMPROBE(MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *flag, MPI_Fint *message, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Improbe_fortran_wrapper(source, tag, comm, flag, message, status, ierr);
}

_EXTERN_C_ void mpi_improbe(MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *flag, MPI_Fint *message, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Improbe_fortran_wrapper(source, tag, comm, flag, message, status, ierr);
}

_EXTERN_C_ void mpi_improbe_(MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *flag, MPI_Fint *message, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Improbe_fortran_wrapper(source, tag, comm, flag, message, status, ierr);
}

_EXTERN_C_ void mpi_improbe__(MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *flag, MPI_Fint *message, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Improbe_fortran_wrapper(source, tag, comm, flag, message, status, ierr);
}

/* ================= End Wrappers for MPI_Improbe ================= */


/* =============== Fortran Wrappers for MPI_Intercomm_create =============== */
static void MPI_Intercomm_create_fortran_wrapper(MPI_Fint *local_comm, MPI_Fint *local_leader, MPI_Fint *bridge_comm, MPI_Fint *remote_leader, MPI_Fint *tag, MPI_Fint *newintercomm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Intercomm_create((MPI_Comm)(*local_comm), *local_leader, (MPI_Comm)(*bridge_comm), *remote_leader, *tag, (MPI_Comm*)newintercomm);
#else /* MPI-2 safe call */
    MPI_Comm temp_newintercomm;
    temp_newintercomm = MPI_Comm_f2c(*newintercomm);
    _wrap_py_return_val = MPI_Intercomm_create(MPI_Comm_f2c(*local_comm), *local_leader, MPI_Comm_f2c(*bridge_comm), *remote_leader, *tag, &temp_newintercomm);
    *newintercomm = MPI_Comm_c2f(temp_newintercomm);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_INTERCOMM_CREATE(MPI_Fint *local_comm, MPI_Fint *local_leader, MPI_Fint *bridge_comm, MPI_Fint *remote_leader, MPI_Fint *tag, MPI_Fint *newintercomm, MPI_Fint *ierr) { 
    MPI_Intercomm_create_fortran_wrapper(local_comm, local_leader, bridge_comm, remote_leader, tag, newintercomm, ierr);
}

_EXTERN_C_ void mpi_intercomm_create(MPI_Fint *local_comm, MPI_Fint *local_leader, MPI_Fint *bridge_comm, MPI_Fint *remote_leader, MPI_Fint *tag, MPI_Fint *newintercomm, MPI_Fint *ierr) { 
    MPI_Intercomm_create_fortran_wrapper(local_comm, local_leader, bridge_comm, remote_leader, tag, newintercomm, ierr);
}

_EXTERN_C_ void mpi_intercomm_create_(MPI_Fint *local_comm, MPI_Fint *local_leader, MPI_Fint *bridge_comm, MPI_Fint *remote_leader, MPI_Fint *tag, MPI_Fint *newintercomm, MPI_Fint *ierr) { 
    MPI_Intercomm_create_fortran_wrapper(local_comm, local_leader, bridge_comm, remote_leader, tag, newintercomm, ierr);
}

_EXTERN_C_ void mpi_intercomm_create__(MPI_Fint *local_comm, MPI_Fint *local_leader, MPI_Fint *bridge_comm, MPI_Fint *remote_leader, MPI_Fint *tag, MPI_Fint *newintercomm, MPI_Fint *ierr) { 
    MPI_Intercomm_create_fortran_wrapper(local_comm, local_leader, bridge_comm, remote_leader, tag, newintercomm, ierr);
}

/* ================= End Wrappers for MPI_Intercomm_create ================= */


/* =============== Fortran Wrappers for MPI_Intercomm_merge =============== */
static void MPI_Intercomm_merge_fortran_wrapper(MPI_Fint *intercomm, MPI_Fint *high, MPI_Fint *newintercomm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Intercomm_merge((MPI_Comm)(*intercomm), *high, (MPI_Comm*)newintercomm);
#else /* MPI-2 safe call */
    MPI_Comm temp_newintercomm;
    temp_newintercomm = MPI_Comm_f2c(*newintercomm);
    _wrap_py_return_val = MPI_Intercomm_merge(MPI_Comm_f2c(*intercomm), *high, &temp_newintercomm);
    *newintercomm = MPI_Comm_c2f(temp_newintercomm);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_INTERCOMM_MERGE(MPI_Fint *intercomm, MPI_Fint *high, MPI_Fint *newintercomm, MPI_Fint *ierr) { 
    MPI_Intercomm_merge_fortran_wrapper(intercomm, high, newintercomm, ierr);
}

_EXTERN_C_ void mpi_intercomm_merge(MPI_Fint *intercomm, MPI_Fint *high, MPI_Fint *newintercomm, MPI_Fint *ierr) { 
    MPI_Intercomm_merge_fortran_wrapper(intercomm, high, newintercomm, ierr);
}

_EXTERN_C_ void mpi_intercomm_merge_(MPI_Fint *intercomm, MPI_Fint *high, MPI_Fint *newintercomm, MPI_Fint *ierr) { 
    MPI_Intercomm_merge_fortran_wrapper(intercomm, high, newintercomm, ierr);
}

_EXTERN_C_ void mpi_intercomm_merge__(MPI_Fint *intercomm, MPI_Fint *high, MPI_Fint *newintercomm, MPI_Fint *ierr) { 
    MPI_Intercomm_merge_fortran_wrapper(intercomm, high, newintercomm, ierr);
}

/* ================= End Wrappers for MPI_Intercomm_merge ================= */


/* =============== Fortran Wrappers for MPI_Iprobe =============== */
static void MPI_Iprobe_fortran_wrapper(MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *flag, MPI_Fint *status, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Iprobe(*source, *tag, (MPI_Comm)(*comm), (int*)flag, (MPI_Status*)status);
#else /* MPI-2 safe call */
    MPI_Status temp_status;
    MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_Iprobe(*source, *tag, MPI_Comm_f2c(*comm), (int*)flag, &temp_status);
    MPI_Status_c2f(&temp_status, status);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_IPROBE(MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *flag, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Iprobe_fortran_wrapper(source, tag, comm, flag, status, ierr);
}

_EXTERN_C_ void mpi_iprobe(MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *flag, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Iprobe_fortran_wrapper(source, tag, comm, flag, status, ierr);
}

_EXTERN_C_ void mpi_iprobe_(MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *flag, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Iprobe_fortran_wrapper(source, tag, comm, flag, status, ierr);
}

_EXTERN_C_ void mpi_iprobe__(MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *flag, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Iprobe_fortran_wrapper(source, tag, comm, flag, status, ierr);
}

/* ================= End Wrappers for MPI_Iprobe ================= */


/* =============== Fortran Wrappers for MPI_Irecv =============== */
static void MPI_Irecv_fortran_wrapper(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Irecv((void*)buf, *count, (MPI_Datatype)(*datatype), *source, *tag, (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Irecv((void*)buf, *count, MPI_Type_f2c(*datatype), *source, *tag, MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_IRECV(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Irecv_fortran_wrapper(buf, count, datatype, source, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_irecv(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Irecv_fortran_wrapper(buf, count, datatype, source, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_irecv_(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Irecv_fortran_wrapper(buf, count, datatype, source, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_irecv__(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Irecv_fortran_wrapper(buf, count, datatype, source, tag, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Irecv ================= */


/* =============== Fortran Wrappers for MPI_Ireduce =============== */
static void MPI_Ireduce_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Ireduce((MPI_CONST void*)sendbuf, (void*)recvbuf, *count, (MPI_Datatype)(*datatype), (MPI_Op)(*op), *root, (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Ireduce((MPI_CONST void*)sendbuf, (void*)recvbuf, *count, MPI_Type_f2c(*datatype), MPI_Op_f2c(*op), *root, MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_IREDUCE(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ireduce_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, root, comm, request, ierr);
}

_EXTERN_C_ void mpi_ireduce(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ireduce_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, root, comm, request, ierr);
}

_EXTERN_C_ void mpi_ireduce_(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ireduce_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, root, comm, request, ierr);
}

_EXTERN_C_ void mpi_ireduce__(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ireduce_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, root, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Ireduce ================= */


/* =============== Fortran Wrappers for MPI_Ireduce_scatter =============== */
static void MPI_Ireduce_scatter_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Ireduce_scatter((MPI_CONST void*)sendbuf, (void*)recvbuf, (MPI_CONST int*)recvcounts, (MPI_Datatype)(*datatype), (MPI_Op)(*op), (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Ireduce_scatter((MPI_CONST void*)sendbuf, (void*)recvbuf, (MPI_CONST int*)recvcounts, MPI_Type_f2c(*datatype), MPI_Op_f2c(*op), MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_IREDUCE_SCATTER(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ireduce_scatter_fortran_wrapper(sendbuf, recvbuf, recvcounts, datatype, op, comm, request, ierr);
}

_EXTERN_C_ void mpi_ireduce_scatter(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ireduce_scatter_fortran_wrapper(sendbuf, recvbuf, recvcounts, datatype, op, comm, request, ierr);
}

_EXTERN_C_ void mpi_ireduce_scatter_(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ireduce_scatter_fortran_wrapper(sendbuf, recvbuf, recvcounts, datatype, op, comm, request, ierr);
}

_EXTERN_C_ void mpi_ireduce_scatter__(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ireduce_scatter_fortran_wrapper(sendbuf, recvbuf, recvcounts, datatype, op, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Ireduce_scatter ================= */


/* =============== Fortran Wrappers for MPI_Ireduce_scatter_block =============== */
static void MPI_Ireduce_scatter_block_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Ireduce_scatter_block((MPI_CONST void*)sendbuf, (void*)recvbuf, *recvcount, (MPI_Datatype)(*datatype), (MPI_Op)(*op), (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Ireduce_scatter_block((MPI_CONST void*)sendbuf, (void*)recvbuf, *recvcount, MPI_Type_f2c(*datatype), MPI_Op_f2c(*op), MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_IREDUCE_SCATTER_BLOCK(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ireduce_scatter_block_fortran_wrapper(sendbuf, recvbuf, recvcount, datatype, op, comm, request, ierr);
}

_EXTERN_C_ void mpi_ireduce_scatter_block(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ireduce_scatter_block_fortran_wrapper(sendbuf, recvbuf, recvcount, datatype, op, comm, request, ierr);
}

_EXTERN_C_ void mpi_ireduce_scatter_block_(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ireduce_scatter_block_fortran_wrapper(sendbuf, recvbuf, recvcount, datatype, op, comm, request, ierr);
}

_EXTERN_C_ void mpi_ireduce_scatter_block__(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ireduce_scatter_block_fortran_wrapper(sendbuf, recvbuf, recvcount, datatype, op, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Ireduce_scatter_block ================= */


/* =============== Fortran Wrappers for MPI_Irsend =============== */
static void MPI_Irsend_fortran_wrapper(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Irsend((MPI_CONST void*)buf, *count, (MPI_Datatype)(*datatype), *dest, *tag, (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Irsend((MPI_CONST void*)buf, *count, MPI_Type_f2c(*datatype), *dest, *tag, MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_IRSEND(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Irsend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_irsend(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Irsend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_irsend_(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Irsend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_irsend__(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Irsend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Irsend ================= */


/* =============== Fortran Wrappers for MPI_Iscan =============== */
static void MPI_Iscan_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Iscan((MPI_CONST void*)sendbuf, (void*)recvbuf, *count, (MPI_Datatype)(*datatype), (MPI_Op)(*op), (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Iscan((MPI_CONST void*)sendbuf, (void*)recvbuf, *count, MPI_Type_f2c(*datatype), MPI_Op_f2c(*op), MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_ISCAN(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Iscan_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, request, ierr);
}

_EXTERN_C_ void mpi_iscan(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Iscan_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, request, ierr);
}

_EXTERN_C_ void mpi_iscan_(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Iscan_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, request, ierr);
}

_EXTERN_C_ void mpi_iscan__(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Iscan_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Iscan ================= */


/* =============== Fortran Wrappers for MPI_Iscatter =============== */
static void MPI_Iscatter_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Iscatter((MPI_CONST void*)sendbuf, *sendcount, (MPI_Datatype)(*sendtype), (void*)recvbuf, *recvcount, (MPI_Datatype)(*recvtype), *root, (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Iscatter((MPI_CONST void*)sendbuf, *sendcount, MPI_Type_f2c(*sendtype), (void*)recvbuf, *recvcount, MPI_Type_f2c(*recvtype), *root, MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_ISCATTER(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Iscatter_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierr);
}

_EXTERN_C_ void mpi_iscatter(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Iscatter_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierr);
}

_EXTERN_C_ void mpi_iscatter_(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Iscatter_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierr);
}

_EXTERN_C_ void mpi_iscatter__(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Iscatter_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Iscatter ================= */


/* =============== Fortran Wrappers for MPI_Iscatterv =============== */
static void MPI_Iscatterv_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint displs[], MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Iscatterv((MPI_CONST void*)sendbuf, (MPI_CONST int*)sendcounts, (MPI_CONST int*)displs, (MPI_Datatype)(*sendtype), (void*)recvbuf, *recvcount, (MPI_Datatype)(*recvtype), *root, (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Iscatterv((MPI_CONST void*)sendbuf, (MPI_CONST int*)sendcounts, (MPI_CONST int*)displs, MPI_Type_f2c(*sendtype), (void*)recvbuf, *recvcount, MPI_Type_f2c(*recvtype), *root, MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_ISCATTERV(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint displs[], MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Iscatterv_fortran_wrapper(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierr);
}

_EXTERN_C_ void mpi_iscatterv(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint displs[], MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Iscatterv_fortran_wrapper(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierr);
}

_EXTERN_C_ void mpi_iscatterv_(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint displs[], MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Iscatterv_fortran_wrapper(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierr);
}

_EXTERN_C_ void mpi_iscatterv__(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint displs[], MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Iscatterv_fortran_wrapper(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Iscatterv ================= */


/* =============== Fortran Wrappers for MPI_Isend =============== */
static void MPI_Isend_fortran_wrapper(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Isend((MPI_CONST void*)buf, *count, (MPI_Datatype)(*datatype), *dest, *tag, (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Isend((MPI_CONST void*)buf, *count, MPI_Type_f2c(*datatype), *dest, *tag, MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_ISEND(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Isend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_isend(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Isend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_isend_(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Isend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_isend__(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Isend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Isend ================= */


/* =============== Fortran Wrappers for MPI_Issend =============== */
static void MPI_Issend_fortran_wrapper(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Issend((MPI_CONST void*)buf, *count, (MPI_Datatype)(*datatype), *dest, *tag, (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Issend((MPI_CONST void*)buf, *count, MPI_Type_f2c(*datatype), *dest, *tag, MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_ISSEND(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Issend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_issend(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Issend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_issend_(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Issend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_issend__(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Issend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Issend ================= */


/* =============== Fortran Wrappers for MPI_Mprobe =============== */
static void MPI_Mprobe_fortran_wrapper(MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *message, MPI_Fint *status, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Mprobe(*source, *tag, (MPI_Comm)(*comm), (MPI_Message*)message, (MPI_Status*)status);
#else /* MPI-2 safe call */
    MPI_Status temp_status;
    MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_Mprobe(*source, *tag, MPI_Comm_f2c(*comm), (MPI_Message*)message, &temp_status);
    MPI_Status_c2f(&temp_status, status);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_MPROBE(MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *message, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Mprobe_fortran_wrapper(source, tag, comm, message, status, ierr);
}

_EXTERN_C_ void mpi_mprobe(MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *message, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Mprobe_fortran_wrapper(source, tag, comm, message, status, ierr);
}

_EXTERN_C_ void mpi_mprobe_(MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *message, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Mprobe_fortran_wrapper(source, tag, comm, message, status, ierr);
}

_EXTERN_C_ void mpi_mprobe__(MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *message, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Mprobe_fortran_wrapper(source, tag, comm, message, status, ierr);
}

/* ================= End Wrappers for MPI_Mprobe ================= */


/* =============== Fortran Wrappers for MPI_Pack =============== */
static void MPI_Pack_fortran_wrapper(MPI_Fint *inbuf, MPI_Fint *incount, MPI_Fint *datatype, MPI_Fint *outbuf, MPI_Fint *outsize, MPI_Fint *position, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Pack((MPI_CONST void*)inbuf, *incount, (MPI_Datatype)(*datatype), (void*)outbuf, *outsize, (int*)position, (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Pack((MPI_CONST void*)inbuf, *incount, MPI_Type_f2c(*datatype), (void*)outbuf, *outsize, (int*)position, MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_PACK(MPI_Fint *inbuf, MPI_Fint *incount, MPI_Fint *datatype, MPI_Fint *outbuf, MPI_Fint *outsize, MPI_Fint *position, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Pack_fortran_wrapper(inbuf, incount, datatype, outbuf, outsize, position, comm, ierr);
}

_EXTERN_C_ void mpi_pack(MPI_Fint *inbuf, MPI_Fint *incount, MPI_Fint *datatype, MPI_Fint *outbuf, MPI_Fint *outsize, MPI_Fint *position, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Pack_fortran_wrapper(inbuf, incount, datatype, outbuf, outsize, position, comm, ierr);
}

_EXTERN_C_ void mpi_pack_(MPI_Fint *inbuf, MPI_Fint *incount, MPI_Fint *datatype, MPI_Fint *outbuf, MPI_Fint *outsize, MPI_Fint *position, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Pack_fortran_wrapper(inbuf, incount, datatype, outbuf, outsize, position, comm, ierr);
}

_EXTERN_C_ void mpi_pack__(MPI_Fint *inbuf, MPI_Fint *incount, MPI_Fint *datatype, MPI_Fint *outbuf, MPI_Fint *outsize, MPI_Fint *position, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Pack_fortran_wrapper(inbuf, incount, datatype, outbuf, outsize, position, comm, ierr);
}

/* ================= End Wrappers for MPI_Pack ================= */


/* =============== Fortran Wrappers for MPI_Pack_size =============== */
static void MPI_Pack_size_fortran_wrapper(MPI_Fint *incount, MPI_Fint *datatype, MPI_Fint *comm, MPI_Fint *size, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Pack_size(*incount, (MPI_Datatype)(*datatype), (MPI_Comm)(*comm), (int*)size);
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Pack_size(*incount, MPI_Type_f2c(*datatype), MPI_Comm_f2c(*comm), (int*)size);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_PACK_SIZE(MPI_Fint *incount, MPI_Fint *datatype, MPI_Fint *comm, MPI_Fint *size, MPI_Fint *ierr) { 
    MPI_Pack_size_fortran_wrapper(incount, datatype, comm, size, ierr);
}

_EXTERN_C_ void mpi_pack_size(MPI_Fint *incount, MPI_Fint *datatype, MPI_Fint *comm, MPI_Fint *size, MPI_Fint *ierr) { 
    MPI_Pack_size_fortran_wrapper(incount, datatype, comm, size, ierr);
}

_EXTERN_C_ void mpi_pack_size_(MPI_Fint *incount, MPI_Fint *datatype, MPI_Fint *comm, MPI_Fint *size, MPI_Fint *ierr) { 
    MPI_Pack_size_fortran_wrapper(incount, datatype, comm, size, ierr);
}

_EXTERN_C_ void mpi_pack_size__(MPI_Fint *incount, MPI_Fint *datatype, MPI_Fint *comm, MPI_Fint *size, MPI_Fint *ierr) { 
    MPI_Pack_size_fortran_wrapper(incount, datatype, comm, size, ierr);
}

/* ================= End Wrappers for MPI_Pack_size ================= */


/* =============== Fortran Wrappers for MPI_Probe =============== */
static void MPI_Probe_fortran_wrapper(MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Probe(*source, *tag, (MPI_Comm)(*comm), (MPI_Status*)status);
#else /* MPI-2 safe call */
    MPI_Status temp_status;
    MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_Probe(*source, *tag, MPI_Comm_f2c(*comm), &temp_status);
    MPI_Status_c2f(&temp_status, status);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_PROBE(MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Probe_fortran_wrapper(source, tag, comm, status, ierr);
}

_EXTERN_C_ void mpi_probe(MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Probe_fortran_wrapper(source, tag, comm, status, ierr);
}

_EXTERN_C_ void mpi_probe_(MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Probe_fortran_wrapper(source, tag, comm, status, ierr);
}

_EXTERN_C_ void mpi_probe__(MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Probe_fortran_wrapper(source, tag, comm, status, ierr);
}

/* ================= End Wrappers for MPI_Probe ================= */


/* =============== Fortran Wrappers for MPI_Recv =============== */
static void MPI_Recv_fortran_wrapper(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Recv((void*)buf, *count, (MPI_Datatype)(*datatype), *source, *tag, (MPI_Comm)(*comm), (MPI_Status*)status);
#else /* MPI-2 safe call */
    MPI_Status temp_status;
    MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_Recv((void*)buf, *count, MPI_Type_f2c(*datatype), *source, *tag, MPI_Comm_f2c(*comm), &temp_status);
    MPI_Status_c2f(&temp_status, status);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_RECV(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Recv_fortran_wrapper(buf, count, datatype, source, tag, comm, status, ierr);
}

_EXTERN_C_ void mpi_recv(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Recv_fortran_wrapper(buf, count, datatype, source, tag, comm, status, ierr);
}

_EXTERN_C_ void mpi_recv_(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Recv_fortran_wrapper(buf, count, datatype, source, tag, comm, status, ierr);
}

_EXTERN_C_ void mpi_recv__(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Recv_fortran_wrapper(buf, count, datatype, source, tag, comm, status, ierr);
}

/* ================= End Wrappers for MPI_Recv ================= */


/* =============== Fortran Wrappers for MPI_Recv_init =============== */
static void MPI_Recv_init_fortran_wrapper(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Recv_init((void*)buf, *count, (MPI_Datatype)(*datatype), *source, *tag, (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Recv_init((void*)buf, *count, MPI_Type_f2c(*datatype), *source, *tag, MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_RECV_INIT(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Recv_init_fortran_wrapper(buf, count, datatype, source, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_recv_init(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Recv_init_fortran_wrapper(buf, count, datatype, source, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_recv_init_(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Recv_init_fortran_wrapper(buf, count, datatype, source, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_recv_init__(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Recv_init_fortran_wrapper(buf, count, datatype, source, tag, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Recv_init ================= */


/* =============== Fortran Wrappers for MPI_Reduce =============== */
static void MPI_Reduce_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Reduce((MPI_CONST void*)sendbuf, (void*)recvbuf, *count, (MPI_Datatype)(*datatype), (MPI_Op)(*op), *root, (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Reduce((MPI_CONST void*)sendbuf, (void*)recvbuf, *count, MPI_Type_f2c(*datatype), MPI_Op_f2c(*op), *root, MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_REDUCE(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Reduce_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, root, comm, ierr);
}

_EXTERN_C_ void mpi_reduce(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Reduce_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, root, comm, ierr);
}

_EXTERN_C_ void mpi_reduce_(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Reduce_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, root, comm, ierr);
}

_EXTERN_C_ void mpi_reduce__(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Reduce_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, root, comm, ierr);
}

/* ================= End Wrappers for MPI_Reduce ================= */


/* =============== Fortran Wrappers for MPI_Reduce_scatter =============== */
static void MPI_Reduce_scatter_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Reduce_scatter((MPI_CONST void*)sendbuf, (void*)recvbuf, (MPI_CONST int*)recvcounts, (MPI_Datatype)(*datatype), (MPI_Op)(*op), (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Reduce_scatter((MPI_CONST void*)sendbuf, (void*)recvbuf, (MPI_CONST int*)recvcounts, MPI_Type_f2c(*datatype), MPI_Op_f2c(*op), MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_REDUCE_SCATTER(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Reduce_scatter_fortran_wrapper(sendbuf, recvbuf, recvcounts, datatype, op, comm, ierr);
}

_EXTERN_C_ void mpi_reduce_scatter(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Reduce_scatter_fortran_wrapper(sendbuf, recvbuf, recvcounts, datatype, op, comm, ierr);
}

_EXTERN_C_ void mpi_reduce_scatter_(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Reduce_scatter_fortran_wrapper(sendbuf, recvbuf, recvcounts, datatype, op, comm, ierr);
}

_EXTERN_C_ void mpi_reduce_scatter__(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Reduce_scatter_fortran_wrapper(sendbuf, recvbuf, recvcounts, datatype, op, comm, ierr);
}

/* ================= End Wrappers for MPI_Reduce_scatter ================= */


/* =============== Fortran Wrappers for MPI_Reduce_scatter_block =============== */
static void MPI_Reduce_scatter_block_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Reduce_scatter_block((MPI_CONST void*)sendbuf, (void*)recvbuf, *recvcount, (MPI_Datatype)(*datatype), (MPI_Op)(*op), (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Reduce_scatter_block((MPI_CONST void*)sendbuf, (void*)recvbuf, *recvcount, MPI_Type_f2c(*datatype), MPI_Op_f2c(*op), MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_REDUCE_SCATTER_BLOCK(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Reduce_scatter_block_fortran_wrapper(sendbuf, recvbuf, recvcount, datatype, op, comm, ierr);
}

_EXTERN_C_ void mpi_reduce_scatter_block(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Reduce_scatter_block_fortran_wrapper(sendbuf, recvbuf, recvcount, datatype, op, comm, ierr);
}

_EXTERN_C_ void mpi_reduce_scatter_block_(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Reduce_scatter_block_fortran_wrapper(sendbuf, recvbuf, recvcount, datatype, op, comm, ierr);
}

_EXTERN_C_ void mpi_reduce_scatter_block__(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Reduce_scatter_block_fortran_wrapper(sendbuf, recvbuf, recvcount, datatype, op, comm, ierr);
}

/* ================= End Wrappers for MPI_Reduce_scatter_block ================= */


/* =============== Fortran Wrappers for MPI_Rsend =============== */
static void MPI_Rsend_fortran_wrapper(MPI_Fint *ibuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Rsend((MPI_CONST void*)ibuf, *count, (MPI_Datatype)(*datatype), *dest, *tag, (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Rsend((MPI_CONST void*)ibuf, *count, MPI_Type_f2c(*datatype), *dest, *tag, MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_RSEND(MPI_Fint *ibuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Rsend_fortran_wrapper(ibuf, count, datatype, dest, tag, comm, ierr);
}

_EXTERN_C_ void mpi_rsend(MPI_Fint *ibuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Rsend_fortran_wrapper(ibuf, count, datatype, dest, tag, comm, ierr);
}

_EXTERN_C_ void mpi_rsend_(MPI_Fint *ibuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Rsend_fortran_wrapper(ibuf, count, datatype, dest, tag, comm, ierr);
}

_EXTERN_C_ void mpi_rsend__(MPI_Fint *ibuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Rsend_fortran_wrapper(ibuf, count, datatype, dest, tag, comm, ierr);
}

/* ================= End Wrappers for MPI_Rsend ================= */


/* =============== Fortran Wrappers for MPI_Rsend_init =============== */
static void MPI_Rsend_init_fortran_wrapper(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Rsend_init((MPI_CONST void*)buf, *count, (MPI_Datatype)(*datatype), *dest, *tag, (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Rsend_init((MPI_CONST void*)buf, *count, MPI_Type_f2c(*datatype), *dest, *tag, MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_RSEND_INIT(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Rsend_init_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_rsend_init(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Rsend_init_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_rsend_init_(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Rsend_init_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_rsend_init__(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Rsend_init_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Rsend_init ================= */


/* =============== Fortran Wrappers for MPI_Scan =============== */
static void MPI_Scan_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Scan((MPI_CONST void*)sendbuf, (void*)recvbuf, *count, (MPI_Datatype)(*datatype), (MPI_Op)(*op), (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Scan((MPI_CONST void*)sendbuf, (void*)recvbuf, *count, MPI_Type_f2c(*datatype), MPI_Op_f2c(*op), MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_SCAN(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Scan_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}

_EXTERN_C_ void mpi_scan(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Scan_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}

_EXTERN_C_ void mpi_scan_(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Scan_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}

_EXTERN_C_ void mpi_scan__(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Scan_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}

/* ================= End Wrappers for MPI_Scan ================= */


/* =============== Fortran Wrappers for MPI_Scatter =============== */
static void MPI_Scatter_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Scatter((MPI_CONST void*)sendbuf, *sendcount, (MPI_Datatype)(*sendtype), (void*)recvbuf, *recvcount, (MPI_Datatype)(*recvtype), *root, (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Scatter((MPI_CONST void*)sendbuf, *sendcount, MPI_Type_f2c(*sendtype), (void*)recvbuf, *recvcount, MPI_Type_f2c(*recvtype), *root, MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_SCATTER(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Scatter_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}

_EXTERN_C_ void mpi_scatter(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Scatter_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}

_EXTERN_C_ void mpi_scatter_(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Scatter_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}

_EXTERN_C_ void mpi_scatter__(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Scatter_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}

/* ================= End Wrappers for MPI_Scatter ================= */


/* =============== Fortran Wrappers for MPI_Scatterv =============== */
static void MPI_Scatterv_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint displs[], MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Scatterv((MPI_CONST void*)sendbuf, (MPI_CONST int*)sendcounts, (MPI_CONST int*)displs, (MPI_Datatype)(*sendtype), (void*)recvbuf, *recvcount, (MPI_Datatype)(*recvtype), *root, (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Scatterv((MPI_CONST void*)sendbuf, (MPI_CONST int*)sendcounts, (MPI_CONST int*)displs, MPI_Type_f2c(*sendtype), (void*)recvbuf, *recvcount, MPI_Type_f2c(*recvtype), *root, MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_SCATTERV(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint displs[], MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Scatterv_fortran_wrapper(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}

_EXTERN_C_ void mpi_scatterv(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint displs[], MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Scatterv_fortran_wrapper(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}

_EXTERN_C_ void mpi_scatterv_(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint displs[], MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Scatterv_fortran_wrapper(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}

_EXTERN_C_ void mpi_scatterv__(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint displs[], MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Scatterv_fortran_wrapper(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}

/* ================= End Wrappers for MPI_Scatterv ================= */


/* =============== Fortran Wrappers for MPI_Send =============== */
static void MPI_Send_fortran_wrapper(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Send((MPI_CONST void*)buf, *count, (MPI_Datatype)(*datatype), *dest, *tag, (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Send((MPI_CONST void*)buf, *count, MPI_Type_f2c(*datatype), *dest, *tag, MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_SEND(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Send_fortran_wrapper(buf, count, datatype, dest, tag, comm, ierr);
}

_EXTERN_C_ void mpi_send(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Send_fortran_wrapper(buf, count, datatype, dest, tag, comm, ierr);
}

_EXTERN_C_ void mpi_send_(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Send_fortran_wrapper(buf, count, datatype, dest, tag, comm, ierr);
}

_EXTERN_C_ void mpi_send__(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Send_fortran_wrapper(buf, count, datatype, dest, tag, comm, ierr);
}

/* ================= End Wrappers for MPI_Send ================= */


/* =============== Fortran Wrappers for MPI_Send_init =============== */
static void MPI_Send_init_fortran_wrapper(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Send_init((MPI_CONST void*)buf, *count, (MPI_Datatype)(*datatype), *dest, *tag, (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Send_init((MPI_CONST void*)buf, *count, MPI_Type_f2c(*datatype), *dest, *tag, MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_SEND_INIT(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Send_init_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_send_init(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Send_init_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_send_init_(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Send_init_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_send_init__(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Send_init_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Send_init ================= */


/* =============== Fortran Wrappers for MPI_Sendrecv =============== */
static void MPI_Sendrecv_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *dest, MPI_Fint *sendtag, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Sendrecv((MPI_CONST void*)sendbuf, *sendcount, (MPI_Datatype)(*sendtype), *dest, *sendtag, (void*)recvbuf, *recvcount, (MPI_Datatype)(*recvtype), *source, *recvtag, (MPI_Comm)(*comm), (MPI_Status*)status);
#else /* MPI-2 safe call */
    MPI_Status temp_status;
    MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_Sendrecv((MPI_CONST void*)sendbuf, *sendcount, MPI_Type_f2c(*sendtype), *dest, *sendtag, (void*)recvbuf, *recvcount, MPI_Type_f2c(*recvtype), *source, *recvtag, MPI_Comm_f2c(*comm), &temp_status);
    MPI_Status_c2f(&temp_status, status);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_SENDRECV(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *dest, MPI_Fint *sendtag, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Sendrecv_fortran_wrapper(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, status, ierr);
}

_EXTERN_C_ void mpi_sendrecv(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *dest, MPI_Fint *sendtag, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Sendrecv_fortran_wrapper(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, status, ierr);
}

_EXTERN_C_ void mpi_sendrecv_(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *dest, MPI_Fint *sendtag, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Sendrecv_fortran_wrapper(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, status, ierr);
}

_EXTERN_C_ void mpi_sendrecv__(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *dest, MPI_Fint *sendtag, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Sendrecv_fortran_wrapper(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, status, ierr);
}

/* ================= End Wrappers for MPI_Sendrecv ================= */


/* =============== Fortran Wrappers for MPI_Sendrecv_replace =============== */
static void MPI_Sendrecv_replace_fortran_wrapper(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *sendtag, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Sendrecv_replace((void*)buf, *count, (MPI_Datatype)(*datatype), *dest, *sendtag, *source, *recvtag, (MPI_Comm)(*comm), (MPI_Status*)status);
#else /* MPI-2 safe call */
    MPI_Status temp_status;
    MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_Sendrecv_replace((void*)buf, *count, MPI_Type_f2c(*datatype), *dest, *sendtag, *source, *recvtag, MPI_Comm_f2c(*comm), &temp_status);
    MPI_Status_c2f(&temp_status, status);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_SENDRECV_REPLACE(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *sendtag, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Sendrecv_replace_fortran_wrapper(buf, count, datatype, dest, sendtag, source, recvtag, comm, status, ierr);
}

_EXTERN_C_ void mpi_sendrecv_replace(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *sendtag, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Sendrecv_replace_fortran_wrapper(buf, count, datatype, dest, sendtag, source, recvtag, comm, status, ierr);
}

_EXTERN_C_ void mpi_sendrecv_replace_(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *sendtag, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Sendrecv_replace_fortran_wrapper(buf, count, datatype, dest, sendtag, source, recvtag, comm, status, ierr);
}

_EXTERN_C_ void mpi_sendrecv_replace__(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *sendtag, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Sendrecv_replace_fortran_wrapper(buf, count, datatype, dest, sendtag, source, recvtag, comm, status, ierr);
}

/* ================= End Wrappers for MPI_Sendrecv_replace ================= */


/* =============== Fortran Wrappers for MPI_Ssend =============== */
static void MPI_Ssend_fortran_wrapper(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Ssend((MPI_CONST void*)buf, *count, (MPI_Datatype)(*datatype), *dest, *tag, (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Ssend((MPI_CONST void*)buf, *count, MPI_Type_f2c(*datatype), *dest, *tag, MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_SSEND(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Ssend_fortran_wrapper(buf, count, datatype, dest, tag, comm, ierr);
}

_EXTERN_C_ void mpi_ssend(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Ssend_fortran_wrapper(buf, count, datatype, dest, tag, comm, ierr);
}

_EXTERN_C_ void mpi_ssend_(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Ssend_fortran_wrapper(buf, count, datatype, dest, tag, comm, ierr);
}

_EXTERN_C_ void mpi_ssend__(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Ssend_fortran_wrapper(buf, count, datatype, dest, tag, comm, ierr);
}

/* ================= End Wrappers for MPI_Ssend ================= */


/* =============== Fortran Wrappers for MPI_Ssend_init =============== */
static void MPI_Ssend_init_fortran_wrapper(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Ssend_init((MPI_CONST void*)buf, *count, (MPI_Datatype)(*datatype), *dest, *tag, (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Ssend_init((MPI_CONST void*)buf, *count, MPI_Type_f2c(*datatype), *dest, *tag, MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_SSEND_INIT(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ssend_init_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_ssend_init(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ssend_init_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_ssend_init_(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ssend_init_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_ssend_init__(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ssend_init_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Ssend_init ================= */


/* =============== Fortran Wrappers for MPI_Unpack =============== */
static void MPI_Unpack_fortran_wrapper(MPI_Fint *inbuf, MPI_Fint *insize, MPI_Fint *position, MPI_Fint *outbuf, MPI_Fint *outcount, MPI_Fint *datatype, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Unpack((MPI_CONST void*)inbuf, *insize, (int*)position, (void*)outbuf, *outcount, (MPI_Datatype)(*datatype), (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Unpack((MPI_CONST void*)inbuf, *insize, (int*)position, (void*)outbuf, *outcount, MPI_Type_f2c(*datatype), MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_UNPACK(MPI_Fint *inbuf, MPI_Fint *insize, MPI_Fint *position, MPI_Fint *outbuf, MPI_Fint *outcount, MPI_Fint *datatype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Unpack_fortran_wrapper(inbuf, insize, position, outbuf, outcount, datatype, comm, ierr);
}

_EXTERN_C_ void mpi_unpack(MPI_Fint *inbuf, MPI_Fint *insize, MPI_Fint *position, MPI_Fint *outbuf, MPI_Fint *outcount, MPI_Fint *datatype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Unpack_fortran_wrapper(inbuf, insize, position, outbuf, outcount, datatype, comm, ierr);
}

_EXTERN_C_ void mpi_unpack_(MPI_Fint *inbuf, MPI_Fint *insize, MPI_Fint *position, MPI_Fint *outbuf, MPI_Fint *outcount, MPI_Fint *datatype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Unpack_fortran_wrapper(inbuf, insize, position, outbuf, outcount, datatype, comm, ierr);
}

_EXTERN_C_ void mpi_unpack__(MPI_Fint *inbuf, MPI_Fint *insize, MPI_Fint *position, MPI_Fint *outbuf, MPI_Fint *outcount, MPI_Fint *datatype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Unpack_fortran_wrapper(inbuf, insize, position, outbuf, outcount, datatype, comm, ierr);
}

/* ================= End Wrappers for MPI_Unpack ================= */


/* =============== Fortran Wrappers for MPI_Win_create =============== */
static void MPI_Win_create_fortran_wrapper(MPI_Fint *base, MPI_Aint *size, MPI_Fint *disp_unit, MPI_Fint *info, MPI_Fint *comm, MPI_Fint *win, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Win_create((void*)base, *size, *disp_unit, (MPI_Info)(*info), (MPI_Comm)(*comm), (MPI_Win*)win);
#else /* MPI-2 safe call */
    MPI_Win temp_win;
    temp_win = MPI_Win_f2c(*win);
    _wrap_py_return_val = MPI_Win_create((void*)base, *size, *disp_unit, MPI_Info_f2c(*info), MPI_Comm_f2c(*comm), &temp_win);
    *win = MPI_Win_c2f(temp_win);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_WIN_CREATE(MPI_Fint *base, MPI_Aint *size, MPI_Fint *disp_unit, MPI_Fint *info, MPI_Fint *comm, MPI_Fint *win, MPI_Fint *ierr) { 
    MPI_Win_create_fortran_wrapper(base, size, disp_unit, info, comm, win, ierr);
}

_EXTERN_C_ void mpi_win_create(MPI_Fint *base, MPI_Aint *size, MPI_Fint *disp_unit, MPI_Fint *info, MPI_Fint *comm, MPI_Fint *win, MPI_Fint *ierr) { 
    MPI_Win_create_fortran_wrapper(base, size, disp_unit, info, comm, win, ierr);
}

_EXTERN_C_ void mpi_win_create_(MPI_Fint *base, MPI_Aint *size, MPI_Fint *disp_unit, MPI_Fint *info, MPI_Fint *comm, MPI_Fint *win, MPI_Fint *ierr) { 
    MPI_Win_create_fortran_wrapper(base, size, disp_unit, info, comm, win, ierr);
}

_EXTERN_C_ void mpi_win_create__(MPI_Fint *base, MPI_Aint *size, MPI_Fint *disp_unit, MPI_Fint *info, MPI_Fint *comm, MPI_Fint *win, MPI_Fint *ierr) { 
    MPI_Win_create_fortran_wrapper(base, size, disp_unit, info, comm, win, ierr);
}

/* ================= End Wrappers for MPI_Win_create ================= */


#ifndef K_COMPUTER

/* =============== Fortran Wrappers for MPI_Win_allocate =============== */
static void MPI_Win_allocate_fortran_wrapper(MPI_Aint *size, MPI_Fint *disp_unit, MPI_Fint *info, MPI_Fint *comm, MPI_Fint *baseptr, MPI_Fint *win, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Win_allocate(*size, *disp_unit, (MPI_Info)(*info), (MPI_Comm)(*comm), (void*)baseptr, (MPI_Win*)win);
#else /* MPI-2 safe call */
    MPI_Win temp_win;
    temp_win = MPI_Win_f2c(*win);
    _wrap_py_return_val = MPI_Win_allocate(*size, *disp_unit, MPI_Info_f2c(*info), MPI_Comm_f2c(*comm), (void*)baseptr, &temp_win);
    *win = MPI_Win_c2f(temp_win);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_WIN_ALLOCATE(MPI_Aint *size, MPI_Fint *disp_unit, MPI_Fint *info, MPI_Fint *comm, MPI_Fint *baseptr, MPI_Fint *win, MPI_Fint *ierr) { 
    MPI_Win_allocate_fortran_wrapper(size, disp_unit, info, comm, baseptr, win, ierr);
}

_EXTERN_C_ void mpi_win_allocate(MPI_Aint *size, MPI_Fint *disp_unit, MPI_Fint *info, MPI_Fint *comm, MPI_Fint *baseptr, MPI_Fint *win, MPI_Fint *ierr) { 
    MPI_Win_allocate_fortran_wrapper(size, disp_unit, info, comm, baseptr, win, ierr);
}

_EXTERN_C_ void mpi_win_allocate_(MPI_Aint *size, MPI_Fint *disp_unit, MPI_Fint *info, MPI_Fint *comm, MPI_Fint *baseptr, MPI_Fint *win, MPI_Fint *ierr) { 
    MPI_Win_allocate_fortran_wrapper(size, disp_unit, info, comm, baseptr, win, ierr);
}

_EXTERN_C_ void mpi_win_allocate__(MPI_Aint *size, MPI_Fint *disp_unit, MPI_Fint *info, MPI_Fint *comm, MPI_Fint *baseptr, MPI_Fint *win, MPI_Fint *ierr) { 
    MPI_Win_allocate_fortran_wrapper(size, disp_unit, info, comm, baseptr, win, ierr);
}

/* ================= End Wrappers for MPI_Win_allocate ================= */


/* =============== Fortran Wrappers for MPI_Win_allocate_shared =============== */
static void MPI_Win_allocate_shared_fortran_wrapper(MPI_Aint *size, MPI_Fint *disp_unit, MPI_Fint *info, MPI_Fint *comm, MPI_Fint *baseptr, MPI_Fint *win, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Win_allocate_shared(*size, *disp_unit, (MPI_Info)(*info), (MPI_Comm)(*comm), (void*)baseptr, (MPI_Win*)win);
#else /* MPI-2 safe call */
    MPI_Win temp_win;
    temp_win = MPI_Win_f2c(*win);
    _wrap_py_return_val = MPI_Win_allocate_shared(*size, *disp_unit, MPI_Info_f2c(*info), MPI_Comm_f2c(*comm), (void*)baseptr, &temp_win);
    *win = MPI_Win_c2f(temp_win);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_WIN_ALLOCATE_SHARED(MPI_Aint *size, MPI_Fint *disp_unit, MPI_Fint *info, MPI_Fint *comm, MPI_Fint *baseptr, MPI_Fint *win, MPI_Fint *ierr) { 
    MPI_Win_allocate_shared_fortran_wrapper(size, disp_unit, info, comm, baseptr, win, ierr);
}

_EXTERN_C_ void mpi_win_allocate_shared(MPI_Aint *size, MPI_Fint *disp_unit, MPI_Fint *info, MPI_Fint *comm, MPI_Fint *baseptr, MPI_Fint *win, MPI_Fint *ierr) { 
    MPI_Win_allocate_shared_fortran_wrapper(size, disp_unit, info, comm, baseptr, win, ierr);
}

_EXTERN_C_ void mpi_win_allocate_shared_(MPI_Aint *size, MPI_Fint *disp_unit, MPI_Fint *info, MPI_Fint *comm, MPI_Fint *baseptr, MPI_Fint *win, MPI_Fint *ierr) { 
    MPI_Win_allocate_shared_fortran_wrapper(size, disp_unit, info, comm, baseptr, win, ierr);
}

_EXTERN_C_ void mpi_win_allocate_shared__(MPI_Aint *size, MPI_Fint *disp_unit, MPI_Fint *info, MPI_Fint *comm, MPI_Fint *baseptr, MPI_Fint *win, MPI_Fint *ierr) { 
    MPI_Win_allocate_shared_fortran_wrapper(size, disp_unit, info, comm, baseptr, win, ierr);
}

/* ================= End Wrappers for MPI_Win_allocate_shared ================= */


/* =============== Fortran Wrappers for MPI_Win_create_dynamic =============== */
static void MPI_Win_create_dynamic_fortran_wrapper(MPI_Fint *info, MPI_Fint *comm, MPI_Fint *win, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Win_create_dynamic((MPI_Info)(*info), (MPI_Comm)(*comm), (MPI_Win*)win);
#else /* MPI-2 safe call */
    MPI_Win temp_win;
    temp_win = MPI_Win_f2c(*win);
    _wrap_py_return_val = MPI_Win_create_dynamic(MPI_Info_f2c(*info), MPI_Comm_f2c(*comm), &temp_win);
    *win = MPI_Win_c2f(temp_win);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_WIN_CREATE_DYNAMIC(MPI_Fint *info, MPI_Fint *comm, MPI_Fint *win, MPI_Fint *ierr) { 
    MPI_Win_create_dynamic_fortran_wrapper(info, comm, win, ierr);
}

_EXTERN_C_ void mpi_win_create_dynamic(MPI_Fint *info, MPI_Fint *comm, MPI_Fint *win, MPI_Fint *ierr) { 
    MPI_Win_create_dynamic_fortran_wrapper(info, comm, win, ierr);
}

_EXTERN_C_ void mpi_win_create_dynamic_(MPI_Fint *info, MPI_Fint *comm, MPI_Fint *win, MPI_Fint *ierr) { 
    MPI_Win_create_dynamic_fortran_wrapper(info, comm, win, ierr);
}

_EXTERN_C_ void mpi_win_create_dynamic__(MPI_Fint *info, MPI_Fint *comm, MPI_Fint *win, MPI_Fint *ierr) { 
    MPI_Win_create_dynamic_fortran_wrapper(info, comm, win, ierr);
}

/* ================= End Wrappers for MPI_Win_create_dynamic ================= */


/* =============== Fortran Wrappers for MPI_Comm_create_group =============== */
static void MPI_Comm_create_group_fortran_wrapper(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *tag, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_create_group((MPI_Comm)(*comm), (MPI_Group)(*group), *tag, (MPI_Comm*)newcomm);
#else /* MPI-2 safe call */
    MPI_Comm temp_newcomm;
    temp_newcomm = MPI_Comm_f2c(*newcomm);
    _wrap_py_return_val = MPI_Comm_create_group(MPI_Comm_f2c(*comm), MPI_Group_f2c(*group), *tag, &temp_newcomm);
    *newcomm = MPI_Comm_c2f(temp_newcomm);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_CREATE_GROUP(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *tag, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_create_group_fortran_wrapper(comm, group, tag, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_create_group(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *tag, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_create_group_fortran_wrapper(comm, group, tag, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_create_group_(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *tag, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_create_group_fortran_wrapper(comm, group, tag, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_create_group__(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *tag, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_create_group_fortran_wrapper(comm, group, tag, newcomm, ierr);
}

/* ================= End Wrappers for MPI_Comm_create_group ================= */


/* =============== Fortran Wrappers for MPI_Comm_dup_with_info =============== */
static void MPI_Comm_dup_with_info_fortran_wrapper(MPI_Fint *comm, MPI_Fint *info, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_dup_with_info((MPI_Comm)(*comm), (MPI_Info)(*info), (MPI_Comm*)newcomm);
#else /* MPI-2 safe call */
    MPI_Comm temp_newcomm;
    temp_newcomm = MPI_Comm_f2c(*newcomm);
    _wrap_py_return_val = MPI_Comm_dup_with_info(MPI_Comm_f2c(*comm), MPI_Info_f2c(*info), &temp_newcomm);
    *newcomm = MPI_Comm_c2f(temp_newcomm);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_DUP_WITH_INFO(MPI_Fint *comm, MPI_Fint *info, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_dup_with_info_fortran_wrapper(comm, info, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_dup_with_info(MPI_Fint *comm, MPI_Fint *info, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_dup_with_info_fortran_wrapper(comm, info, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_dup_with_info_(MPI_Fint *comm, MPI_Fint *info, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_dup_with_info_fortran_wrapper(comm, info, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_dup_with_info__(MPI_Fint *comm, MPI_Fint *info, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_dup_with_info_fortran_wrapper(comm, info, newcomm, ierr);
}

/* ================= End Wrappers for MPI_Comm_dup_with_info ================= */


/* =============== Fortran Wrappers for MPI_Comm_get_info =============== */
static void MPI_Comm_get_info_fortran_wrapper(MPI_Fint *comm, MPI_Fint *info_used, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_get_info((MPI_Comm)(*comm), (MPI_Info*)info_used);
#else /* MPI-2 safe call */
    MPI_Info temp_info_used;
    temp_info_used = MPI_Info_f2c(*info_used);
    _wrap_py_return_val = MPI_Comm_get_info(MPI_Comm_f2c(*comm), &temp_info_used);
    *info_used = MPI_Info_c2f(temp_info_used);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_GET_INFO(MPI_Fint *comm, MPI_Fint *info_used, MPI_Fint *ierr) { 
    MPI_Comm_get_info_fortran_wrapper(comm, info_used, ierr);
}

_EXTERN_C_ void mpi_comm_get_info(MPI_Fint *comm, MPI_Fint *info_used, MPI_Fint *ierr) { 
    MPI_Comm_get_info_fortran_wrapper(comm, info_used, ierr);
}

_EXTERN_C_ void mpi_comm_get_info_(MPI_Fint *comm, MPI_Fint *info_used, MPI_Fint *ierr) { 
    MPI_Comm_get_info_fortran_wrapper(comm, info_used, ierr);
}

_EXTERN_C_ void mpi_comm_get_info__(MPI_Fint *comm, MPI_Fint *info_used, MPI_Fint *ierr) { 
    MPI_Comm_get_info_fortran_wrapper(comm, info_used, ierr);
}

/* ================= End Wrappers for MPI_Comm_get_info ================= */


/* =============== Fortran Wrappers for MPI_Comm_idup =============== */
static void MPI_Comm_idup_fortran_wrapper(MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_idup((MPI_Comm)(*comm), (MPI_Comm*)newcomm, (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    MPI_Comm temp_newcomm;
    temp_newcomm = MPI_Comm_f2c(*newcomm);
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Comm_idup(MPI_Comm_f2c(*comm), &temp_newcomm, &temp_request);
    *newcomm = MPI_Comm_c2f(temp_newcomm);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_IDUP(MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Comm_idup_fortran_wrapper(comm, newcomm, request, ierr);
}

_EXTERN_C_ void mpi_comm_idup(MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Comm_idup_fortran_wrapper(comm, newcomm, request, ierr);
}

_EXTERN_C_ void mpi_comm_idup_(MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Comm_idup_fortran_wrapper(comm, newcomm, request, ierr);
}

_EXTERN_C_ void mpi_comm_idup__(MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Comm_idup_fortran_wrapper(comm, newcomm, request, ierr);
}

/* ================= End Wrappers for MPI_Comm_idup ================= */


/* =============== Fortran Wrappers for MPI_Comm_set_info =============== */
static void MPI_Comm_set_info_fortran_wrapper(MPI_Fint *comm, MPI_Fint *info, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_set_info((MPI_Comm)(*comm), (MPI_Info)(*info));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Comm_set_info(MPI_Comm_f2c(*comm), MPI_Info_f2c(*info));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_SET_INFO(MPI_Fint *comm, MPI_Fint *info, MPI_Fint *ierr) { 
    MPI_Comm_set_info_fortran_wrapper(comm, info, ierr);
}

_EXTERN_C_ void mpi_comm_set_info(MPI_Fint *comm, MPI_Fint *info, MPI_Fint *ierr) { 
    MPI_Comm_set_info_fortran_wrapper(comm, info, ierr);
}

_EXTERN_C_ void mpi_comm_set_info_(MPI_Fint *comm, MPI_Fint *info, MPI_Fint *ierr) { 
    MPI_Comm_set_info_fortran_wrapper(comm, info, ierr);
}

_EXTERN_C_ void mpi_comm_set_info__(MPI_Fint *comm, MPI_Fint *info, MPI_Fint *ierr) { 
    MPI_Comm_set_info_fortran_wrapper(comm, info, ierr);
}

/* ================= End Wrappers for MPI_Comm_set_info ================= */


/* =============== Fortran Wrappers for MPI_Comm_split_type =============== */
static void MPI_Comm_split_type_fortran_wrapper(MPI_Fint *comm, MPI_Fint *split_type, MPI_Fint *key, MPI_Fint *info, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_split_type((MPI_Comm)(*comm), *split_type, *key, (MPI_Info)(*info), (MPI_Comm*)newcomm);
#else /* MPI-2 safe call */
    MPI_Comm temp_newcomm;
    temp_newcomm = MPI_Comm_f2c(*newcomm);
    _wrap_py_return_val = MPI_Comm_split_type(MPI_Comm_f2c(*comm), *split_type, *key, MPI_Info_f2c(*info), &temp_newcomm);
    *newcomm = MPI_Comm_c2f(temp_newcomm);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_SPLIT_TYPE(MPI_Fint *comm, MPI_Fint *split_type, MPI_Fint *key, MPI_Fint *info, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_split_type_fortran_wrapper(comm, split_type, key, info, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_split_type(MPI_Fint *comm, MPI_Fint *split_type, MPI_Fint *key, MPI_Fint *info, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_split_type_fortran_wrapper(comm, split_type, key, info, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_split_type_(MPI_Fint *comm, MPI_Fint *split_type, MPI_Fint *key, MPI_Fint *info, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_split_type_fortran_wrapper(comm, split_type, key, info, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_split_type__(MPI_Fint *comm, MPI_Fint *split_type, MPI_Fint *key, MPI_Fint *info, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_split_type_fortran_wrapper(comm, split_type, key, info, newcomm, ierr);
}

/* ================= End Wrappers for MPI_Comm_split_type ================= */


/* =============== Fortran Wrappers for MPI_Neighbor_allgather =============== */
static void MPI_Neighbor_allgather_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Neighbor_allgather((MPI_CONST void*)sendbuf, *sendcount, (MPI_Datatype)(*sendtype), (void*)recvbuf, *recvcount, (MPI_Datatype)(*recvtype), (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Neighbor_allgather((MPI_CONST void*)sendbuf, *sendcount, MPI_Type_f2c(*sendtype), (void*)recvbuf, *recvcount, MPI_Type_f2c(*recvtype), MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_NEIGHBOR_ALLGATHER(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Neighbor_allgather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_neighbor_allgather(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Neighbor_allgather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_neighbor_allgather_(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Neighbor_allgather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_neighbor_allgather__(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Neighbor_allgather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}

/* ================= End Wrappers for MPI_Neighbor_allgather ================= */


/* =============== Fortran Wrappers for MPI_Ineighbor_allgatherv =============== */
static void MPI_Ineighbor_allgatherv_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint displs[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Ineighbor_allgatherv((MPI_CONST void*)sendbuf, *sendcount, (MPI_Datatype)(*sendtype), (void*)recvbuf, (MPI_CONST int*)recvcounts, (MPI_CONST int*)displs, (MPI_Datatype)(*recvtype), (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Ineighbor_allgatherv((MPI_CONST void*)sendbuf, *sendcount, MPI_Type_f2c(*sendtype), (void*)recvbuf, (MPI_CONST int*)recvcounts, (MPI_CONST int*)displs, MPI_Type_f2c(*recvtype), MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_INEIGHBOR_ALLGATHERV(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint displs[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ineighbor_allgatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request, ierr);
}

_EXTERN_C_ void mpi_ineighbor_allgatherv(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint displs[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ineighbor_allgatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request, ierr);
}

_EXTERN_C_ void mpi_ineighbor_allgatherv_(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint displs[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ineighbor_allgatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request, ierr);
}

_EXTERN_C_ void mpi_ineighbor_allgatherv__(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint displs[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ineighbor_allgatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Ineighbor_allgatherv ================= */


/* =============== Fortran Wrappers for MPI_Ineighbor_allgather =============== */
static void MPI_Ineighbor_allgather_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Ineighbor_allgather((MPI_CONST void*)sendbuf, *sendcount, (MPI_Datatype)(*sendtype), (void*)recvbuf, *recvcount, (MPI_Datatype)(*recvtype), (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Ineighbor_allgather((MPI_CONST void*)sendbuf, *sendcount, MPI_Type_f2c(*sendtype), (void*)recvbuf, *recvcount, MPI_Type_f2c(*recvtype), MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_INEIGHBOR_ALLGATHER(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ineighbor_allgather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}

_EXTERN_C_ void mpi_ineighbor_allgather(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ineighbor_allgather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}

_EXTERN_C_ void mpi_ineighbor_allgather_(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ineighbor_allgather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}

_EXTERN_C_ void mpi_ineighbor_allgather__(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ineighbor_allgather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Ineighbor_allgather ================= */


/* =============== Fortran Wrappers for MPI_Ineighbor_alltoall =============== */
static void MPI_Ineighbor_alltoall_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Ineighbor_alltoall((MPI_CONST void*)sendbuf, *sendcount, (MPI_Datatype)(*sendtype), (void*)recvbuf, *recvcount, (MPI_Datatype)(*recvtype), (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Ineighbor_alltoall((MPI_CONST void*)sendbuf, *sendcount, MPI_Type_f2c(*sendtype), (void*)recvbuf, *recvcount, MPI_Type_f2c(*recvtype), MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_INEIGHBOR_ALLTOALL(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ineighbor_alltoall_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}

_EXTERN_C_ void mpi_ineighbor_alltoall(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ineighbor_alltoall_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}

_EXTERN_C_ void mpi_ineighbor_alltoall_(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ineighbor_alltoall_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}

_EXTERN_C_ void mpi_ineighbor_alltoall__(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ineighbor_alltoall_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Ineighbor_alltoall ================= */


/* =============== Fortran Wrappers for MPI_Ineighbor_alltoallv =============== */
static void MPI_Ineighbor_alltoallv_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Ineighbor_alltoallv((MPI_CONST void*)sendbuf, (MPI_CONST int*)sendcounts, (MPI_CONST int*)sdispls, (MPI_Datatype)(*sendtype), (void*)recvbuf, (MPI_CONST int*)recvcounts, (MPI_CONST int*)rdispls, (MPI_Datatype)(*recvtype), (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Ineighbor_alltoallv((MPI_CONST void*)sendbuf, (MPI_CONST int*)sendcounts, (MPI_CONST int*)sdispls, MPI_Type_f2c(*sendtype), (void*)recvbuf, (MPI_CONST int*)recvcounts, (MPI_CONST int*)rdispls, MPI_Type_f2c(*recvtype), MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_INEIGHBOR_ALLTOALLV(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ineighbor_alltoallv_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request, ierr);
}

_EXTERN_C_ void mpi_ineighbor_alltoallv(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ineighbor_alltoallv_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request, ierr);
}

_EXTERN_C_ void mpi_ineighbor_alltoallv_(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ineighbor_alltoallv_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request, ierr);
}

_EXTERN_C_ void mpi_ineighbor_alltoallv__(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ineighbor_alltoallv_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Ineighbor_alltoallv ================= */


/* =============== Fortran Wrappers for MPI_Ineighbor_alltoallw =============== */
static void MPI_Ineighbor_alltoallw_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint sendtypes[], MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint recvtypes[], MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Ineighbor_alltoallw((MPI_CONST void*)sendbuf, (MPI_CONST int*)sendcounts, (MPI_CONST MPI_Aint*)sdispls, (MPI_CONST MPI_Datatype*)sendtypes, (void*)recvbuf, (MPI_CONST int*)recvcounts, (MPI_CONST MPI_Aint*)rdispls, (MPI_CONST MPI_Datatype*)recvtypes, (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Ineighbor_alltoallw((MPI_CONST void*)sendbuf, (MPI_CONST int*)sendcounts, (MPI_CONST MPI_Aint*)sdispls, (MPI_CONST MPI_Datatype*)sendtypes, (void*)recvbuf, (MPI_CONST int*)recvcounts, (MPI_CONST MPI_Aint*)rdispls, (MPI_CONST MPI_Datatype*)recvtypes, MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_INEIGHBOR_ALLTOALLW(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint sendtypes[], MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint recvtypes[], MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ineighbor_alltoallw_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request, ierr);
}

_EXTERN_C_ void mpi_ineighbor_alltoallw(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint sendtypes[], MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint recvtypes[], MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ineighbor_alltoallw_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request, ierr);
}

_EXTERN_C_ void mpi_ineighbor_alltoallw_(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint sendtypes[], MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint recvtypes[], MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ineighbor_alltoallw_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request, ierr);
}

_EXTERN_C_ void mpi_ineighbor_alltoallw__(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint sendtypes[], MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint recvtypes[], MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ineighbor_alltoallw_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Ineighbor_alltoallw ================= */


/* =============== Fortran Wrappers for MPI_Neighbor_allgatherv =============== */
static void MPI_Neighbor_allgatherv_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint displs[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Neighbor_allgatherv((MPI_CONST void*)sendbuf, *sendcount, (MPI_Datatype)(*sendtype), (void*)recvbuf, (MPI_CONST int*)recvcounts, (MPI_CONST int*)displs, (MPI_Datatype)(*recvtype), (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Neighbor_allgatherv((MPI_CONST void*)sendbuf, *sendcount, MPI_Type_f2c(*sendtype), (void*)recvbuf, (MPI_CONST int*)recvcounts, (MPI_CONST int*)displs, MPI_Type_f2c(*recvtype), MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_NEIGHBOR_ALLGATHERV(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint displs[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Neighbor_allgatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_neighbor_allgatherv(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint displs[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Neighbor_allgatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_neighbor_allgatherv_(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint displs[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Neighbor_allgatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_neighbor_allgatherv__(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint displs[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Neighbor_allgatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierr);
}

/* ================= End Wrappers for MPI_Neighbor_allgatherv ================= */


/* =============== Fortran Wrappers for MPI_Neighbor_alltoall =============== */
static void MPI_Neighbor_alltoall_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Neighbor_alltoall((MPI_CONST void*)sendbuf, *sendcount, (MPI_Datatype)(*sendtype), (void*)recvbuf, *recvcount, (MPI_Datatype)(*recvtype), (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Neighbor_alltoall((MPI_CONST void*)sendbuf, *sendcount, MPI_Type_f2c(*sendtype), (void*)recvbuf, *recvcount, MPI_Type_f2c(*recvtype), MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_NEIGHBOR_ALLTOALL(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Neighbor_alltoall_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_neighbor_alltoall(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Neighbor_alltoall_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_neighbor_alltoall_(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Neighbor_alltoall_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_neighbor_alltoall__(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Neighbor_alltoall_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}

/* ================= End Wrappers for MPI_Neighbor_alltoall ================= */


/* =============== Fortran Wrappers for MPI_Neighbor_alltoallv =============== */
static void MPI_Neighbor_alltoallv_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Neighbor_alltoallv((MPI_CONST void*)sendbuf, (MPI_CONST int*)sendcounts, (MPI_CONST int*)sdispls, (MPI_Datatype)(*sendtype), (void*)recvbuf, (MPI_CONST int*)recvcounts, (MPI_CONST int*)rdispls, (MPI_Datatype)(*recvtype), (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Neighbor_alltoallv((MPI_CONST void*)sendbuf, (MPI_CONST int*)sendcounts, (MPI_CONST int*)sdispls, MPI_Type_f2c(*sendtype), (void*)recvbuf, (MPI_CONST int*)recvcounts, (MPI_CONST int*)rdispls, MPI_Type_f2c(*recvtype), MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_NEIGHBOR_ALLTOALLV(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Neighbor_alltoallv_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_neighbor_alltoallv(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Neighbor_alltoallv_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_neighbor_alltoallv_(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Neighbor_alltoallv_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_neighbor_alltoallv__(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Neighbor_alltoallv_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierr);
}

/* ================= End Wrappers for MPI_Neighbor_alltoallv ================= */


/* =============== Fortran Wrappers for MPI_Neighbor_alltoallw =============== */
static void MPI_Neighbor_alltoallw_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint sendtypes[], MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint recvtypes[], MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Neighbor_alltoallw((MPI_CONST void*)sendbuf, (MPI_CONST int*)sendcounts, (MPI_CONST MPI_Aint*)sdispls, (MPI_CONST MPI_Datatype*)sendtypes, (void*)recvbuf, (MPI_CONST int*)recvcounts, (MPI_CONST MPI_Aint*)rdispls, (MPI_CONST MPI_Datatype*)recvtypes, (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Neighbor_alltoallw((MPI_CONST void*)sendbuf, (MPI_CONST int*)sendcounts, (MPI_CONST MPI_Aint*)sdispls, (MPI_CONST MPI_Datatype*)sendtypes, (void*)recvbuf, (MPI_CONST int*)recvcounts, (MPI_CONST MPI_Aint*)rdispls, (MPI_CONST MPI_Datatype*)recvtypes, MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_NEIGHBOR_ALLTOALLW(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint sendtypes[], MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint recvtypes[], MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Neighbor_alltoallw_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierr);
}

_EXTERN_C_ void mpi_neighbor_alltoallw(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint sendtypes[], MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint recvtypes[], MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Neighbor_alltoallw_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierr);
}

_EXTERN_C_ void mpi_neighbor_alltoallw_(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint sendtypes[], MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint recvtypes[], MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Neighbor_alltoallw_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierr);
}

_EXTERN_C_ void mpi_neighbor_alltoallw__(MPI_Fint *sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint sendtypes[], MPI_Fint *recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint recvtypes[], MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Neighbor_alltoallw_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierr);
}

/* ================= End Wrappers for MPI_Neighbor_alltoallw ================= */

#endif

