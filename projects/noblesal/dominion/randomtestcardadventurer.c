
#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include "rngs.h"

#include "assertTest.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define SET_DECK_TO_ZERO 10
#define SET_HAND_TO_ZERO 15
#define NUM_TEST 100

int testHelper(struct gameState *g, struct gameState *test);

int main (int argc, char *argv[])
{

    int card = adventurer,
        choice1 = 0,
        choice2 = 0,
        choice3 = 0,
        handPos = 0,
        bonus = 0,
        numPlayers = 3,
        currentPlayer,
        seed = 1000,
        retVal,
        retValTest,
        cardCount,
        testCardCount,
        passed;

    int i, numTest = 0, numTestPassed = 0;

    int kingdomCards[10] = {adventurer, smithy, gardens, village, council_room, minion, steward, great_hall, tribute, ambassador};

    struct gameState G, testG;
    initializeGame(numPlayers, kingdomCards, seed, &G);
    // memcpy(&testG, &G, sizeof(struct gameState));

    srand(seed);

    for (i = 0; i < NUM_TEST; i++) {
        memcpy(&testG, &G, sizeof(struct gameState));
        currentPlayer = rand() % numPlayers;
        retVal = 0;
        testG.whoseTurn = currentPlayer;


        if (i % SET_DECK_TO_ZERO == 0) {
            testG.deckCount[currentPlayer] = 0;
        }

        if (i % SET_HAND_TO_ZERO == 0) {
            // testG.handCount[currentPlayer] = 0;
        }

        retValTest = adventurerRefactor(card, choice1, choice2, choice3, &testG, handPos, &bonus);

        passed = assertInt(retVal, retValTest);

        if (passed) numTestPassed++;

        if (!passed) {
            printf("\nFAILED: i: %i\tcurrentPlayer: %i\n", i, currentPlayer);
            printf("FAILED: testG.handCount: %i\tG.handCount: %i\n", testG.handCount[currentPlayer], G.handCount[currentPlayer]);
            printf("FAILED: testG.deckCount: %i\tG.deckCount: %i\n", testG.deckCount[currentPlayer], G.deckCount[currentPlayer]);
            printf("FAILED: testG.discardCount: %i\tG.discardCount: %i\n", testG.discardCount[currentPlayer], G.discardCount[currentPlayer]);
        }

        numTest++;
    }

    printf("numTest: %i\tnumTestPassed: %i\n\n", numTest, numTestPassed);

    return 0;
}


int testHelper(struct gameState *G, struct gameState *testG)
{
	int passed = 0, handCount, testHandCount;

	int currentPlayer = whoseTurn(G);
	if (passed) {
	    handCount = 0;
		handCount += G->handCount[currentPlayer];
		handCount += G->deckCount[currentPlayer];
		handCount += G->discardCount[currentPlayer];
 
		testHandCount = 0;
		testHandCount += testG->handCount[currentPlayer];
		testHandCount += testG->deckCount[currentPlayer];
		testHandCount += testG->discardCount[currentPlayer];
		
		passed = assertInt(handCount, testHandCount);

	}
    return 1;
}
