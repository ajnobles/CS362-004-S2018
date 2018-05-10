
#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include "rngs.h"

#include "assertTest.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

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

    for (i = 0; i < 0; i++) {
        memcpy(&testG, &G, sizeof(struct gameState));
        currentPlayer = rand() % numPlayers;
        retVal = 0;
        testG.whoseTurn = currentPlayer;


        // RUN FUNCTION
        retValTest = adventurerRefactor(card, choice1, choice2, choice3, &testG, handPos, &bonus);

        // TEST
        passed = assertInt(retVal, retValTest);

        if (passed) numTestPassed++;

        if (!passed) {
            printf("\nFAILED: i: %i\tcurrentPlayer: %i\n", i, currentPlayer);
        }

        numTest++;
    }

    printf("numTest: %i\tnumTestPassed: %i\n\n", numTest, numTestPassed);
}
