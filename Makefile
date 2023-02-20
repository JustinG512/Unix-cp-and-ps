CC=gcc
CFLAGS=-I.
DEPS = TUps.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

TUps: TUps.o TUpsfunc.o
	$(CC) -o TUps TUps.o TUpsfunc.o

clean:
	rm TUps TUps.o TUpsfunc.o