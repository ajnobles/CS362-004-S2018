// SMITHY
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
    // GAME SETUP
    int numPlayers = 2;
    int kingdomCards[10] = {adventurer, smithy, gardens, village, council_room, minion, steward, great_hall, tribute, ambassador};
    int seed = 1000,
        passed;

    struct gameState BASE, G, testG;
    initializeGame(numPlayers, kingdomCards, seed, &BASE);


    // GENERAL CARD IMPLEMENTATION VARIABLES
    int retVal,
        retValTest,
        testNumber = 1,
        card,
        choice1 = 0,
        choice2 = 0,
        choice3 = 0,
        handPos = 0,
        bonus;

    // FUNCTION SPECIFIC
    int currentPlayer;


        // TEST 1
        printf("\n\nCARD EFFECT: TEST %i STARTED\n", testNumber++);
        printf("Test Initial Game Implementation\n\n");
        memcpy(&G, &BASE, sizeof(struct gameState));
        retVal = 0;
        card = smithy;

        currentPlayer = whoseTurn(&G);
        gainCard(card, &G, 2, currentPlayer);
        handPos = G.handCount[currentPlayer]-1;
        // STAGE HAND/DECK

        memcpy(&testG, &G, sizeof(struct gameState));
        retValTest = cardEffect(card, choice1, choice2, choice3, &testG, handPos, &bonus);

        printf("return value: %i, expected: %i\t\t", retVal, retVal);
        passed = assertInt(retVal, retValTest);
        if (passed) printf("PASSED\n");
        else printf("FAILED\treturn value: %i\n", retValTest);

        printf("handCount: %i, expected: %i\t\t", G.handCount[currentPlayer], G.handCount[currentPlayer]+3-1);
        passed = assertInt(testG.handCount[currentPlayer], G.handCount[currentPlayer]+3-1);
        if (passed) printf("PASSED\n");
        else printf("FAILED\thandCount: %i\n", testG.handCount[currentPlayer]);

        printf("deckCount+discardCount: %i, expected: %i\t", G.deckCount[currentPlayer]+G.discardCount[currentPlayer], G.deckCount[currentPlayer]+G.discardCount[currentPlayer]-3);
        passed = assertInt(testG.deckCount[currentPlayer]+testG.discardCount[currentPlayer], G.deckCount[currentPlayer]+G.discardCount[currentPlayer]-3);
        if (passed) printf("PASSED\n");
        else printf("FAILED\thandCount: %i\n", testG.deckCount[currentPlayer]+testG.discardCount[currentPlayer]);


        // TEST 2
        printf("\n\nCARD EFFECT: TEST %i STARTED\n", testNumber++);
        printf("Set deckCount to 0\n\n");
        memcpy(&G, &BASE, sizeof(struct gameState));
        retVal = 0;
        card = smithy;

        currentPlayer = whoseTurn(&G);
        gainCard(card, &G, 2, currentPlayer);
        handPos = G.handCount[currentPlayer]-1;

        // STAGE HAND/DECK
        G.deckCount[currentPlayer] = 0;

        memcpy(&testG, &G, sizeof(struct gameState));
        // printHand(testG.whoseTurn, &testG);
        retValTest = cardEffect(card, choice1, choice2, choice3, &testG, handPos, &bonus);
        // printHand(testG.whoseTurn, &testG);

        printf("return value: %i, expected: %i\t\t", retVal, retVal);
        passed = assertInt(retVal, retValTest);
        if (passed) printf("PASSED\n");
        else printf("FAILED\treturn value: %i\n", retValTest);

        printf("handCount: %i, expected: %i\t\t", G.handCount[currentPlayer], G.handCount[currentPlayer]+3-1);
        passed = assertInt(testG.handCount[currentPlayer], G.handCount[currentPlayer]+3-1);
        if (passed) printf("PASSED\n");
        else printf("FAILED\thandCount: %i\n", testG.handCount[currentPlayer]);

        printf("deckCount+discardCount: %i, expected: %i\t", G.deckCount[currentPlayer]+G.discardCount[currentPlayer], G.deckCount[currentPlayer]+G.discardCount[currentPlayer]-3);
        passed = assertInt(testG.deckCount[currentPlayer]+testG.discardCount[currentPlayer], G.deckCount[currentPlayer]+G.discardCount[currentPlayer]-3);
        if (passed) printf("PASSED\n");
        else printf("FAILED\thandCount: %i\n", testG.deckCount[currentPlayer]+testG.discardCount[currentPlayer]);



        // TEST 3
        printf("\n\nCARD EFFECT: TEST %i STARTED\n", testNumber++);
        printf("Set deckCount and discardCount to 0\n\n");
        memcpy(&G, &BASE, sizeof(struct gameState));
        retVal = 0;
        card = smithy;

        currentPlayer = whoseTurn(&G);

        // STAGE HAND/DECK
        G.deckCount[currentPlayer] = 0;
        G.discardCount[currentPlayer] = 0;
        gainCard(card, &G, 2, currentPlayer);
        handPos = G.handCount[currentPlayer]-1;

        memcpy(&testG, &G, sizeof(struct gameState));
        retValTest = cardEffect(card, choice1, choice2, choice3, &testG, handPos, &bonus);

        printf("return value: %i, expected: %i\t\t", retVal, retVal);
        passed = assertInt(retVal, retValTest);
        if (passed) printf("PASSED\n");
        else printf("FAILED\treturn value: %i\n", retValTest);

        printf("handCount: %i, expected: %i\t\t", G.handCount[currentPlayer], G.handCount[currentPlayer]+3-1);
        passed = assertInt(testG.handCount[currentPlayer], G.handCount[currentPlayer]+3-1);
        if (passed) printf("PASSED\n");
        else printf("FAILED\thandCount: %i\n", testG.handCount[currentPlayer]);

        printf("deckCount+discardCount: %i, expected: %i\t", G.deckCount[currentPlayer]+G.discardCount[currentPlayer], G.deckCount[currentPlayer]+G.discardCount[currentPlayer]-3);
        passed = assertInt(testG.deckCount[currentPlayer]+testG.discardCount[currentPlayer], G.deckCount[currentPlayer]+G.discardCount[currentPlayer]-3);
        if (passed) printf("PASSED\n");
        else printf("FAILED\thandCount: %i\n", testG.deckCount[currentPlayer]+testG.discardCount[currentPlayer]);



        // TEST 4
        printf("\n\nCARD EFFECT: TEST %i STARTED\n", testNumber++);
        printf("Set handCount, deckCount and discardCount to 0, then add Smithy to Hand\n\n");
        memcpy(&G, &BASE, sizeof(struct gameState));
        retVal = 0;
        card = smithy;

        currentPlayer = whoseTurn(&G);

        // STAGE HAND/DECK
        G.deckCount[currentPlayer] = 0;
        G.discardCount[currentPlayer] = 0;
        G.handCount[currentPlayer] = 0;
        gainCard(card, &G, 2, currentPlayer);
        handPos = G.handCount[currentPlayer]-1;

        memcpy(&testG, &G, sizeof(struct gameState));
        retValTest = cardEffect(card, choice1, choice2, choice3, &testG, handPos, &bonus);

        printf("return value: %i, expected: %i\t\t", retVal, retVal);
        passed = assertInt(retVal, retValTest);
        if (passed) printf("PASSED\n");
        else printf("FAILED\treturn value: %i\n", retValTest);

        printf("handCount: %i, expected: %i\t\t", G.handCount[currentPlayer], G.handCount[currentPlayer]+3-1);
        passed = assertInt(testG.handCount[currentPlayer], G.handCount[currentPlayer]+3-1);
        if (passed) printf("PASSED\n");
        else printf("FAILED\thandCount: %i\n", testG.handCount[currentPlayer]);

        printf("deckCount+discardCount: %i, expected: %i\t", G.deckCount[currentPlayer]+G.discardCount[currentPlayer], G.deckCount[currentPlayer]+G.discardCount[currentPlayer]-3);
        passed = assertInt(testG.deckCount[currentPlayer]+testG.discardCount[currentPlayer], G.deckCount[currentPlayer]+G.discardCount[currentPlayer]-3);
        if (passed) printf("PASSED\n");
        else printf("FAILED\thandCount: %i\n", testG.deckCount[currentPlayer]+testG.discardCount[currentPlayer]);


        testNumber = 1;
        // TEST 1
        printf("\n\nFUNCTION: TEST %i STARTED\n", testNumber++);
        printf("Test Initial Game Implementation\n\n");
        memcpy(&G, &BASE, sizeof(struct gameState));
        retVal = 0;
        card = smithy;

        currentPlayer = whoseTurn(&G);
        gainCard(card, &G, 2, currentPlayer);
        handPos = G.handCount[currentPlayer]-1;
        // STAGE HAND/DECK

        memcpy(&testG, &G, sizeof(struct gameState));
        retValTest = smithyRefactor(card, choice1, choice2, choice3, &testG, handPos, &bonus);

        printf("return value: %i, expected: %i\t\t", retVal, retVal);
        passed = assertInt(retVal, retValTest);
        if (passed) printf("PASSED\n");
        else printf("FAILED\treturn value: %i\n", retValTest);

        printf("handCount: %i, expected: %i\t\t", G.handCount[currentPlayer], G.handCount[currentPlayer]+3-1);
        passed = assertInt(testG.handCount[currentPlayer], G.handCount[currentPlayer]+3-1);
        if (passed) printf("PASSED\n");
        else printf("FAILED\thandCount: %i\n", testG.handCount[currentPlayer]);

        printf("deckCount+discardCount: %i, expected: %i\t", G.deckCount[currentPlayer]+G.discardCount[currentPlayer], G.deckCount[currentPlayer]+G.discardCount[currentPlayer]-3);
        passed = assertInt(testG.deckCount[currentPlayer]+testG.discardCount[currentPlayer], G.deckCount[currentPlayer]+G.discardCount[currentPlayer]-3);
        if (passed) printf("PASSED\n");
        else printf("FAILED\thandCount: %i\n", testG.deckCount[currentPlayer]+testG.discardCount[currentPlayer]);


        // TEST 2
        printf("\n\nFUNCTION: TEST %i STARTED\n", testNumber++);
        printf("Set deckCount to 0\n\n");
        memcpy(&G, &BASE, sizeof(struct gameState));
        retVal = 0;
        card = smithy;

        currentPlayer = whoseTurn(&G);
        gainCard(card, &G, 2, currentPlayer);
        handPos = G.handCount[currentPlayer]-1;

        // STAGE HAND/DECK
        G.deckCount[currentPlayer] = 0;

        memcpy(&testG, &G, sizeof(struct gameState));
        // printHand(testG.whoseTurn, &testG);
        retValTest = smithyRefactor(card, choice1, choice2, choice3, &testG, handPos, &bonus);
        // printHand(testG.whoseTurn, &testG);

        printf("return value: %i, expected: %i\t\t", retVal, retVal);
        passed = assertInt(retVal, retValTest);
        if (passed) printf("PASSED\n");
        else printf("FAILED\treturn value: %i\n", retValTest);

        printf("handCount: %i, expected: %i\t\t", G.handCount[currentPlayer], G.handCount[currentPlayer]+3-1);
        passed = assertInt(testG.handCount[currentPlayer], G.handCount[currentPlayer]+3-1);
        if (passed) printf("PASSED\n");
        else printf("FAILED\thandCount: %i\n", testG.handCount[currentPlayer]);

        printf("deckCount+discardCount: %i, expected: %i\t", G.deckCount[currentPlayer]+G.discardCount[currentPlayer], G.deckCount[currentPlayer]+G.discardCount[currentPlayer]-3);
        passed = assertInt(testG.deckCount[currentPlayer]+testG.discardCount[currentPlayer], G.deckCount[currentPlayer]+G.discardCount[currentPlayer]-3);
        if (passed) printf("PASSED\n");
        else printf("FAILED\thandCount: %i\n", testG.deckCount[currentPlayer]+testG.discardCount[currentPlayer]);



        // TEST 3
        printf("\n\nFUNCTION: TEST %i STARTED\n", testNumber++);
        printf("Set deckCount and discardCount to 0\n\n");
        memcpy(&G, &BASE, sizeof(struct gameState));
        retVal = 0;
        card = smithy;

        currentPlayer = whoseTurn(&G);

        // STAGE HAND/DECK
        G.deckCount[currentPlayer] = 0;
        G.discardCount[currentPlayer] = 0;
        gainCard(card, &G, 2, currentPlayer);
        handPos = G.handCount[currentPlayer]-1;

        memcpy(&testG, &G, sizeof(struct gameState));
        retValTest = smithyRefactor(card, choice1, choice2, choice3, &testG, handPos, &bonus);

        printf("return value: %i, expected: %i\t\t", retVal, retVal);
        passed = assertInt(retVal, retValTest);
        if (passed) printf("PASSED\n");
        else printf("FAILED\treturn value: %i\n", retValTest);

        printf("handCount: %i, expected: %i\t\t", G.handCount[currentPlayer], G.handCount[currentPlayer]+3-1);
        passed = assertInt(testG.handCount[currentPlayer], G.handCount[currentPlayer]+3-1);
        if (passed) printf("PASSED\n");
        else printf("FAILED\thandCount: %i\n", testG.handCount[currentPlayer]);

        printf("deckCount+discardCount: %i, expected: %i\t", G.deckCount[currentPlayer]+G.discardCount[currentPlayer], G.deckCount[currentPlayer]+G.discardCount[currentPlayer]-3);
        passed = assertInt(testG.deckCount[currentPlayer]+testG.discardCount[currentPlayer], G.deckCount[currentPlayer]+G.discardCount[currentPlayer]-3);
        if (passed) printf("PASSED\n");
        else printf("FAILED\thandCount: %i\n", testG.deckCount[currentPlayer]+testG.discardCount[currentPlayer]);



        // TEST 4
        printf("\n\nFUNCTION: TEST %i STARTED\n", testNumber++);
        printf("Set handCount, deckCount and discardCount to 0, then add Smithy to Hand\n\n");
        memcpy(&G, &BASE, sizeof(struct gameState));
        retVal = 0;
        card = smithy;

        currentPlayer = whoseTurn(&G);

        // STAGE HAND/DECK
        G.deckCount[currentPlayer] = 0;
        G.discardCount[currentPlayer] = 0;
        G.handCount[currentPlayer] = 0;
        gainCard(card, &G, 2, currentPlayer);
        handPos = G.handCount[currentPlayer]-1;

        memcpy(&testG, &G, sizeof(struct gameState));
        retValTest = smithyRefactor(card, choice1, choice2, choice3, &testG, handPos, &bonus);

        printf("return value: %i, expected: %i\t\t", retVal, retVal);
        passed = assertInt(retVal, retValTest);
        if (passed) printf("PASSED\n");
        else printf("FAILED\treturn value: %i\n", retValTest);

        printf("handCount: %i, expected: %i\t\t", G.handCount[currentPlayer], G.handCount[currentPlayer]+3-1);
        passed = assertInt(testG.handCount[currentPlayer], G.handCount[currentPlayer]+3-1);
        if (passed) printf("PASSED\n");
        else printf("FAILED\thandCount: %i\n", testG.handCount[currentPlayer]);

        printf("deckCount+discardCount: %i, expected: %i\t", G.deckCount[currentPlayer]+G.discardCount[currentPlayer], G.deckCount[currentPlayer]+G.discardCount[currentPlayer]-3);
        passed = assertInt(testG.deckCount[currentPlayer]+testG.discardCount[currentPlayer], G.deckCount[currentPlayer]+G.discardCount[currentPlayer]-3);
        if (passed) printf("PASSED\n");
        else printf("FAILED\thandCount: %i\n", testG.deckCount[currentPlayer]+testG.discardCount[currentPlayer]);


    return 0;
}
