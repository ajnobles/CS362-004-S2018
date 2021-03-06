// isGameOver  393
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

    int testGameOver,
        gameOver,
        testNumber = 1;

    initializeGame(numPlayers, kingdomCards, seed, &BASE);

    // TEST 1
    printf("TEST %i STARTED\n", testNumber++);
    printf("Testing initial game initialization\n\n");
    memcpy(&G, &BASE, sizeof(struct gameState));

    gameOver = 0;

    memcpy(&testG, &G, sizeof(struct gameState));
    testGameOver = isGameOver(&testG);

    printf("gameOver: %i, expected: %i...\t\t\t", gameOver, gameOver);
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

    printf("supplyCount[smithy]: %i, expected: %i...\t", testG.supplyCount[smithy], G.supplyCount[smithy]);
    passed = assertInt(testG.supplyCount[smithy], G.supplyCount[smithy]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("Testing all card supply counts...\t\t");
    passed = assertIntArr(testG.supplyCount,G.supplyCount);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");



    // TEST 2
    printf("\n\nTEST %i STARTED\n", testNumber++);
    printf("supplyCount[province] = 0\n\n");
    memcpy(&G, &BASE, sizeof(struct gameState));

    G.supplyCount[province] = 0;

    memcpy(&testG, &G, sizeof(struct gameState));
    testGameOver = isGameOver(&testG);

    gameOver = 0;

    printf("gameOver: %i, expected: %i...\t\t\t", gameOver, gameOver+1);
    passed = assertInt(testGameOver, gameOver+1);
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

    printf("supplyCount[smithy]: %i, expected: %i...\t", testG.supplyCount[smithy], G.supplyCount[smithy]);
    passed = assertInt(testG.supplyCount[smithy], G.supplyCount[smithy]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("Testing all card supply counts...\t\t");
    passed = assertIntArr(testG.supplyCount,G.supplyCount);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");



    // TEST 3
    printf("\n\nTEST %i STARTED\n", testNumber++);
    printf("supplyCount[province] = 4\n\n");
    memcpy(&G, &BASE, sizeof(struct gameState));

    G.supplyCount[province] = 4;
    gameOver = 0;

    memcpy(&testG, &G, sizeof(struct gameState));
    testGameOver = isGameOver(&testG);

    gameOver = 0;

    printf("gameOver: %i, expected: %i...\t\t\t", gameOver, gameOver);
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

    printf("supplyCount[smithy]: %i, expected: %i...\t", testG.supplyCount[smithy], G.supplyCount[smithy]);
    passed = assertInt(testG.supplyCount[smithy], G.supplyCount[smithy]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("Testing all card supply counts...\t\t");
    passed = assertIntArr(testG.supplyCount,G.supplyCount);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");



    // TEST 4
    printf("\n\nTEST %i STARTED\n", testNumber++);
    printf("supplyCount[adventurer] = 0\tsupplyCount[village] = 0\n\n");
    memcpy(&G, &BASE, sizeof(struct gameState));

    G.supplyCount[adventurer] = 0;
    G.supplyCount[village] = 0;

    memcpy(&testG, &G, sizeof(struct gameState));
    testGameOver = isGameOver(&testG);

    gameOver = 0;

    printf("gameOver: %i, expected: %i...\t\t\t", gameOver, gameOver);
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

    printf("supplyCount[smithy]: %i, expected: %i...\t", testG.supplyCount[smithy], G.supplyCount[smithy]);
    passed = assertInt(testG.supplyCount[smithy], G.supplyCount[smithy]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("Testing all card supply counts...\t\t");
    passed = assertIntArr(testG.supplyCount,G.supplyCount);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");



    // TEST 5
    printf("\n\nTEST %i STARTED\n", testNumber++);
    printf("supplyCount[adventurer] = 0\tsupplyCount[village] = 0\tsupplyCount[province] = 0\n\n");
    memcpy(&G, &BASE, sizeof(struct gameState));

    G.supplyCount[province] = 0;
    G.supplyCount[adventurer] = 0;
    G.supplyCount[village] = 0;
    gameOver = 0;

    memcpy(&testG, &G, sizeof(struct gameState));
    testGameOver = isGameOver(&testG);

    gameOver = 0;

    printf("gameOver: %i, expected: %i...\t\t\t", gameOver, gameOver+1);
    passed = assertInt(testGameOver, gameOver+1);
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

    printf("supplyCount[smithy]: %i, expected: %i...\t", testG.supplyCount[smithy], G.supplyCount[smithy]);
    passed = assertInt(testG.supplyCount[smithy], G.supplyCount[smithy]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("Testing all card supply counts...\t\t");
    passed = assertIntArr(testG.supplyCount,G.supplyCount);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");



    // TEST 6
    printf("\n\nTEST %i STARTED\n", testNumber++);
    printf("supplyCount[adventurer] = 0\tsupplyCount[village] = 0\tsupplyCount[province] = 4\n\n");
    memcpy(&G, &BASE, sizeof(struct gameState));

    G.supplyCount[province] = 4;
    G.supplyCount[adventurer] = 0;
    G.supplyCount[village] = 0;
    gameOver = 0;

    memcpy(&testG, &G, sizeof(struct gameState));
    testGameOver = isGameOver(&testG);

    gameOver = 0;

    printf("gameOver: %i, expected: %i...\t\t\t", gameOver, gameOver);
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

    printf("supplyCount[smithy]: %i, expected: %i...\t", testG.supplyCount[smithy], G.supplyCount[smithy]);
    passed = assertInt(testG.supplyCount[smithy], G.supplyCount[smithy]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("Testing all card supply counts...\t\t");
    passed = assertIntArr(testG.supplyCount,G.supplyCount);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");



    // TEST 7
    printf("\n\nTEST %i STARTED\n", testNumber++);
    printf("supplyCount[adventurer] = 0\tsupplyCount[village] = 0\tsupplyCount[smithy] = 0\n\n");
    memcpy(&G, &BASE, sizeof(struct gameState));

    G.supplyCount[adventurer] = 0;
    G.supplyCount[village] = 0;
    G.supplyCount[smithy] = 0;
    gameOver = 0;

    memcpy(&testG, &G, sizeof(struct gameState));
    testGameOver = isGameOver(&testG);

    gameOver = 0;

    printf("gameOver: %i, expected: %i...\t\t\t", gameOver, gameOver+1);
    passed = assertInt(testGameOver, gameOver+1);
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

    printf("supplyCount[smithy]: %i, expected: %i...\t\t", testG.supplyCount[smithy], G.supplyCount[smithy]);
    passed = assertInt(testG.supplyCount[smithy], G.supplyCount[smithy]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("Testing all card supply counts...\t\t");
    passed = assertIntArr(testG.supplyCount,G.supplyCount);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");


    // TEST 8
    printf("\n\nTEST %i STARTED\n", testNumber++);
    printf("supplyCount[province] = 0\tsupplyCount[adventurer] = 0\tsupplyCount[village] = 0\tsupplyCount[smithy] = 0\n\n");
    memcpy(&G, &BASE, sizeof(struct gameState));

    G.supplyCount[province] = 0;
    G.supplyCount[adventurer] = 0;
    G.supplyCount[village] = 0;
    G.supplyCount[smithy] = 0;
    gameOver = 0;

    memcpy(&testG, &G, sizeof(struct gameState));
    testGameOver = isGameOver(&testG);

    gameOver = 0;

    printf("gameOver: %i, expected: %i...\t\t\t", gameOver, gameOver+1);
    passed = assertInt(testGameOver, gameOver+1);
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

    printf("supplyCount[smithy]: %i, expected: %i...\t\t", testG.supplyCount[smithy], G.supplyCount[smithy]);
    passed = assertInt(testG.supplyCount[smithy], G.supplyCount[smithy]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("Testing all card supply counts...\t\t");
    passed = assertIntArr(testG.supplyCount,G.supplyCount);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");



    // TEST 9
    printf("\n\nTEST %i STARTED\n", testNumber++);
    printf("supplyCount[province] = 4\tsupplyCount[adventurer] = 0\tsupplyCount[village] = 0\tsupplyCount[smithy] = 0\n\n");
    memcpy(&G, &BASE, sizeof(struct gameState));

    G.supplyCount[province] = 4;
    G.supplyCount[adventurer] = 0;
    G.supplyCount[village] = 0;
    G.supplyCount[smithy] = 0;
    gameOver = 0;

    memcpy(&testG, &G, sizeof(struct gameState));
    testGameOver = isGameOver(&testG);

    gameOver = 0;

    printf("gameOver: %i, expected: %i...\t\t\t", gameOver, gameOver+1);
    passed = assertInt(testGameOver, gameOver+1);
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

    printf("supplyCount[smithy]: %i, expected: %i...\t\t", testG.supplyCount[smithy], G.supplyCount[smithy]);
    passed = assertInt(testG.supplyCount[smithy], G.supplyCount[smithy]);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");

    printf("Testing all card supply counts...\t\t");
    passed = assertIntArr(testG.supplyCount,G.supplyCount);
    if (passed) printf("PASSED\n");
    else printf("FAILED\n");


    return 0;
}
