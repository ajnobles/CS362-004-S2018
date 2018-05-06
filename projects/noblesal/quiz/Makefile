CFLAGS = -Wall -fpic -coverage -lm

all: testme.c
	gcc testme.c -o testme $(CFLAGS)
	./testme

clean:
	rm -f *.o testme *.gcda *.gcno
