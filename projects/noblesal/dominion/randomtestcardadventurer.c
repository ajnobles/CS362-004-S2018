/// 1288
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
#define NUM_TEST 10000

const int HAND_COUNT_CHANGE = 2;
const int DECK_COUNT_CHANGE = 0;

int testHelper(struct gameState *g, struct gameState *test);

int main (int argc, char *argv[])
{

    int card = adventurer,
        choice1 = 0,
        choice2 = 0,
        choice3 = 0,
        handPos = 0,
        bonus = 0,
        numPlayers = 2,
        currentPlayer,
        seed = 1000,
        retVal,
        retValTest,
        cardCount,
        testCardCount,
        passed;

    int i, numTest = 0, numTestPassed = 0;

    int kingdomCards[10] = {adventurer, smithy, gardens, village, council_room, minion, steward, great_hall, tribute, ambassador};

    struct gameState BASE, G, testG;
    initializeGame(numPlayers, kingdomCards, seed, &BASE);

    srand(seed);

    for (i = 0; i < NUM_TEST; i++) {
        memcpy(&G, &BASE, sizeof(struct gameState));

        if (i % SET_DECK_TO_ZERO == 0) {
            G.deckCount[currentPlayer] = 0;
			G.discardCount[currentPlayer] = 5;
			G.discard[currentPlayer][0] = copper;
			G.discard[currentPlayer][1] = copper;
			G.discard[currentPlayer][2] = kingdomCards[rand() % 10];
			G.discard[currentPlayer][3] = kingdomCards[rand() % 10];
			G.discard[currentPlayer][4] = kingdomCards[rand() % 10];
        }

        if (i % SET_HAND_TO_ZERO == 0) {
            G.handCount[currentPlayer] = 0;
        }

        currentPlayer = rand() % numPlayers;
        retVal = 0;
        G.whoseTurn = currentPlayer;
		handPos = 0;
		G.hand[currentPlayer][handPos];
        memcpy(&testG, &G, sizeof(struct gameState));

        retValTest = adventurerRefactor(card, choice1, choice2, choice3, &testG, handPos, &bonus);

        passed = assertInt(retVal, retValTest);
       
		// TEST HAND COUNT
		if (passed) {
		    passed = assertInt(G.handCount[currentPlayer] + HAND_COUNT_CHANGE, testG.handCount[currentPlayer]);
		}

		// TEST TOTAL CARD COUNT
		if (passed) {
		    cardCount = 0;
			cardCount += G.handCount[currentPlayer];
			cardCount += G.deckCount[currentPlayer];
			cardCount += G.discardCount[currentPlayer];

			testCardCount = 0;
			testCardCount += testG.handCount[currentPlayer];
			testCardCount += testG.deckCount[currentPlayer];
			testCardCount += testG.discardCount[currentPlayer];
		}

        if (passed) numTestPassed++;

        if (!passed) {
            printf("\nFAILED: i: %i\tcurrentPlayer: %i\n", i, currentPlayer);
            printf("FAILED: retVal: %i\tretValTest: %i\n", retVal, retValTest);
            printf("FAILED: testG.handCount: %i\tG.handCount: %i\n", testG.handCount[currentPlayer], G.handCount[currentPlayer]);


    		cardCount = G.handCount[currentPlayer];
			cardCount += G.deckCount[currentPlayer];
			cardCount += G.discardCount[currentPlayer];

			testCardCount = testG.handCount[currentPlayer];
			testCardCount += testG.deckCount[currentPlayer];
			testCardCount += testG.discardCount[currentPlayer];
			
			printf("FAILED: testG Card Count: %i\tG Card Count: %i\n", cardCount, testCardCount);
   	    }

        numTest++;
    }




    for (i = 0; i < NUM_TEST; i++) {
        memcpy(&G, &BASE, sizeof(struct gameState));

        if (i % SET_DECK_TO_ZERO == 0) {
            G.deckCount[currentPlayer] = 0;
			G.discardCount[currentPlayer] = 5;
			G.discard[currentPlayer][0] = copper;
			G.discard[currentPlayer][1] = copper;
			G.discard[currentPlayer][2] = kingdomCards[rand() % 10];
			G.discard[currentPlayer][3] = kingdomCards[rand() % 10];
			G.discard[currentPlayer][4] = kingdomCards[rand() % 10];
        }

        if (i % SET_HAND_TO_ZERO == 0) {
            G.handCount[currentPlayer] = 0;
        }

        currentPlayer = rand() % numPlayers;
        retVal = 0;
        G.whoseTurn = currentPlayer;
        memcpy(&testG, &G, sizeof(struct gameState));

        retValTest = cardEffect(card, choice1, choice2, choice3, &testG, handPos, &bonus);

        passed = assertInt(retVal, retValTest);
       
		// TEST HAND COUNT
		if (passed) {
		    passed = assertInt(G.handCount[currentPlayer] + HAND_COUNT_CHANGE, testG.handCount[currentPlayer]);
		}

		// TEST TOTAL CARD COUNT
		if (passed) {
		    cardCount = 0;
			cardCount += G.handCount[currentPlayer];
			cardCount += G.deckCount[currentPlayer];
			cardCount += G.discardCount[currentPlayer];

			testCardCount = 0;
			testCardCount += testG.handCount[currentPlayer];
			testCardCount += testG.deckCount[currentPlayer];
			testCardCount += testG.discardCount[currentPlayer];
		}

        if (passed) numTestPassed++;

        if (!passed) {
            printf("\nFAILED: i: %i\tcurrentPlayer: %i\n", i, currentPlayer);
            printf("FAILED: retVal: %i\tretValTest: %i\n", retVal, retValTest);
            printf("FAILED: testG.handCount: %i\tG.handCount: %i\n", testG.handCount[currentPlayer], G.handCount[currentPlayer]);


    		cardCount = G.handCount[currentPlayer];
			cardCount += G.deckCount[currentPlayer];
			cardCount += G.discardCount[currentPlayer];

			testCardCount = testG.handCount[currentPlayer];
			testCardCount += testG.deckCount[currentPlayer];
			testCardCount += testG.discardCount[currentPlayer];
			
			printf("FAILED: testG Card Count: %i\tG Card Count: %i\n", cardCount, testCardCount);
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
