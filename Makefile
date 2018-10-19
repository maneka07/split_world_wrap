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
	$(CC) -ggdb -shared -Wl,-soname,libdtfwrap.so -o libdtfwrap.so *.o
#	$(CC) -ggdb -shared -Wl,-soname,libdtfwrap.so.1 -o libdtfwrap.so.1.0 *.o
#	ln -sf ./libdtfwrap.so.1.0 ./libdtfwrap.so.1
#	ln -sf ./libdtfwrap.so.1.0 ./libdtfwrap.so

%.o: %.c
	$(CC) -fPIC -c $< $(CFLAGS)

clean:
	rm -f $(OBJ) $(SNAME) $(DNAME)
