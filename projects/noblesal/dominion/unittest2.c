// playCard  234
//
#include "assertTest.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include "rngs.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>



int main (int argc, char *argv[])
{
    // GAME SETUP
    int numPlayers = 2;
    int kingdomCards[10] = {adventurer, smithy, gardens, village, council_room, minion, embargo, great_hall, outpost, ambassador};
    int seed = 1000,
        passed;

    struct gameState BASE, G, testG;

    int card,
        handPos = 0,
        choice1 = 0,
        choice2 = 0,
        choice3 = 0,
        retVal,
        retValTest,
        testNumber = 1,
        currentPlayer;

    initializeGame(numPlayers, kingdomCards, seed, &BASE);

    // TEST 1
    // RETURN -1 FROM PHASE
    printf("\n\nTEST %i STARTED\n", testNumber++);
    printf("phase = 1\tnumActions = 1\n\n");
    memcpy(&G, &BASE, sizeof(struct gameState));
    G.phase = 1;
    G.numActions = 1;
    memcpy(&testG, &G, sizeof(struct gameState));

    retValTest = playCard(handPos, choice1, choice2, choice3, &testG);
    retVal = 0;

    printf("return value: %i, expected: %i...\t", retVal, retVal-1);
    passed = assertInt(retValTest, retVal-1);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("phase: %i, expected: %i...\t\t", G.phase, G.phase);
    passed = assertInt(testG.phase, G.phase);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("numActions: %i, expected: %i...\t\t", G.numActions, G.numActions);
    passed = assertInt(testG.numActions, G.numActions);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");


    // TEST 2
    // RETURN -1 FROM numActions
    printf("\n\nTEST %i STARTED\n", testNumber++);
    printf("phase = 0\tnumActions = 0\n\n");
    memcpy(&G, &BASE, sizeof(struct gameState));

    G.phase = 0;
    G.numActions = 0;
    memcpy(&testG, &G, sizeof(struct gameState));

    retValTest = playCard(handPos, choice1, choice2, choice3, &testG);
    retVal = 0;

    printf("return value: %i, expected: %i...\t", retValTest, retVal-1);
    passed = assertInt(retValTest, retVal-1);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("phase: %i, expected: %i...\t\t", G.phase, G.phase);
    passed = assertInt(testG.phase, G.phase);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("numActions: %i, expected: %i...\t\t", G.numActions, G.numActions);
    passed = assertInt(testG.numActions, G.numActions);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");


    // TEST 3
    // RETURN -1 FROM selected card
    printf("\n\nTEST %i STARTED\n", testNumber++);
    printf("phase = 0\tnumActions = 1\n\n");
    memcpy(&G, &BASE, sizeof(struct gameState));

    G.phase = 0;
    G.numActions = 1;
    handPos = 0;
    memcpy(&testG, &G, sizeof(struct gameState));

    retValTest = playCard(handPos, choice1, choice2, choice3, &testG);
    retVal = 0;

    printf("return value: %i, expected: %i...\t", retValTest, retVal-1);
    passed = assertInt(retValTest, retVal-1);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("phase: %i, expected: %i...\t\t", G.phase, G.phase);
    passed = assertInt(testG.phase, G.phase);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("numActions: %i, expected: %i...\t\t", G.numActions, G.numActions);
    passed = assertInt(testG.numActions, G.numActions);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");


    // TEST 4
    // RETURN 0
    printf("\n\nTEST %i STARTED\n", testNumber++);
    printf("phase = 0\tnumActions = 1\tForce use Adventurer Card\n\n");
    memcpy(&G, &BASE, sizeof(struct gameState));

    G.phase = 0;
    G.numActions = 1;
    retVal = 0;

    // FORCE ADVENTRURER CARD TO BE PLAYED
    gainCard(adventurer, &G, 2, G.whoseTurn);
    handPos = G.handCount[G.whoseTurn]-1;

    memcpy(&testG, &G, sizeof(struct gameState));

    retValTest = playCard(handPos, choice1, choice2, choice3, &testG);

    printf("return value: %i, expected: %i...\t\t", retVal, retVal);
    passed = assertInt(retValTest, retVal);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("phase: %i, expected: %i...\t\t", G.phase, G.phase);
    passed = assertInt(testG.phase, G.phase);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("numActions: %i, expected: %i...\t\t", G.numActions, G.numActions-1);
    passed = assertInt(testG.numActions, G.numActions-1);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("coins: %i, expected: %i...\t\t", G.coins, G.coins+2);
    passed = assertInt(testG.coins, G.coins+2);
    if (passed) printf("PASSED\n");
    else printf("FAILED\tcoins: %i\n", testG.coins);


    // TEST 5
    printf("\n\nTEST %i STARTED\n", testNumber++);
    printf("phase = 0\tnumActions = 1\tForce use Outpost Card\n\n");
    memcpy(&G, &BASE, sizeof(struct gameState));

    G.phase = 0;
    G.numActions = 1;
    card = outpost;
    currentPlayer = whoseTurn(&G);
    retVal = 0;

    // FORCE outpost CARD TO BE PLAYED
    gainCard(card, &G, 2, currentPlayer);
    handPos = G.handCount[currentPlayer] - 1;

    memcpy(&testG, &G, sizeof(struct gameState));
    retValTest = playCard(handPos, choice1, choice2, choice3, &testG);

    printf("return value: %i, expected: %i...\t\t", retVal, retVal);
    passed = assertInt(retValTest, retVal);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("phase: %i, expected: %i...\t\t", G.phase, G.phase);
    passed = assertInt(testG.phase, G.phase);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("numActions: %i, expected: %i...\t\t", G.numActions, G.numActions-1);
    passed = assertInt(testG.numActions, G.numActions-1);
    if (passed) printf("PASSED\n");
    else printf("FAILED\tnumActions: %i\n", testG.numActions);

    printf("coins: %i, expected: %i...\t\t", testG.coins, G.coins);
    passed = assertInt(testG.coins, G.coins);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("outpostPlayed: %i, expected: %i...\t", G.outpostPlayed, G.outpostPlayed+1);
    passed = assertInt(testG.outpostPlayed, G.outpostPlayed+1);
    if (passed) printf("PASSED\n");
    else printf("FAILED\toutpostPlayed: %i\n",testG.outpostPlayed);


    // TEST 6
    printf("\n\nTEST %i STARTED\n", testNumber++);
    printf("phase = 0\tnumActions = 1\tForce use Embargo Card\tchoice1=smithy\n\n");
    memcpy(&G, &BASE, sizeof(struct gameState));

    G.phase = 0;
    G.numActions = 1;
    retVal = 0;
    choice1 = smithy;

    // FORCE Embargo CARD TO BE PLAYED
    gainCard(embargo, &G, 2, G.whoseTurn);
    handPos = G.handCount[G.whoseTurn]-1;

    memcpy(&testG, &G, sizeof(struct gameState));

    retValTest = playCard(handPos, choice1, choice2, choice3, &testG);

    printf("return value: %i, expected: %i...\t\t", retVal, retVal);
    passed = assertInt(retValTest, retVal);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("phase: %i, expected: %i...\t\t", G.phase, G.phase);
    passed = assertInt(testG.phase, G.phase);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("numActions: %i, expected: %i...\t\t", G.numActions, G.numActions);
    passed = assertInt(testG.numActions, G.numActions);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("coins: %i, expected: %i...\t\t", G.coins, G.coins+2);
    passed = assertInt(testG.coins, G.coins+2);
    if (passed) printf("PASSED\n");
    else printf("FAILED\tcoins: %i\n", testG.coins);

    printf("embargoTokens: %i, expected: %i...\t", G.embargoTokens[smithy], G.embargoTokens[smithy]+1);
    passed = assertInt(testG.embargoTokens[smithy], G.embargoTokens[smithy]+1);
    if (passed) printf("PASSED\n");
    else printf("FAILED\tembargoTokens: %i\n", testG.embargoTokens[smithy]);


    // TEST 7
    printf("\n\nTEST %i STARTED\n", testNumber++);
    printf("phase = 0\tnumActions = 1\tForce use Embargo Card\tchoice1=smithy\t supplyCount[choice1] = -1\n\n");
    memcpy(&G, &BASE, sizeof(struct gameState));

    G.phase = 0;
    G.numActions = 1;
    retVal = 0;
    choice1 = smithy;
    G.supplyCount[choice1] = -1;

    // FORCE Embargo CARD TO BE PLAYED
    gainCard(embargo, &G, 2, G.whoseTurn);
    handPos = G.handCount[G.whoseTurn]-1;

    memcpy(&testG, &G, sizeof(struct gameState));

    retValTest = playCard(handPos, choice1, choice2, choice3, &testG);

    printf("return value: %i, expected: %i...\t", retVal, retVal-1);
    passed = assertInt(retValTest, retVal-1);
    if (passed) printf("PASSED\n");
    else printf("FAILED\treturn value: %i\n", retValTest);

    printf("phase: %i, expected: %i...\t\t", G.phase, G.phase);
    passed = assertInt(testG.phase, G.phase);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("numActions: %i, expected: %i...\t\t", G.numActions, G.numActions);
    passed = assertInt(testG.numActions, G.numActions);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("coins: %i, expected: %i...\t\t", G.coins, G.coins+2);
    passed = assertInt(testG.coins, G.coins+2);
    if (passed) printf("PASSED\n");
    else printf("FAILED\tcoins: %i\n", testG.coins);

    printf("embargoTokens: %i, expected: %i...\t", G.embargoTokens[smithy], G.embargoTokens[smithy]);
    passed = assertInt(testG.embargoTokens[smithy], G.embargoTokens[smithy]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\tembargoTokens: %i\n", testG.embargoTokens[smithy]);


    return 0;
}
