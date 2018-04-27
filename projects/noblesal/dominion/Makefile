CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

unittestresult.out: dominion.o unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c
	rm -f unittestresult.out
	# echo "unittest1.c:" > unittestresult.out
	# gcc -o unittest1 unittest1.c dominion.o rngs.o -g $(CFLAGS)
	# ./unittest1 >> unittestresult.out
	# gcov -f dominion.c >> unittestresult.out
	#
	# echo "unittest2.c:" >> unittestresult.out
	# gcc -o unittest2 unittest2.c dominion.o rngs.o -g $(CFLAGS)
	# ./unittest2  >> unittestresult.out
	# gcov -f dominion.c >> unittestresult.out
	# cat unittestresult.out | more
	#
	# echo "unittest3.c:" >> unittestresult.out
	# gcc -o unittest3 unittest3.c dominion.o rngs.o -g $(CFLAGS)
	# ./unittest3  >> unittestresult.out
	# gcov -f dominion.c >> unittestresult.out
	#
	# echo "unittest4.c:" >> unittestresult.out
	# gcc -o unittest4 unittest4.c dominion.o rngs.o -g $(CFLAGS)
	# ./unittest4  >> unittestresult.out
	# gcov -f dominion.c >> unittestresult.out

	echo "cardtest1.c:" > unittestresult.out
	gcc -o cardtest1 cardtest1.c dominion.o rngs.o -g $(CFLAGS)
	./cardtest1 >> unittestresult.out
	gcov -f dominion.c >> unittestresult.out
	#
	# echo "cardtest2.c:" >> unittestresult.out
	# gcc -o cardtest2 cardtest2.c dominion.o rngs.o -g $(CFLAGS)
	# ./cardtest2  >> unittestresult.out
	# gcov -f dominion.c >> unittestresult.out
	# cat unittestresult.out | more
	#
	# echo "cardtest3.c:" >> unittestresult.out
	# gcc -o cardtest3 cardtest3.c dominion.o rngs.o -g $(CFLAGS)
	# ./cardtest3  >> unittestresult.out
	# gcov -f dominion.c >> unittestresult.out
	#
	# echo "cardtest4.c:" >> unittestresult.out
	# gcc -o cardtest4 cardtest4.c dominion.o rngs.o -g $(CFLAGS)
	# ./cardtest4  >> unittestresult.out
	# gcov -f dominion.c >> unittestresult.out



player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe unittest1 unittest2 unittest3
