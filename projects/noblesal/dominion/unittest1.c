//
#include "dominion.h"
#include "dominion_helpers.h"

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

    int i,
        j,
        testGameOver,
        gameOver = 0,
        testNumber = 1;

    initializeGame(numPlayers, kingdomCards, seed, &G);

    // TEST 1
    printf("TEST %i STARTED\n", testNumber);
    printf("Initial gameState Settings\n");
    // G.supplyCount[province] = 0;
    // G.supplyCount[adventurer] = 0;
    // G.supplyCount[village] = 0;
    // G.supplyCount[smithy] = 0;

    memcpy(&testG, &G, sizeof(struct gameState));
    testGameOver = isGameOver(&testG);

    // Test isGameOver to G
    if (G.supplyCount[province] == 0) {
        gameOver = 1;
    }

    j = 0;
    for (i = 0; i < 25; i++) {
        if (G.supplyCount[i] == 0) {
            j++;
        }

        if (j >= 3) {
            gameOver = 1;
        }
    }

    printf("isGameOver: %i, expected: %i\n", testGameOver, gameOver);
    printf("supplyCount[province]: %i, expected: %i\n", testG.supplyCount[province], G.supplyCount[province]);
    printf("supplyCount[village]: %i, expected: %i\n", testG.supplyCount[village], G.supplyCount[village]);
    printf("supplyCount[adventurer]: %i, expected: %i\n", testG.supplyCount[adventurer], G.supplyCount[adventurer]);
    printf("supplyCount[smithy]: %i, expected: %i\n", testG.supplyCount[smithy], G.supplyCount[smithy]);    assert(gameOver == testGameOver);
    assert(G.supplyCount[province] == testG.supplyCount[province]);
    for (i = 0; i < 25; i++) {
        assert(G.supplyCount[i] == testG.supplyCount[i]);
    }
    printf("TEST %i PASSED\n\n", testNumber++);


    // TEST 2
    printf("TEST %i STARTED\n", testNumber);
    G.supplyCount[province] = 0;
    // G.supplyCount[adventurer] = 0;
    //G.supplyCount[village] = 0;
    //G.supplyCount[smithy] = 0;
    gameOver = 0;

    memcpy(&testG, &G, sizeof(struct gameState));
    testGameOver = isGameOver(&testG);

    // Test isGameOver to G
    if (G.supplyCount[province] == 0) {
        gameOver = 1;
    }

    j = 0;
    for (i = 0; i < 25; i++) {
        if (G.supplyCount[i] == 0) {
            j++;
        }

        if (j >= 3) {
            gameOver = 1;
        }
    }

    printf("isGameOver: %i, expected: %i\n", testGameOver, gameOver);
    printf("supplyCount[province]: %i, expected: %i\n", testG.supplyCount[province], G.supplyCount[province]);
    printf("supplyCount[village]: %i, expected: %i\n", testG.supplyCount[village], G.supplyCount[village]);
    printf("supplyCount[adventurer]: %i, expected: %i\n", testG.supplyCount[adventurer], G.supplyCount[adventurer]);
    printf("supplyCount[smithy]: %i, expected: %i\n", testG.supplyCount[smithy], G.supplyCount[smithy]);    assert(gameOver == testGameOver);
    assert(G.supplyCount[province] == testG.supplyCount[province]);
    for (i = 0; i < 25; i++) {
        assert(G.supplyCount[i] == testG.supplyCount[i]);
    }
    printf("TEST %i PASSED\n\n", testNumber++);


    // TEST 3
    printf("TEST %i STARTED\n", testNumber);
    G.supplyCount[province] = 4;
    // G.supplyCount[adventurer] = 0;
    // G.supplyCount[village] = 0;
    //G.supplyCount[smithy] = 0;
    gameOver = 0;

    memcpy(&testG, &G, sizeof(struct gameState));
    testGameOver = isGameOver(&testG);

    // Test isGameOver to G
    if (G.supplyCount[province] == 0) {
        gameOver = 1;
    }

    j = 0;
    for (i = 0; i < 25; i++) {
        if (G.supplyCount[i] == 0) {
            j++;
        }

        if (j >= 3) {
            gameOver = 1;
        }
    }

    printf("isGameOver: %i, expected: %i\n", testGameOver, gameOver);
    printf("supplyCount[province]: %i, expected: %i\n", testG.supplyCount[province], G.supplyCount[province]);
    printf("supplyCount[village]: %i, expected: %i\n", testG.supplyCount[village], G.supplyCount[village]);
    printf("supplyCount[adventurer]: %i, expected: %i\n", testG.supplyCount[adventurer], G.supplyCount[adventurer]);
    printf("supplyCount[smithy]: %i, expected: %i\n", testG.supplyCount[smithy], G.supplyCount[smithy]);
    assert(gameOver == testGameOver);
    assert(G.supplyCount[province] == testG.supplyCount[province]);
    for (i = 0; i < 25; i++) {
        assert(G.supplyCount[i] == testG.supplyCount[i]);
    }
    printf("TEST %i PASSED\n\n", testNumber++);


    // TEST 4
    printf("TEST %i STARTED\n", testNumber);
    // G.supplyCount[province] = 4;
    G.supplyCount[adventurer] = 0;
    G.supplyCount[village] = 0;
    //G.supplyCount[smithy] = 0;
    gameOver = 0;

    memcpy(&testG, &G, sizeof(struct gameState));
    testGameOver = isGameOver(&testG);

    // Test isGameOver to G
    if (G.supplyCount[province] == 0) {
        gameOver = 1;
    }

    j = 0;
    for (i = 0; i < 25; i++) {
        if (G.supplyCount[i] == 0) {
            j++;
        }

        if (j >= 3) {
            gameOver = 1;
        }
    }

    printf("isGameOver: %i, expected: %i\n", testGameOver, gameOver);
    printf("supplyCount[province]: %i, expected: %i\n", testG.supplyCount[province], G.supplyCount[province]);
    printf("supplyCount[village]: %i, expected: %i\n", testG.supplyCount[village], G.supplyCount[village]);
    printf("supplyCount[adventurer]: %i, expected: %i\n", testG.supplyCount[adventurer], G.supplyCount[adventurer]);
    printf("supplyCount[smithy]: %i, expected: %i\n", testG.supplyCount[smithy], G.supplyCount[smithy]);
    assert(gameOver == testGameOver);
    assert(G.supplyCount[province] == testG.supplyCount[province]);
    for (i = 0; i < 25; i++) {
        assert(G.supplyCount[i] == testG.supplyCount[i]);
    }
    printf("TEST %i PASSED\n\n", testNumber++);


    // TEST 5
    printf("TEST %i STARTED\n", testNumber);
    G.supplyCount[province] = 0;
    G.supplyCount[adventurer] = 0;
    G.supplyCount[village] = 0;
    //G.supplyCount[smithy] = 0;
    gameOver = 0;

    memcpy(&testG, &G, sizeof(struct gameState));
    testGameOver = isGameOver(&testG);

    // Test isGameOver to G
    if (G.supplyCount[province] == 0) {
        gameOver = 1;
    }

    j = 0;
    for (i = 0; i < 25; i++) {
        if (G.supplyCount[i] == 0) {
            j++;
        }

        if (j >= 3) {
            gameOver = 1;
        }
    }

    printf("isGameOver: %i, expected: %i\n", testGameOver, gameOver);
    printf("supplyCount[province]: %i, expected: %i\n", testG.supplyCount[province], G.supplyCount[province]);
    printf("supplyCount[village]: %i, expected: %i\n", testG.supplyCount[village], G.supplyCount[village]);
    printf("supplyCount[adventurer]: %i, expected: %i\n", testG.supplyCount[adventurer], G.supplyCount[adventurer]);
    printf("supplyCount[smithy]: %i, expected: %i\n", testG.supplyCount[smithy], G.supplyCount[smithy]);
    assert(gameOver == testGameOver);
    assert(G.supplyCount[province] == testG.supplyCount[province]);
    for (i = 0; i < 25; i++) {
        assert(G.supplyCount[i] == testG.supplyCount[i]);
    }
    printf("TEST %i PASSED\n\n", testNumber++);


    // TEST 6
    printf("TEST %i STARTED\n", testNumber);
    G.supplyCount[province] = 4;
    G.supplyCount[adventurer] = 0;
    G.supplyCount[village] = 0;
    //G.supplyCount[smithy] = 0;
    gameOver = 0;

    memcpy(&testG, &G, sizeof(struct gameState));
    testGameOver = isGameOver(&testG);

    // Test isGameOver to G
    if (G.supplyCount[province] == 0) {
        gameOver = 1;
    }

    j = 0;
    for (i = 0; i < 25; i++) {
        if (G.supplyCount[i] == 0) {
            j++;
        }

        if (j >= 3) {
            gameOver = 1;
        }
    }

    printf("isGameOver: %i, expected: %i\n", testGameOver, gameOver);
    printf("supplyCount[province]: %i, expected: %i\n", testG.supplyCount[province], G.supplyCount[province]);
    printf("supplyCount[village]: %i, expected: %i\n", testG.supplyCount[village], G.supplyCount[village]);
    printf("supplyCount[adventurer]: %i, expected: %i\n", testG.supplyCount[adventurer], G.supplyCount[adventurer]);
    printf("supplyCount[smithy]: %i, expected: %i\n", testG.supplyCount[smithy], G.supplyCount[smithy]);
    assert(gameOver == testGameOver);
    assert(G.supplyCount[province] == testG.supplyCount[province]);
    for (i = 0; i < 25; i++) {
        assert(G.supplyCount[i] == testG.supplyCount[i]);
    }
    printf("TEST %i PASSED\n\n", testNumber++);


    // TEST 7
    printf("TEST %i STARTED\n", testNumber);
    // G.supplyCount[province] = 0;
    G.supplyCount[adventurer] = 0;
    G.supplyCount[village] = 0;
    G.supplyCount[smithy] = 0;
    gameOver = 0;

    memcpy(&testG, &G, sizeof(struct gameState));
    testGameOver = isGameOver(&testG);

    // Test isGameOver to G
    if (G.supplyCount[province] == 0) {
        gameOver = 1;
    }

    j = 0;
    for (i = 0; i < 25; i++) {
        if (G.supplyCount[i] == 0) {
            j++;
        }

        if (j >= 3) {
            gameOver = 1;
        }
    }

    printf("isGameOver: %i, expected: %i\n", testGameOver, gameOver);
    printf("supplyCount[province]: %i, expected: %i\n", testG.supplyCount[province], G.supplyCount[province]);
    printf("supplyCount[village]: %i, expected: %i\n", testG.supplyCount[village], G.supplyCount[village]);
    printf("supplyCount[adventurer]: %i, expected: %i\n", testG.supplyCount[adventurer], G.supplyCount[adventurer]);
    printf("supplyCount[smithy]: %i, expected: %i\n", testG.supplyCount[smithy], G.supplyCount[smithy]);
    assert(gameOver == testGameOver);
    assert(G.supplyCount[province] == testG.supplyCount[province]);
    for (i = 0; i < 25; i++) {
        assert(G.supplyCount[i] == testG.supplyCount[i]);
    }
    printf("TEST %i PASSED\n\n", testNumber++);


    // TEST 8
    printf("TEST %i STARTED\n", testNumber);
    G.supplyCount[province] = 0;
    G.supplyCount[adventurer] = 0;
    G.supplyCount[village] = 0;
    G.supplyCount[smithy] = 0;
    gameOver = 0;

    memcpy(&testG, &G, sizeof(struct gameState));
    testGameOver = isGameOver(&testG);

    // Test isGameOver to G
    if (G.supplyCount[province] == 0) {
        gameOver = 1;
    }

    j = 0;
    for (i = 0; i < 25; i++) {
        if (G.supplyCount[i] == 0) {
            j++;
        }

        if (j >= 3) {
            gameOver = 1;
        }
    }

    printf("isGameOver: %i, expected: %i\n", testGameOver, gameOver);
    printf("supplyCount[province]: %i, expected: %i\n", testG.supplyCount[province], G.supplyCount[province]);
    printf("supplyCount[village]: %i, expected: %i\n", testG.supplyCount[village], G.supplyCount[village]);
    printf("supplyCount[adventurer]: %i, expected: %i\n", testG.supplyCount[adventurer], G.supplyCount[adventurer]);
    printf("supplyCount[smithy]: %i, expected: %i\n", testG.supplyCount[smithy], G.supplyCount[smithy]);
    assert(gameOver == testGameOver);
    assert(G.supplyCount[province] == testG.supplyCount[province]);
    for (i = 0; i < 25; i++) {
        assert(G.supplyCount[i] == testG.supplyCount[i]);
    }
    printf("TEST %i PASSED\n\n", testNumber++);


    // TEST 9
    printf("TEST %i STARTED\n", testNumber);
    G.supplyCount[province] = 4;
    G.supplyCount[adventurer] = 0;
    G.supplyCount[village] = 0;
    G.supplyCount[smithy] = 0;
    gameOver = 0;

    memcpy(&testG, &G, sizeof(struct gameState));
    testGameOver = isGameOver(&testG);

    // Test isGameOver to G
    if (G.supplyCount[province] == 0) {
        gameOver = 1;
    }

    j = 0;
    for (i = 0; i < 25; i++) {
        if (G.supplyCount[i] == 0) {
            j++;
        }

        if (j >= 3) {
            gameOver = 1;
        }
    }

    printf("isGameOver: %i, expected: %i\n", testGameOver, gameOver);
    printf("supplyCount[province]: %i, expected: %i\n", testG.supplyCount[province], G.supplyCount[province]);
    printf("supplyCount[village]: %i, expected: %i\n", testG.supplyCount[village], G.supplyCount[village]);
    printf("supplyCount[adventurer]: %i, expected: %i\n", testG.supplyCount[adventurer], G.supplyCount[adventurer]);
    printf("supplyCount[smithy]: %i, expected: %i\n", testG.supplyCount[smithy], G.supplyCount[smithy]);
    assert(gameOver == testGameOver);
    assert(G.supplyCount[province] == testG.supplyCount[province]);
    for (i = 0; i < 25; i++) {
        assert(G.supplyCount[i] == testG.supplyCount[i]);
    }
    printf("TEST %i PASSED\n\n", testNumber++);


    return 0;
}
