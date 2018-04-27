// playCard
//
#include "dominion.h"
#include "dominion_helpers.h"

#include "refactor.h"

#include "rngs.h"
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>



int main (int argc, char *argv[])
{
    // GAME SETUP
    int numPlayers = 2;
    int kingdomCards[10] = {adventurer, smithy, gardens, village, council_room, minion, steward, great_hall, tribute, ambassador};
    int seed = 1000;

    struct gameState G, testG;
//
    int card,
        retVal,
        retValTest,
        testNumber = 1;

    initializeGame(numPlayers, kingdomCards, seed, &G);

    // TEST 1
    printf("TEST %i STARTED\n", testNumber);
    card = adventurer;

    memcpy(&testG, &G, sizeof(struct gameState));

    retValTest = supplyCount(card, &testG);

    retVal = G.supplyCount[card];

    printf("card supply: %i, expected: %i\n", retValTest, retVal);
    assert(retVal == retValTest);

    printf("TEST %i PASSED\n\n", testNumber++);

    // TEST 2
    printf("TEST %i STARTED\n", testNumber);
    card = adventurer;
    G.supplyCount[adventurer] = 5;

    memcpy(&testG, &G, sizeof(struct gameState));

    retValTest = supplyCount(card, &testG);

    retVal = G.supplyCount[card];

    printf("card supply: %i, expected: %i\n", retValTest, retVal);
    assert(retVal == retValTest);

    printf("TEST %i PASSED\n\n", testNumber++);

    return 0;
}
