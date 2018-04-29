// playCard
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
    int kingdomCards[10] = {adventurer, smithy, gardens, village, council_room, minion, steward, great_hall, outpost, ambassador};
    int seed = 1000,
        passed;

    struct gameState BASE, G, testG;

    int card,
        coin_bonus,
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
    printf("\nTEST %i STARTED\n", testNumber++);
    memcpy(&G, &BASE, sizeof(struct gameState));
    G.phase = 1;
    G.numActions = 1;
    retVal = 0;
    memcpy(&testG, &G, sizeof(struct gameState));

    retValTest = playCard(handPos, choice1, choice2, choice3, &testG);

    if (G.phase != 0) {
        retVal = -1;
    }

    printf("return value: %i, expected: %i...\t", retValTest, retVal);
    passed = assertInt(retValTest, retVal);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("phase: %i, expected: %i...\t\t", testG.phase, G.phase);
    passed = assertInt(testG.phase, G.phase);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("numActions: %i, expected: %i...\t\t", testG.numActions, G.numActions);
    passed = assertInt(testG.numActions, G.numActions);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");


    // TEST 2
    // RETURN -1 FROM numActions
    printf("\nTEST %i STARTED\n", testNumber++);
    memcpy(&G, &BASE, sizeof(struct gameState));

    G.phase = 0;
    G.numActions = 0;
    retVal = 0;
    memcpy(&testG, &G, sizeof(struct gameState));

    retValTest = playCard(handPos, choice1, choice2, choice3, &testG);

    if (G.phase != 0) {
        retVal = -1;
    }

    if (G.numActions < 1) {
        retVal = -1;
    }

    printf("return value: %i, expected: %i...\t", retValTest, retVal);
    passed = assertInt(retValTest, retVal);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("phase: %i, expected: %i...\t\t", testG.phase, G.phase);
    passed = assertInt(testG.phase, G.phase);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("numActions: %i, expected: %i...\t\t", testG.numActions, G.numActions);
    passed = assertInt(testG.numActions, G.numActions);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");


    // TEST 3
    // RETURN -1 FROM selected card
    printf("\nTEST %i STARTED\n", testNumber++);
    memcpy(&G, &BASE, sizeof(struct gameState));

    G.phase = 0;
    G.numActions = 1;
    retVal = 0;
    handPos = 0;
    memcpy(&testG, &G, sizeof(struct gameState));

    retValTest = playCard(handPos, choice1, choice2, choice3, &testG);

    card = handCard(handPos, &G);

    if (G.phase != 0) {
        retVal = -1;
    }

    if (G.numActions < 1) {
        retVal = -1;
    }

    if (card < adventurer || card > treasure_map) {
        retVal = -1;
    }


    printf("return value: %i, expected: %i...\t", retValTest, retVal);
    passed = assertInt(retValTest, retVal);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("phase: %i, expected: %i...\t\t", testG.phase, G.phase);
    passed = assertInt(testG.phase, G.phase);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("numActions: %i, expected: %i...\t\t", testG.numActions, G.numActions);
    passed = assertInt(testG.numActions, G.numActions);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");


    // TEST 4
    // RETURN 0
    printf("\nTEST %i STARTED\n", testNumber++);
    memcpy(&G, &BASE, sizeof(struct gameState));

    G.phase = 0;
    G.numActions = 1;
    retVal = 0;

    // FORCE ADVENTRURER CARD TO BE PLAYED
    gainCard(adventurer, &G, 2, G.whoseTurn);
    handPos = 0;

    memcpy(&testG, &G, sizeof(struct gameState));

    retValTest = playCard(handPos, choice1, choice2, choice3, &testG);

    card = handCard(handPos, &G);

    if (cardEffect(card, choice1, choice2, choice3, &G, handPos, &coin_bonus) < 0) {
        retVal = -1;
    }

    G.numActions--;
    updateCoins(G.whoseTurn, &G, coin_bonus);


    printf("return value: %i, expected: %i...\t", retValTest, retVal);
    passed = assertInt(retValTest, retVal);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("phase: %i, expected: %i...\t\t", testG.phase, G.phase);
    passed = assertInt(testG.phase, G.phase);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("numActions: %i, expected: %i...\t\t", testG.numActions, G.numActions);
    passed = assertInt(testG.numActions, G.numActions);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("coins: %i, expected: %i...\t\t", testG.coins, G.coins);
    passed = assertInt(testG.coins, G.coins);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");


    // TEST 5
    printf("\nTEST %i STARTED\n", testNumber++);
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

    card = handCard(handPos, &G);

    if (cardEffect(card, choice1, choice2, choice3, &G, handPos, &coin_bonus) < 0) {
        retVal = -1;
    }

    G.numActions--;
    updateCoins(currentPlayer, &G, coin_bonus);


    printf("return value: %i, expected: %i...\t\t", retValTest, retVal);
    passed = assertInt(retValTest, retVal);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("phase: %i, expected: %i...\t\t", testG.phase, G.phase);
    passed = assertInt(testG.phase, G.phase);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("numActions: %i, expected: %i...\t\t", testG.numActions, G.numActions);
    passed = assertInt(testG.numActions, G.numActions);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("coins: %i, expected: %i...\t\t", testG.coins, G.coins);
    passed = assertInt(testG.coins, G.coins);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("outpostPlayed: %i, expected: %i...\t", testG.outpostPlayed, G.outpostPlayed);
    passed = assertInt(testG.outpostPlayed, G.outpostPlayed);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    return 0;
}
