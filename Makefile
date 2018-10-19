DNAME=libsplitworld.so
SNAME=libsplitworld.a
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

CFLAGS=-Wall -ggdb -Wno-comment -pedantic
CC=mpicc

all: $(SNAME) $(DNAME) 

$(SNAME): $(OBJ)
	ar rcs $(SNAME) $(OBJ)
	ranlib $(SNAME)

$(DNAME): $(OBJ)
	$(CC) -ggdb -shared -Wl,-soname,$(DNAME) -o $(DNAME) *.o
#	$(CC) -ggdb -shared -Wl,-soname,$(DNAME).1 -o $(DNAME).1.0 *.o
#	ln -sf ./$(DNAME).1.0 ./$(DNAME).1
#	ln -sf ./$(DNAME).1.0 ./$(DNAME)

%.o: %.c
	$(CC) -fPIC -c $< $(CFLAGS)

clean:
	rm -f $(OBJ) $(SNAME) $(DNAME)
