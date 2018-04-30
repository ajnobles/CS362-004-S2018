// endTurn 353
//
#include "assertTest.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define HAND_COUNT_START 5



int main (int argc, char *argv[])
{
    // GAME SETUP
    int numPlayers = 2;
    int kingdomCards[10] = {adventurer, smithy, gardens, village, council_room, minion, steward, great_hall, tribute, ambassador};
    int seed = 1000;

    struct gameState BASE, G, testG;

    int retVal,
        retValTest,
        i,
        k,
        currentPlayer,
        handCount,
        discardCount,
        passed = 0,
        testNumber = 1;

    initializeGame(numPlayers, kingdomCards, seed, &BASE);

    // TEST 1
    printf("\nTEST %i STARTED\n", testNumber++);
    memcpy(&G, &BASE, sizeof(struct gameState));

    // GET CURRENT VALUES
    currentPlayer = whoseTurn(&G);
    handCount = G.handCount[currentPlayer];
    discardCount = G.discardCount[currentPlayer];

    memcpy(&testG, &G, sizeof(struct gameState));

    retVal = 0;
    retValTest = endTurn(&testG);

    printf("return value: %i, expected: %i...\t", retVal, retVal);
    passed = assertInt(retVal, retValTest);
    if (passed) printf("PASSED\n");
    else printf("FAILED\tretVal: %i\n", retValTest);

    printf("whoseTurn: %i, expected: %i...\t", currentPlayer, (currentPlayer+1) % numPlayers);
    passed = assertInt(testG.whoseTurn, (currentPlayer+1) % numPlayers);
    if (passed) printf("PASSED\n");
    else printf("FAILED\twhoseTurn: %i\n", testG.whoseTurn);

    printf("handCount: %i, expected: %i...\t", G.handCount[currentPlayer], 0);
    passed = assertInt(testG.handCount[currentPlayer], 0);
    if (passed) printf("PASSED\n");
    else printf("FAILED\thandCount: %i\n", testG.handCount[currentPlayer]);

    printf("discardCount: %i, expected: %i...\t", G.discardCount[currentPlayer], G.discardCount[currentPlayer]+handCount);
    passed = assertInt(testG.discardCount[currentPlayer], G.discardCount[currentPlayer]+handCount);
    if (passed) printf("PASSED\n");
    else printf("FAILED\tdiscardCount: %i\n", testG.discardCount[currentPlayer]);

    printf("deckCount: %i, expected: %i...\t", G.deckCount[currentPlayer], G.deckCount[currentPlayer]);
    passed = assertInt(testG.deckCount[currentPlayer], G.deckCount[currentPlayer]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\tdiscardCount: %i\n", testG.deckCount[currentPlayer]);

    printf("\tNext Player Values\n");
    currentPlayer = (currentPlayer + 1) % numPlayers;

    printf("handCount: %i, expected: %i...\t", HAND_COUNT_START, HAND_COUNT_START);
    passed = assertInt(testG.handCount[currentPlayer], HAND_COUNT_START);
    if (passed) printf("PASSED\n");
    else printf("FAILED\thandCount: %i\n", testG.handCount[currentPlayer]);


    // TEST 2
    printf("\nTEST %i STARTED\n", testNumber++);

    memcpy(&G, &testG, sizeof(struct gameState));

    // GET CURRENT VALUES
    currentPlayer = whoseTurn(&G);
    handCount = G.handCount[currentPlayer];
    discardCount = G.discardCount[currentPlayer];

    memcpy(&testG, &G, sizeof(struct gameState));

    retVal = 0;
    retValTest = endTurn(&testG);

    printf("return value: %i, expected: %i...\t", retVal, retVal);
    passed = assertInt(retVal, retValTest);
    if (passed) printf("PASSED\n");
    else printf("FAILED\tretVal: %i\n", retValTest);

    printf("whoseTurn: %i, expected: %i...\t", currentPlayer, (currentPlayer+1) % numPlayers);
    passed = assertInt(testG.whoseTurn, (currentPlayer+1) % numPlayers);
    if (passed) printf("PASSED\n");
    else printf("FAILED\twhoseTurn: %i\n", testG.whoseTurn);

    printf("handCount: %i, expected: %i...\t", G.handCount[currentPlayer], 0);
    passed = assertInt(testG.handCount[currentPlayer], 0);
    if (passed) printf("PASSED\n");
    else printf("FAILED\thandCount: %i\n", testG.handCount[currentPlayer]);

    printf("discardCount: %i, expected: %i...\t", G.discardCount[currentPlayer], G.discardCount[currentPlayer]+handCount);
    passed = assertInt(testG.discardCount[currentPlayer], G.discardCount[currentPlayer]+handCount);
    if (passed) printf("PASSED\n");
    else printf("FAILED\tdiscardCount: %i\n", testG.discardCount[currentPlayer]);

    printf("deckCount: %i, expected: %i...\t", G.deckCount[currentPlayer], G.deckCount[currentPlayer]);
    passed = assertInt(testG.deckCount[currentPlayer], G.deckCount[currentPlayer]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\tdiscardCount: %i\n", testG.deckCount[currentPlayer]);

    printf("\tNext Player Values\n");
    currentPlayer = (currentPlayer + 1) % numPlayers;

    printf("handCount: %i, expected: %i...\t", HAND_COUNT_START, HAND_COUNT_START);
    passed = assertInt(testG.handCount[currentPlayer], HAND_COUNT_START);
    if (passed) printf("PASSED\n");
    else printf("FAILED\thandCount: %i\n", testG.handCount[currentPlayer]);


    return 0;
}
