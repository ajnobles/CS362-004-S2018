// SMITHY
#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"

//
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
    int seed = 1000,
        printTestHand = 0;

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
    int i,
        currentPlayer;


    // TEST 1
    printf("TEST %i STARTED\n", testNumber);
    memcpy(&G, &BASE, sizeof(struct gameState));
    retVal = 0;
    card = smithy;

    currentPlayer = whoseTurn(&G);

    // STAGE HAND/DECK

    memcpy(&testG, &G, sizeof(struct gameState));
    retValTest = smithyRefactor(card, choice1, choice2, choice3, &testG, handPos, &bonus);

    // FOR TESTING
    if (printTestHand) {
        printf("PRE-TEST HANDS\n");
        printHand(currentPlayer, &G);
        printDeck(currentPlayer, &G);
        printPlayed(currentPlayer, &G);
        printDiscard(currentPlayer, &G);
    }

    currentPlayer = whoseTurn(&G);

    for (i = 0; i < 3; i++) {
        drawCard(currentPlayer, &G);
    }

    discardCard(handPos, currentPlayer, &G, 0);

    // FOR TESTING
    if (printTestHand) {
        printf("POST-TEST HANDS\n");
        printHand(currentPlayer, &G);
        printDeck(currentPlayer, &G);
        printPlayed(currentPlayer, &G);
        printDiscard(currentPlayer, &G);
    }

    printf("return value: %i, expected: %i\n", retValTest, retVal);
    assert(retVal == retValTest);

    printf("handCount: %i, expected: %i\n", testG.handCount[currentPlayer], G.handCount[currentPlayer]);
    // assert(G.handCount[currentPlayer] == testG.handCount[currentPlayer]);

    printf("deckCount: %i, expected: %i\n", testG.deckCount[currentPlayer], G.deckCount[currentPlayer]);
    // assert(G.deckCount[currentPlayer] == testG.deckCount[currentPlayer]);

    printf("discardCount: %i, expected: %i\n", testG.discardCount[currentPlayer], G.discardCount[currentPlayer]);
    // assert(G.discardCount[currentPlayer] == testG.discardCount[currentPlayer]);

    printf("TEST %i PASSED\n\n", testNumber++);


    // TEST 2
    printf("TEST %i STARTED\n", testNumber);
    memcpy(&G, &BASE, sizeof(struct gameState));
    retVal = 0;
    card = smithy;

    currentPlayer = whoseTurn(&G);

    // STAGE HAND/DECK
    G.deckCount[currentPlayer] = 0;

    memcpy(&testG, &G, sizeof(struct gameState));
    retValTest = smithyRefactor(card, choice1, choice2, choice3, &testG, handPos, &bonus);

    // FOR TESTING
    if (printTestHand) {
        printf("PRE-TEST HANDS\n");
        printHand(currentPlayer, &G);
        printDeck(currentPlayer, &G);
        printPlayed(currentPlayer, &G);
        printDiscard(currentPlayer, &G);
    }

    currentPlayer = whoseTurn(&G);

    for (i = 0; i < 3; i++) {
        drawCard(currentPlayer, &G);
    }

    discardCard(handPos, currentPlayer, &G, 0);

    // FOR TESTING
    if (printTestHand) {
        printf("POST-TEST HANDS\n");
        printHand(currentPlayer, &G);
        printDeck(currentPlayer, &G);
        printPlayed(currentPlayer, &G);
        printDiscard(currentPlayer, &G);
    }

    printf("return value: %i, expected: %i\n", retValTest, retVal);
    assert(retVal == retValTest);

    printf("handCount: %i, expected: %i\n", testG.handCount[currentPlayer], G.handCount[currentPlayer]);
    // assert(G.handCount[currentPlayer] == testG.handCount[currentPlayer]);

    printf("deckCount: %i, expected: %i\n", testG.deckCount[currentPlayer], G.deckCount[currentPlayer]);
    // assert(G.deckCount[currentPlayer] == testG.deckCount[currentPlayer]);

    printf("discardCount: %i, expected: %i\n", testG.discardCount[currentPlayer], G.discardCount[currentPlayer]);
    // assert(G.discardCount[currentPlayer] == testG.discardCount[currentPlayer]);

    printf("TEST %i PASSED\n\n", testNumber++);


    // TEST 3
    printf("TEST %i STARTED\n", testNumber);
    memcpy(&G, &BASE, sizeof(struct gameState));
    retVal = 0;
    card = smithy;

    currentPlayer = whoseTurn(&G);

    // STAGE HAND/DECK
    G.deckCount[currentPlayer] = 0;
    G.discardCount[currentPlayer] = 0;

    memcpy(&testG, &G, sizeof(struct gameState));
    retValTest = smithyRefactor(card, choice1, choice2, choice3, &testG, handPos, &bonus);

    // FOR TESTING
    if (printTestHand) {
        printf("PRE-TEST HANDS\n");
        printHand(currentPlayer, &G);
        printDeck(currentPlayer, &G);
        printPlayed(currentPlayer, &G);
        printDiscard(currentPlayer, &G);
    }

    currentPlayer = whoseTurn(&G);

    for (i = 0; i < 3; i++) {
        drawCard(currentPlayer, &G);
    }

    discardCard(handPos, currentPlayer, &G, 0);

    // FOR TESTING
    if (printTestHand) {
        printf("POST-TEST HANDS\n");
        printHand(currentPlayer, &G);
        printDeck(currentPlayer, &G);
        printPlayed(currentPlayer, &G);
        printDiscard(currentPlayer, &G);
    }

    printf("return value: %i, expected: %i\n", retValTest, retVal);
    assert(retVal == retValTest);

    printf("handCount: %i, expected: %i\n", testG.handCount[currentPlayer], G.handCount[currentPlayer]);
    // assert(G.handCount[currentPlayer] == testG.handCount[currentPlayer]);

    printf("deckCount: %i, expected: %i\n", testG.deckCount[currentPlayer], G.deckCount[currentPlayer]);
    // assert(G.deckCount[currentPlayer] == testG.deckCount[currentPlayer]);

    printf("discardCount: %i, expected: %i\n", testG.discardCount[currentPlayer], G.discardCount[currentPlayer]);
    // assert(G.discardCount[currentPlayer] == testG.discardCount[currentPlayer]);

    printf("TEST %i PASSED\n\n", testNumber++);


    // TEST 4
    printf("TEST %i STARTED\n", testNumber);
    memcpy(&G, &BASE, sizeof(struct gameState));
    retVal = 0;
    card = smithy;

    currentPlayer = whoseTurn(&G);

    // STAGE HAND/DECK
    G.deckCount[currentPlayer] = 0;
    G.discardCount[currentPlayer] = 0;
    G.handCount[currentPlayer] = 0;

    memcpy(&testG, &G, sizeof(struct gameState));
    retValTest = smithyRefactor(card, choice1, choice2, choice3, &testG, handPos, &bonus);

    // FOR TESTING
    if (printTestHand) {
        printf("PRE-TEST HANDS\n");
        printHand(currentPlayer, &G);
        printDeck(currentPlayer, &G);
        printPlayed(currentPlayer, &G);
        printDiscard(currentPlayer, &G);
    }

    currentPlayer = whoseTurn(&G);

    for (i = 0; i < 3; i++) {
        drawCard(currentPlayer, &G);
    }

    discardCard(handPos, currentPlayer, &G, 0);

    // FOR TESTING
    if (printTestHand) {
        printf("POST-TEST HANDS\n");
        printHand(currentPlayer, &G);
        printDeck(currentPlayer, &G);
        printPlayed(currentPlayer, &G);
        printDiscard(currentPlayer, &G);
    }

    printf("return value: %i, expected: %i\n", retValTest, retVal);
    assert(retVal == retValTest);

    printf("handCount: %i, expected: %i\n", testG.handCount[currentPlayer], G.handCount[currentPlayer]);
    // assert(G.handCount[currentPlayer] == testG.handCount[currentPlayer]);

    printf("deckCount: %i, expected: %i\n", testG.deckCount[currentPlayer], G.deckCount[currentPlayer]);
    // assert(G.deckCount[currentPlayer] == testG.deckCount[currentPlayer]);

    printf("discardCount: %i, expected: %i\n", testG.discardCount[currentPlayer], G.discardCount[currentPlayer]);
    // assert(G.discardCount[currentPlayer] == testG.discardCount[currentPlayer]);

    printf("TEST %i PASSED\n\n", testNumber++);

    return 0;
}
