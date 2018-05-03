CFLAGS = -Wall -fpic -coverage -lm

all: testme.c
	gcc testme.c -o testme $(CFLAGS)

run: all
	./testme

clean:
	rm -f *.o testme
