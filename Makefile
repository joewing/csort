
CC=gcc
LD=gcc
CFLAGS=-O2 -Wall
LDFLAGS=

OBJECTS=main.o \
   bubble.o \
   heap.o \
   insert.o \
   merge.o \
   quick.o \
   radix.o \
   select.o \
   shell.o

csort: $(OBJECTS)
	$(LD) $(LDFLAGS) -o csort $(OBJECTS)

.c.o: $*.c
	$(CC) $(CFLAGS) -c $*.c

clean:
	rm -f $(OBJECTS) csort

