// VILLAGE 1344
#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include "rngs.h"

#include "assertTest.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define NUM_TEST 10000

const int HAND_COUNT_CHANGE = 1 - 1;
const int NUM_ACTIONS_CHANGE = 2;
const int PLAYED_CARDS_CHANGE = 1;

int main (int argc, char *argv[])
{

    int card = village,
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
        passed;

    int i, j, numTest = 0, numTestPassed = 0;

    int kingdomCards[10] = {adventurer, smithy, gardens, village, council_room, minion, steward, great_hall, tribute, ambassador};

    struct gameState G, testG;
    initializeGame(numPlayers, kingdomCards, seed, &G);
    // memcpy(&testG, &G, sizeof(struct gameState));

    srand(seed);

    for (i = 0; i < NUM_TEST; i++) {
		for (j = 0; j < NUM_TEST; j++) {
        memcpy(&testG, &G, sizeof(struct gameState));
        currentPlayer = rand() % numPlayers;
        retVal = 0;
        testG.whoseTurn = currentPlayer;


        // RUN FUNCTION
        retValTest = villageRefactor(card, choice1, choice2, choice3, &testG, handPos, &bonus);

        // TEST
        passed = assertInt(retVal, retValTest);

		if (passed) {
			passed = assertInt(G.handCount[currentPlayer]+HAND_COUNT_CHANGE,testG.handCount[currentPlayer]);
		}

		if (passed) {
			passed = assertInt(G.numActions + NUM_ACTIONS_CHANGE, testG.numActions);
		}

		if (passed) {
			passed = assertInt(G.playedCardCount + PLAYED_CARDS_CHANGE, testG.playedCardCount);
		}


        if (passed) numTestPassed++;

        if (!passed) {
            printf("\nFAILED: i: %i\tj: %i\tcurrentPlayer: %i\thandPos: %i\n", i, j, currentPlayer, handPos);
			printf("handCount - G: %i]ttestG: %i\n", G.handCount[currentPlayer] + HAND_COUNT_CHANGE, testG.handCount[currentPlayer]);
			printf("playedCardsCount - G: %i]ttestG: %i\n", G.playedCardCount + PLAYED_CARDS_CHANGE, testG.playedCardCount);
        }

        numTest++;
		}
    }

    printf("numTest: %i\tnumTestPassed: %i\n\n", numTest, numTestPassed);

	return 0;
}
