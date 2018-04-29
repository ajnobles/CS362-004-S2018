// isGameOver
#include "assertTest.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>



int main (int argc, char *argv[])
{
    // GAME SETUP
    int numPlayers = 2;
    int kingdomCards[10] = {adventurer, smithy, gardens, village, council_room, minion, steward, great_hall, tribute, ambassador};
    int seed = 1000,
        passed = 0;

    struct gameState BASE, G, testG;

    int i,
        j,
        testGameOver,
        gameOver,
        testNumber = 1;

    initializeGame(numPlayers, kingdomCards, seed, &BASE);

    // TEST 1
    printf("TEST %i STARTED\n", testNumber++);
    memcpy(&G, &BASE, sizeof(struct gameState));

    gameOver = 0;
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

    printf("isGameOver: %i, expected: %i...\t\t\t", testGameOver, gameOver);
    passed = assertInt(testGameOver, gameOver);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[province]: %i, expected: %i...\t", testG.supplyCount[province], G.supplyCount[province]);
    passed = assertInt(testG.supplyCount[province], G.supplyCount[province]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[village]: %i, expected: %i...\t", testG.supplyCount[village], G.supplyCount[village]);
    passed = assertInt(testG.supplyCount[village], G.supplyCount[village]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[adventurer]: %i, expected: %i...\t", testG.supplyCount[adventurer], G.supplyCount[adventurer]);
    passed = assertInt(testG.supplyCount[adventurer], G.supplyCount[adventurer]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[smithy]: %i, expected: %i...\t", testG.supplyCount[smithy], G.supplyCount[smithy]);    assert(gameOver == testGameOver);
    passed = assertInt(testG.supplyCount[smithy], G.supplyCount[smithy]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("Testing all card supply counts...\t\t");
    passed = assertIntArr(testG.supplyCount,G.supplyCount);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");



    // TEST 2
    printf("\nTEST %i STARTED\n", testNumber++);
    memcpy(&G, &BASE, sizeof(struct gameState));

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


    printf("isGameOver: %i, expected: %i...\t\t\t", testGameOver, gameOver);
    passed = assertInt(testGameOver, gameOver);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[province]: %i, expected: %i...\t", testG.supplyCount[province], G.supplyCount[province]);
    passed = assertInt(testG.supplyCount[province], G.supplyCount[province]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[village]: %i, expected: %i...\t", testG.supplyCount[village], G.supplyCount[village]);
    passed = assertInt(testG.supplyCount[village], G.supplyCount[village]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[adventurer]: %i, expected: %i...\t", testG.supplyCount[adventurer], G.supplyCount[adventurer]);
    passed = assertInt(testG.supplyCount[adventurer], G.supplyCount[adventurer]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[smithy]: %i, expected: %i...\t", testG.supplyCount[smithy], G.supplyCount[smithy]);    assert(gameOver == testGameOver);
    passed = assertInt(testG.supplyCount[smithy], G.supplyCount[smithy]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("Testing all card supply counts...\t\t");
    passed = assertIntArr(testG.supplyCount,G.supplyCount);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");



    // TEST 3
    printf("\nTEST %i STARTED\n", testNumber++);
    memcpy(&G, &BASE, sizeof(struct gameState));

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

    printf("isGameOver: %i, expected: %i...\t\t\t", testGameOver, gameOver);
    passed = assertInt(testGameOver, gameOver);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[province]: %i, expected: %i...\t", testG.supplyCount[province], G.supplyCount[province]);
    passed = assertInt(testG.supplyCount[province], G.supplyCount[province]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[village]: %i, expected: %i...\t", testG.supplyCount[village], G.supplyCount[village]);
    passed = assertInt(testG.supplyCount[village], G.supplyCount[village]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[adventurer]: %i, expected: %i...\t", testG.supplyCount[adventurer], G.supplyCount[adventurer]);
    passed = assertInt(testG.supplyCount[adventurer], G.supplyCount[adventurer]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[smithy]: %i, expected: %i...\t", testG.supplyCount[smithy], G.supplyCount[smithy]);    assert(gameOver == testGameOver);
    passed = assertInt(testG.supplyCount[smithy], G.supplyCount[smithy]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("Testing all card supply counts...\t\t");
    passed = assertIntArr(testG.supplyCount,G.supplyCount);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");



    // TEST 4
    printf("\nTEST %i STARTED\n", testNumber++);
    memcpy(&G, &BASE, sizeof(struct gameState));

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


    printf("isGameOver: %i, expected: %i...\t\t\t", testGameOver, gameOver);
    passed = assertInt(testGameOver, gameOver);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[province]: %i, expected: %i...\t", testG.supplyCount[province], G.supplyCount[province]);
    passed = assertInt(testG.supplyCount[province], G.supplyCount[province]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[village]: %i, expected: %i...\t\t", testG.supplyCount[village], G.supplyCount[village]);
    passed = assertInt(testG.supplyCount[village], G.supplyCount[village]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[adventurer]: %i, expected: %i...\t", testG.supplyCount[adventurer], G.supplyCount[adventurer]);
    passed = assertInt(testG.supplyCount[adventurer], G.supplyCount[adventurer]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[smithy]: %i, expected: %i...\t", testG.supplyCount[smithy], G.supplyCount[smithy]);    assert(gameOver == testGameOver);
    passed = assertInt(testG.supplyCount[smithy], G.supplyCount[smithy]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("Testing all card supply counts...\t\t");
    passed = assertIntArr(testG.supplyCount,G.supplyCount);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");



    // TEST 5
    printf("\nTEST %i STARTED\n", testNumber++);
    memcpy(&G, &BASE, sizeof(struct gameState));

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

    printf("isGameOver: %i, expected: %i...\t\t\t", testGameOver, gameOver);
    passed = assertInt(testGameOver, gameOver);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[province]: %i, expected: %i...\t", testG.supplyCount[province], G.supplyCount[province]);
    passed = assertInt(testG.supplyCount[province], G.supplyCount[province]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[village]: %i, expected: %i...\t\t", testG.supplyCount[village], G.supplyCount[village]);
    passed = assertInt(testG.supplyCount[village], G.supplyCount[village]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[adventurer]: %i, expected: %i...\t", testG.supplyCount[adventurer], G.supplyCount[adventurer]);
    passed = assertInt(testG.supplyCount[adventurer], G.supplyCount[adventurer]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[smithy]: %i, expected: %i...\t", testG.supplyCount[smithy], G.supplyCount[smithy]);    assert(gameOver == testGameOver);
    passed = assertInt(testG.supplyCount[smithy], G.supplyCount[smithy]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("Testing all card supply counts...\t\t");
    passed = assertIntArr(testG.supplyCount,G.supplyCount);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");



    // TEST 6
    printf("\nTEST %i STARTED\n", testNumber++);
    memcpy(&G, &BASE, sizeof(struct gameState));

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

    printf("isGameOver: %i, expected: %i...\t\t\t", testGameOver, gameOver);
    passed = assertInt(testGameOver, gameOver);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[province]: %i, expected: %i...\t", testG.supplyCount[province], G.supplyCount[province]);
    passed = assertInt(testG.supplyCount[province], G.supplyCount[province]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[village]: %i, expected: %i...\t\t", testG.supplyCount[village], G.supplyCount[village]);
    passed = assertInt(testG.supplyCount[village], G.supplyCount[village]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[adventurer]: %i, expected: %i...\t", testG.supplyCount[adventurer], G.supplyCount[adventurer]);
    passed = assertInt(testG.supplyCount[adventurer], G.supplyCount[adventurer]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[smithy]: %i, expected: %i...\t", testG.supplyCount[smithy], G.supplyCount[smithy]);    assert(gameOver == testGameOver);
    passed = assertInt(testG.supplyCount[smithy], G.supplyCount[smithy]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("Testing all card supply counts...\t\t");
    passed = assertIntArr(testG.supplyCount,G.supplyCount);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");



    // TEST 7
    printf("\nTEST %i STARTED\n", testNumber++);
    memcpy(&G, &BASE, sizeof(struct gameState));

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

    printf("isGameOver: %i, expected: %i...\t\t\t", testGameOver, gameOver);
    passed = assertInt(testGameOver, gameOver);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[province]: %i, expected: %i...\t", testG.supplyCount[province], G.supplyCount[province]);
    passed = assertInt(testG.supplyCount[province], G.supplyCount[province]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[village]: %i, expected: %i...\t\t", testG.supplyCount[village], G.supplyCount[village]);
    passed = assertInt(testG.supplyCount[village], G.supplyCount[village]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[adventurer]: %i, expected: %i...\t", testG.supplyCount[adventurer], G.supplyCount[adventurer]);
    passed = assertInt(testG.supplyCount[adventurer], G.supplyCount[adventurer]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[smithy]: %i, expected: %i...\t\t", testG.supplyCount[smithy], G.supplyCount[smithy]);    assert(gameOver == testGameOver);
    passed = assertInt(testG.supplyCount[smithy], G.supplyCount[smithy]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("Testing all card supply counts...\t\t");
    passed = assertIntArr(testG.supplyCount,G.supplyCount);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");


    // TEST 8
    printf("\nTEST %i STARTED\n", testNumber++);
    memcpy(&G, &BASE, sizeof(struct gameState));

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

    printf("isGameOver: %i, expected: %i...\t\t\t", testGameOver, gameOver);
    passed = assertInt(testGameOver, gameOver);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[province]: %i, expected: %i...\t", testG.supplyCount[province], G.supplyCount[province]);
    passed = assertInt(testG.supplyCount[province], G.supplyCount[province]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[village]: %i, expected: %i...\t\t", testG.supplyCount[village], G.supplyCount[village]);
    passed = assertInt(testG.supplyCount[village], G.supplyCount[village]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[adventurer]: %i, expected: %i...\t", testG.supplyCount[adventurer], G.supplyCount[adventurer]);
    passed = assertInt(testG.supplyCount[adventurer], G.supplyCount[adventurer]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[smithy]: %i, expected: %i...\t\t", testG.supplyCount[smithy], G.supplyCount[smithy]);    assert(gameOver == testGameOver);
    passed = assertInt(testG.supplyCount[smithy], G.supplyCount[smithy]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("Testing all card supply counts...\t\t");
    passed = assertIntArr(testG.supplyCount,G.supplyCount);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");



    // TEST 9
    printf("\nTEST %i STARTED\n", testNumber++);
    memcpy(&G, &BASE, sizeof(struct gameState));

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


    printf("isGameOver: %i, expected: %i...\t\t\t", testGameOver, gameOver);
    passed = assertInt(testGameOver, gameOver);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[province]: %i, expected: %i...\t", testG.supplyCount[province], G.supplyCount[province]);
    passed = assertInt(testG.supplyCount[province], G.supplyCount[province]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[village]: %i, expected: %i...\t\t", testG.supplyCount[village], G.supplyCount[village]);
    passed = assertInt(testG.supplyCount[village], G.supplyCount[village]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[adventurer]: %i, expected: %i...\t", testG.supplyCount[adventurer], G.supplyCount[adventurer]);
    passed = assertInt(testG.supplyCount[adventurer], G.supplyCount[adventurer]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("supplyCount[smithy]: %i, expected: %i...\t\t", testG.supplyCount[smithy], G.supplyCount[smithy]);    assert(gameOver == testGameOver);
    passed = assertInt(testG.supplyCount[smithy], G.supplyCount[smithy]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("Testing all card supply counts...\t\t");
    passed = assertIntArr(testG.supplyCount,G.supplyCount);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");


    return 0;
}
