// SMITHY 1324
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

const int HAND_CHANGE = 2;
const int PLAYED_CARDS_CHANGE = 1; 
const int DECK_CHANGE = -3;

int main (int argc, char *argv[])
{

    int card = smithy,
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

    int i, numTest = 0, numTestPassed = 0;

    int kingdomCards[10] = {adventurer, smithy, gardens, village, council_room, minion, steward, great_hall, tribute, ambassador};

    struct gameState G, testG;
    initializeGame(numPlayers, kingdomCards, seed, &G);
    // memcpy(&testG, &G, sizeof(struct gameState));

    srand(seed);

    for (i = 0; i < NUM_TEST; i++) {
        currentPlayer = rand() % numPlayers;
        memcpy(&testG, &G, sizeof(struct gameState));
        retVal = 0;
        testG.whoseTurn = currentPlayer;
        handPos = rand() % 2;
        // printf("handPos: %i\n", handPos);

        // RUN FUNCTION
        retValTest = smithyRefactor(card, choice1, choice2, choice3, &testG, handPos, &bonus);

        // TEST
        passed = assertInt(retVal, retValTest);

        if (passed) {
            passed = assertInt(testG.handCount[currentPlayer], G.handCount[currentPlayer]+HAND_CHANGE);
		}

        if (passed) {
            passed = assertInt(testG.playedCardCount, G.playedCardCount+PLAYED_CARDS_CHANGE);
        }

        if (passed) {
            passed = assertInt(testG.deckCount[currentPlayer], G.deckCount[currentPlayer] + DECK_CHANGE);
        }

        if (passed) numTestPassed++;

        else {
            printf("\nFAILED: i: %i\tcurrentPlayer: %i\thandPos: %i\n", i, currentPlayer, handPos);
				
			printf("handCount - G: %i\ttestG: %i\n", G.handCount[currentPlayer]+HAND_CHANGE,testG.handCount[currentPlayer]);
			printf("playedCardCount - G: %i\ttestG: %i\n", G.playedCardCount+PLAYED_CARDS_CHANGE,testG.playedCardCount);
			printf("deckCount - G: %i\ttestG: %i\n", G.deckCount[currentPlayer]+DECK_CHANGE,testG.deckCount[currentPlayer]);
        }

        numTest++;
    }

    printf("numTest: %i\tnumTestPassed: %i\n\n", numTest, numTestPassed);

	return 0;
}
