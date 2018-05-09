
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

    for (i = 0; i < 1000; i++) {
        memcpy(&testG, &G, sizeof(struct gameState));
        currentPlayer = rand() % numPlayers;
        retVal = 0;
        testG.whoseTurn = currentPlayer;


        if (i % SET_DECK_TO_ZERO == 0) {
            testG.deckCount[currentPlayer] = 0;
        }

        if (i % SET_HAND_TO_ZERO == 0) {
            testG.handCount[currentPlayer] = 0;
        }

        retValTest = adventurerRefactor(card, choice1, choice2, choice3, &testG, handPos, &bonus);

        passed = assertInt(retVal, retValTest);

	if (i % SET_DECK_TO_ZERO == 0 && i % SET_HAND_TO_ZERO == 0) {
	    
	}

	else if (i % SET_DECK_TO_ZERO == 0) {

	}

	else if (i % SET_HAND_TO_ZERO == 0) {

	    if (passed) {
                passed = assertInt(testG.handCount[currentPlayer], G.handCount[currentPlayer] + 2);
	    }

	    if (passed) {
                testCardCount = testG.handCount[currentPlayer];
                testCardCount += testG.deckCount[currentPlayer];
                testCardCount += testG.discardCount[currentPlayer];

                cardCount = G.handCount[currentPlayer];
                cardCount += G.deckCount[currentPlayer];
                cardCount += G.discardCount[currentPlayer];

                passed = assertInt(cardCount, testCardCount);
	    }

	    if (passed) {
                testCardCount += testG.deckCount[currentPlayer];
                testCardCount += testG.discardCount[currentPlayer];
        
                cardCount += G.deckCount[currentPlayer];
                cardCount += G.discardCount[currentPlayer];
        
                passed = assertInt(cardCount - 2, testCardCount);
	    }

	} 

	else {

	    if (passed) {
                passed = assertInt(testG.handCount[currentPlayer], G.handCount[currentPlayer] + 2);
	    }

	    if (passed) {
                testCardCount = testG.handCount[currentPlayer];
                testCardCount += testG.deckCount[currentPlayer];
                testCardCount += testG.discardCount[currentPlayer];

                cardCount = G.handCount[currentPlayer];
                cardCount += G.deckCount[currentPlayer];
                cardCount += G.discardCount[currentPlayer];

                passed = assertInt(cardCount, testCardCount);
	    }

	    if (passed) {
                testCardCount += testG.deckCount[currentPlayer];
                testCardCount += testG.discardCount[currentPlayer];
        
                cardCount += G.deckCount[currentPlayer];
                cardCount += G.discardCount[currentPlayer];
        
                passed = assertInt(cardCount - 2, testCardCount);
	    }

	}


        /*
        if (passed) {

            if (i % SET_HAND_TO_ZERO == 0) {
                passed = assertInt(testG.handCount[currentPlayer], 2);
            }

            else if (i % SET_DECK_TO_ZERO == 0) {
                passed = assertInt(testG.handCount[currentPlayer], 2);
            }

            else {
                passed = assertInt(testG.handCount[currentPlayer], G.handCount[currentPlayer] + 2);
            }
        }

        if (passed) {

            if (i % SET_HAND_TO_ZERO == 0) {
                testCardCount = testG.handCount[currentPlayer];
                testCardCount += testG.deckCount[currentPlayer];
                testCardCount += testG.discardCount[currentPlayer];

                cardCount = G.handCount[currentPlayer];
                cardCount += G.deckCount[currentPlayer];
                cardCount += G.discardCount[currentPlayer];

                passed = assertInt(cardCount, testCardCount);
            }

            else {
                testCardCount = testG.handCount[currentPlayer];
                testCardCount += testG.deckCount[currentPlayer];
                testCardCount += testG.discardCount[currentPlayer];

                cardCount = G.handCount[currentPlayer];
                cardCount += G.deckCount[currentPlayer];
                cardCount += G.discardCount[currentPlayer];

                passed = assertInt(cardCount, testCardCount);
            }
        }*/

        // if (passed) {
        //     testCardCount += testG.deckCount[currentPlayer];
        //     testCardCount += testG.discardCount[currentPlayer];
        //
        //     cardCount += G.deckCount[currentPlayer];
        //     cardCount += G.discardCount[currentPlayer];
        //
        //     passed = assertInt(cardCount - 2, testCardCount);
        // }

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
