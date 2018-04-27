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

    int card,
        coin_bonus,
        handPos = 0,
        choice1 = 0,
        choice2 = 0,
        choice3 = 0,
        player,
        i,
        retVal,
        retValTest,
        testNumber = 1;

    initializeGame(numPlayers, kingdomCards, seed, &G);

    // TEST 1
    // RETURN -1 FROM PHASE
    printf("TEST %i STARTED\n", testNumber);
    G.phase = 1;
    G.numActions = 1;
    retVal = 0;
    memcpy(&testG, &G, sizeof(struct gameState));

    retValTest = playCard(handPos, choice1, choice2, choice3, &testG);

    if (G.phase != 0) {
        retVal = -1;
    }

    printf("phase: %i, expected: %i\n", testG.phase, G.phase);
    printf("return value: %i, expected: %i\n", retValTest, retVal);

    assert(testG.phase == G.phase);
    assert(retValTest == retVal);
    printf("TEST %i PASSED\n\n", testNumber++);


    // TEST 2
    // RETURN -1 FROM numActions
    printf("TEST %i STARTED\n", testNumber);
    G.phase = 0;
    G.numActions = 0;
    retVal = 0;
    memcpy(&testG, &G, sizeof(struct gameState));

    retValTest = playCard(handPos, choice1, choice2, choice3, &testG);

    if (G.numActions < 1) {
        retVal = -1;
    }

    printf("phase: %i, expected: %i\n", testG.phase, G.phase);
    printf("numActions: %i, expected: %i\n", testG.numActions, G.numActions);
    printf("return value: %i, expected: %i\n", retValTest, retVal);

    assert(testG.phase == G.phase);
    assert(testG.numActions == G.numActions);
    assert(retValTest == retVal);
    printf("TEST %i PASSED\n\n", testNumber++);


    // TEST 3
    // RETURN -1 FROM selected card
    printf("TEST %i STARTED\n", testNumber);
    G.phase = 0;
    G.numActions = 1;
    retVal = 0;
    handPos = 0;
    memcpy(&testG, &G, sizeof(struct gameState));

    retValTest = playCard(handPos, choice1, choice2, choice3, &testG);

    card = handCard(handPos, &G);

    if (card < adventurer || card > treasure_map) {
        retVal = -1;
    }

    printf("phase: %i, expected: %i\n", testG.phase, G.phase);
    printf("numActions: %i, expected: %i\n", testG.numActions, G.numActions);
    printf("return value: %i, expected: %i\n", retValTest, retVal);

    assert(testG.phase == G.phase);
    assert(testG.numActions == G.numActions);
    assert(retValTest == retVal);
    printf("TEST %i PASSED\n\n", testNumber++);


    // TEST 4
    // RETURN 0
    printf("TEST %i STARTED\n", testNumber);
    G.phase = 0;
    G.numActions = 1;
    choice1 = 1;
    retVal = 0;

    // FORCE ADVENTRURER CARD TO BE PLAYED
    gainCard(adventurer, &G, 2, G.whoseTurn);
    handPos = 5;

    memcpy(&testG, &G, sizeof(struct gameState));

    retValTest = playCard(handPos, choice1, choice2, choice3, &testG);

    card = handCard(handPos, &G);

    if (cardEffect(card, choice1, choice2, choice3, &G, handPos, &coin_bonus) < 0) {
        retVal = -1;
    }

    G.numActions--;
    updateCoins(G.whoseTurn, &G, coin_bonus);

    printf("phase: %i, expected: %i\n", testG.phase, G.phase);
    printf("numActions: %i, expected: %i\n", testG.numActions, G.numActions);
    printf("coins: %i, expected: %i\n", testG.coins, G.coins);
    printf("return value: %i, expected: %i\n", retValTest, retVal);

    assert(testG.phase == G.phase);
    assert(testG.numActions == G.numActions);
    assert(retValTest == retVal);
    printf("TEST %i PASSED\n\n", testNumber++);

    return 0;
}
