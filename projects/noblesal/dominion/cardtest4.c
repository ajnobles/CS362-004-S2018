// COUNCIL ROOM
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
    int i, currentPlayer;

    // TEST 1
    printf("TEST %i STARTED\n", testNumber);
    memcpy(&G, &BASE, sizeof(struct gameState));
    retVal = 0;
    card = council_room;

    currentPlayer = whoseTurn(&G);

    // STAGE HAND/DECK

    memcpy(&testG, &G, sizeof(struct gameState));
    retValTest = council_roomRefactor(card, choice1, choice2, choice3, &testG, handPos, &bonus);

    // FOR TESTING
    if (printTestHand) {
        printf("PRE-TEST HANDS\n");
        printHand(currentPlayer, &G);
        printDeck(currentPlayer, &G);
        printPlayed(currentPlayer, &G);
        printDiscard(currentPlayer, &G);
    }

    currentPlayer = whoseTurn(&G);

    for (i = 0; i < 4; i++) {
        drawCard(currentPlayer, &G);
    }

    G.numBuys++;

    for(i = 0; i < G.numPlayers; i++) {
        if (i != currentPlayer) {
            drawCard(i, &G);
        }
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

    printf("Testing Cards in Players Hand\n");
    for (int i = 0; i < G.handCount[currentPlayer]; i++) {
        // assert(G.hand[currentPlayer][i] == testG.hand[currentPlayer][i]);
    }

    printf("deckCount: %i, expected: %i\n", testG.deckCount[currentPlayer], G.deckCount[currentPlayer]);
    // assert(G.deckCount[currentPlayer] == testG.deckCount[currentPlayer]);

    printf("Testing Cards in Players Deck\n");
    for (int i = 0; i < G.deckCount[currentPlayer]; i++) {
        assert(G.deck[currentPlayer][i] == testG.deck[currentPlayer][i]);
    }

    printf("discardCount: %i, expected: %i\n", testG.discardCount[currentPlayer], G.discardCount[currentPlayer]);
    assert(G.discardCount[currentPlayer] == testG.discardCount[currentPlayer]);

    printf("Testing Cards in Players Discard Pile\n");
    for (int i = 0; i < G.discardCount[currentPlayer]; i++) {
        assert(G.discard[currentPlayer][i] == testG.discard[currentPlayer][i]);
    }

    printf("numBuys: %i, expected: %i\n", testG.numBuys, G.numBuys);
    assert(G.numBuys == testG.numBuys);

    printf("TEST %i PASSED\n\n", testNumber++);

    // TEST 2
    printf("TEST %i STARTED\n", testNumber);
    memcpy(&G, &BASE, sizeof(struct gameState));
    retVal = 0;
    card = council_room;

    currentPlayer = whoseTurn(&G);

    // STAGE HAND/DECK
    G.deckCount[currentPlayer] = 0;

    memcpy(&testG, &G, sizeof(struct gameState));
    retValTest = council_roomRefactor(card, choice1, choice2, choice3, &testG, handPos, &bonus);

    // FOR TESTING
    if (printTestHand) {
        printf("PRE-TEST HANDS\n");
        printHand(currentPlayer, &G);
        printDeck(currentPlayer, &G);
        printPlayed(currentPlayer, &G);
        printDiscard(currentPlayer, &G);
    }

    currentPlayer = whoseTurn(&G);

    for (i = 0; i < 4; i++) {
        drawCard(currentPlayer, &G);
    }

    G.numBuys++;

    for(i = 0; i < G.numPlayers; i++) {
        if (i != currentPlayer) {
            drawCard(i, &G);
        }
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

    printf("Testing Cards in Players Hand\n");
    for (int i = 0; i < G.handCount[currentPlayer]; i++) {
        // assert(G.hand[currentPlayer][i] == testG.hand[currentPlayer][i]);
    }

    printf("deckCount: %i, expected: %i\n", testG.deckCount[currentPlayer], G.deckCount[currentPlayer]);
    // assert(G.deckCount[currentPlayer] == testG.deckCount[currentPlayer]);

    printf("Testing Cards in Players Deck\n");
    for (int i = 0; i < G.deckCount[currentPlayer]; i++) {
        assert(G.deck[currentPlayer][i] == testG.deck[currentPlayer][i]);
    }

    printf("discardCount: %i, expected: %i\n", testG.discardCount[currentPlayer], G.discardCount[currentPlayer]);
    assert(G.discardCount[currentPlayer] == testG.discardCount[currentPlayer]);

    printf("Testing Cards in Players Discard Pile\n");
    for (int i = 0; i < G.discardCount[currentPlayer]; i++) {
        assert(G.discard[currentPlayer][i] == testG.discard[currentPlayer][i]);
    }

    printf("numBuys: %i, expected: %i\n", testG.numBuys, G.numBuys);
    assert(G.numBuys == testG.numBuys);

    printf("TEST %i PASSED\n\n", testNumber++);

    // TEST 3
    printf("TEST %i STARTED\n", testNumber);
    memcpy(&G, &BASE, sizeof(struct gameState));
    retVal = 0;
    card = council_room;

    currentPlayer = whoseTurn(&G);

    // STAGE HAND/DECK
    G.deckCount[currentPlayer] = 0;
    G.discardCount[currentPlayer] = 0;

    memcpy(&testG, &G, sizeof(struct gameState));
    retValTest = council_roomRefactor(card, choice1, choice2, choice3, &testG, handPos, &bonus);

    // FOR TESTING
    if (printTestHand) {
        printf("PRE-TEST HANDS\n");
        printHand(currentPlayer, &G);
        printDeck(currentPlayer, &G);
        printPlayed(currentPlayer, &G);
        printDiscard(currentPlayer, &G);
    }

    currentPlayer = whoseTurn(&G);

    for (i = 0; i < 4; i++) {
        drawCard(currentPlayer, &G);
    }

    G.numBuys++;

    for(i = 0; i < G.numPlayers; i++) {
        if (i != currentPlayer) {
            drawCard(i, &G);
        }
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

    printf("Testing Cards in Players Hand\n");
    for (int i = 0; i < G.handCount[currentPlayer]; i++) {
        // assert(G.hand[currentPlayer][i] == testG.hand[currentPlayer][i]);
    }

    printf("deckCount: %i, expected: %i\n", testG.deckCount[currentPlayer], G.deckCount[currentPlayer]);
    // assert(G.deckCount[currentPlayer] == testG.deckCount[currentPlayer]);

    printf("Testing Cards in Players Deck\n");
    for (int i = 0; i < G.deckCount[currentPlayer]; i++) {
        assert(G.deck[currentPlayer][i] == testG.deck[currentPlayer][i]);
    }

    printf("discardCount: %i, expected: %i\n", testG.discardCount[currentPlayer], G.discardCount[currentPlayer]);
    assert(G.discardCount[currentPlayer] == testG.discardCount[currentPlayer]);

    printf("Testing Cards in Players Discard Pile\n");
    for (int i = 0; i < G.discardCount[currentPlayer]; i++) {
        assert(G.discard[currentPlayer][i] == testG.discard[currentPlayer][i]);
    }

    printf("numBuys: %i, expected: %i\n", testG.numBuys, G.numBuys);
    assert(G.numBuys == testG.numBuys);

    printf("TEST %i PASSED\n\n", testNumber++);


    // TEST 4
    printf("TEST %i STARTED\n", testNumber);
    memcpy(&G, &BASE, sizeof(struct gameState));
    retVal = 0;
    card = council_room;

    currentPlayer = whoseTurn(&G);

    // STAGE HAND/DECK
    G.deckCount[currentPlayer] = 0;
    G.discardCount[currentPlayer] = 0;
    G.handCount[currentPlayer] = 0;

    memcpy(&testG, &G, sizeof(struct gameState));
    retValTest = council_roomRefactor(card, choice1, choice2, choice3, &testG, handPos, &bonus);

    // FOR TESTING
    if (printTestHand) {
        printf("PRE-TEST HANDS\n");
        printHand(currentPlayer, &G);
        printDeck(currentPlayer, &G);
        printPlayed(currentPlayer, &G);
        printDiscard(currentPlayer, &G);
    }

    currentPlayer = whoseTurn(&G);

    for (i = 0; i < 4; i++) {
        drawCard(currentPlayer, &G);
    }

    G.numBuys++;

    for(i = 0; i < G.numPlayers; i++) {
        if (i != currentPlayer) {
            drawCard(i, &G);
        }
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

    printf("Testing Cards in Players Hand\n");
    for (int i = 0; i < G.handCount[currentPlayer]; i++) {
        // assert(G.hand[currentPlayer][i] == testG.hand[currentPlayer][i]);
    }

    printf("deckCount: %i, expected: %i\n", testG.deckCount[currentPlayer], G.deckCount[currentPlayer]);
    // assert(G.deckCount[currentPlayer] == testG.deckCount[currentPlayer]);

    printf("Testing Cards in Players Deck\n");
    for (int i = 0; i < G.deckCount[currentPlayer]; i++) {
        assert(G.deck[currentPlayer][i] == testG.deck[currentPlayer][i]);
    }

    printf("discardCount: %i, expected: %i\n", testG.discardCount[currentPlayer], G.discardCount[currentPlayer]);
    assert(G.discardCount[currentPlayer] == testG.discardCount[currentPlayer]);

    printf("Testing Cards in Players Discard Pile\n");
    for (int i = 0; i < G.discardCount[currentPlayer]; i++) {
        assert(G.discard[currentPlayer][i] == testG.discard[currentPlayer][i]);
    }

    printf("numBuys: %i, expected: %i\n", testG.numBuys, G.numBuys);
    assert(G.numBuys == testG.numBuys);

    printf("TEST %i PASSED\n\n", testNumber++);

    return 0;
}
