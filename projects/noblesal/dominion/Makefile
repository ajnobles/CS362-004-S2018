CFLAGS = -Wall -fpic -coverage -lm

testFiles= cardtest1
testFilesDep= cardtest1.c

RESULTS="unittestresult.out"

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

unitTestResultsCompile: unittest*.c cardtest*.c assertTest.c assertTest.h
	gcc -o unittest1 unittest1.c assertTest.c dominion.o interface.o rngs.o -g $(CFLAGS)
	gcc -o unittest2 unittest2.c assertTest.c dominion.o interface.o rngs.o -g $(CFLAGS)
	gcc -o unittest3 unittest3.c assertTest.c dominion.o interface.o rngs.o -g $(CFLAGS)
	gcc -o unittest4 unittest4.c assertTest.c dominion.o interface.o rngs.o -g $(CFLAGS)
	gcc -o cardtest1 cardtest1.c assertTest.c dominion.o interface.o rngs.o -g $(CFLAGS)
	gcc -o cardtest2 cardtest2.c assertTest.c dominion.o interface.o rngs.o -g $(CFLAGS)
	gcc -o cardtest3 cardtest3.c assertTest.c dominion.o interface.o rngs.o -g $(CFLAGS)
	gcc -o cardtest4 cardtest4.c assertTest.c dominion.o interface.o rngs.o -g $(CFLAGS)

unittestresult.out: dominion.o interface.o unitTestResultsCompile
	rm -f $(RESULTS)
	echo > $(RESULTS)

	echo "unittest1.c: " >> $(RESULTS)
	./unittest1 >> $(RESULTS)

	echo >> $(RESULTS)
	echo "unittest2.c: " >> $(RESULTS)
	./unittest2 >> $(RESULTS)

	echo >> $(RESULTS)
	echo "unittest3.c: " >> $(RESULTS)
	./unittest3 >> $(RESULTS)

	echo >> $(RESULTS)
	echo "unittest4.c: " >> $(RESULTS)
	./unittest4 >> $(RESULTS)

	echo >> $(RESULTS)
	echo "cardtest1.c: " >> $(RESULTS)
	./cardtest1 >> $(RESULTS)

	echo >> $(RESULTS)
	echo "cardtest2.c: " >> $(RESULTS)
	./cardtest2 >> $(RESULTS)

	echo >> $(RESULTS)
	echo "cardtest3.c: " >> $(RESULTS)
	./cardtest3 >> $(RESULTS)

	echo >> $(RESULTS)
	echo "cardtest4.c: " >> $(RESULTS)
	./cardtest4 >> $(RESULTS)

	echo >> $(RESULTS)
	gcov dominion.c >> unittestresult.out
	gcov dominion.c

randomTestResultsCompile: randomtest*.c assertTest.c assertTest.h
		gcc -o randomtestcard1 randomtestcard1.c assertTest.c dominion.o interface.o rngs.o -g $(CFLAGS)
		gcc -o randomtestcard2 randomtestcard2.c assertTest.c dominion.o interface.o rngs.o -g $(CFLAGS)
		gcc -o randomtestcardadventurer randomtestcardadventurer.c assertTest.c dominion.o interface.o rngs.o -g $(CFLAGS)

randomtestresults: dominion.o interface.o randomTestResultsCompile
	rm -f randomtestcard1.out randomtestcard2.out randomtestcardadventurer.out

	./randomtestcard1 > randomtestcard1.out
	./randomtestcard2 > randomtestcard2.out
	./randomtestcardadventurer > randomtestcardadventurer.out
	gcov -f dominion.c >> randomtestcard1.out
	gcov -f dominion.c >> randomtestcard2.out
	gcov -f dominion.c >> randomtestcardadventurer.out
	gcov dominion.c

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestcard1 randomtestcard2 randomtestcardadventurer
