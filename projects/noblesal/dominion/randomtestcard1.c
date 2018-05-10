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

#define NUM_TEST 1

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
        cardCount,
        testCardCount,
        passed;

    int i, j, numTest = 0, numTestPassed = 0;

    int kingdomCards[10] = {adventurer, smithy, gardens, village, council_room, minion, steward, great_hall, tribute, ambassador};

    struct gameState G, testG;
    initializeGame(numPlayers, kingdomCards, seed, &G);
    // memcpy(&testG, &G, sizeof(struct gameState));

    srand(seed);

    for (i = 0; i < NUM_TEST; i++) {
        for (j = 0; j < NUM_TEST; j++) {
            currentPlayer = rand() % numPlayers;
            memcpy(&testG, &G, sizeof(struct gameState));
            retVal = 0;
            testG.whoseTurn = currentPlayer;
            handPos = j % 2;
            printf("handPos: %i\n", handPos);


            // RUN FUNCTION
            retValTest = smithyRefactor(card, choice1, choice2, choice3, &testG, handPos, &bonus);

            // TEST
            passed = assertInt(retVal, retValTest);

            if (passed) {
                passed = assertInt(testG.handCount[currentPlayer], G.handCount[currentPlayer]+2-1);
            }

            if (passed) {
                passed = assertInt(testG.discardCount[currentPlayer], G.discardCount[currentPlayer]+1);
            }

            if (passed) numTestPassed++;

            else {
                printf("\nFAILED: i: %i\tcurrentPlayer: %i\n", i, currentPlayer);
            }

            numTest++;
        }
    }

    printf("numTest: %i\tnumTestPassed: %i\n\n", numTest, numTestPassed);
}
