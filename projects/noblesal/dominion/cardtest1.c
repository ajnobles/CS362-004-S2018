// ADVENTURER  1290
// REVEAL CARDS FROM YOUR DECK UNTIL YOU REVEAL 2 TREASURE CARDS.
//      PUT THOSE THREASURE CARDS INTO YOUR HAND AND DISCARD THE OTHER REVEALED CARDS.
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
        printTestHand = 0;

    struct gameState BASE, G, testG;
    initializeGame(numPlayers, kingdomCards, seed, &BASE);


    // GENERAL CARD IMPLEMENTATION VARIABLES
    int retVal,
        retValTest,
        testNumber = 1,
        choice1 = 0,
        choice2 = 0,
        choice3 = 0,
        handPos = 0,
        bonus;

    // FUNCTION SPECIFIC
    int z,
        temphand[MAX_HAND],
        drawntreasure,
        cardDrawn,
        currentPlayer,
        card;


    // TEST 1
    printf("TEST %i STARTED\n", testNumber);
    memcpy(&G, &BASE, sizeof(struct gameState));

    retVal = 0;
    card = adventurer;

    currentPlayer = whoseTurn(&G);

    memcpy(&testG, &G, sizeof(struct gameState));
    retValTest = adventurerRefactor(card, choice1, choice2, choice3, &testG, handPos, &bonus);


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
    printf("\nTEST %i STARTED\n", testNumber);
    memcpy(&G, &BASE, sizeof(struct gameState));
    printf("G: %p\tBASE: %p\n", &G, &BASE);

    retVal = 0;

    card = adventurer;
    currentPlayer = whoseTurn(&G);

    // STAGE HAND/DECK
    G.deck[currentPlayer][0] = gold;
    G.deck[currentPlayer][1] = gold;
    G.deck[currentPlayer][2] = estate;
    G.deck[currentPlayer][3] = copper;
    G.deck[currentPlayer][4] = estate;

    memcpy(&testG, &G, sizeof(struct gameState));
    retValTest = adventurerRefactor(card, choice1, choice2, choice3, &testG, handPos, &bonus);

    if (printTestHand) {
        printf("PRE-TEST HANDS\n");
        printHand(currentPlayer, &G);
        printDeck(currentPlayer, &G);
        printPlayed(currentPlayer, &G);
        printDiscard(currentPlayer, &G);
    }

    z = 0;
    drawntreasure = 0;
    currentPlayer = whoseTurn(&G);

    while (drawntreasure < 2) {
        if (G.deckCount[currentPlayer] < 1) {
            shuffle(currentPlayer, &G);
        }
        drawCard(currentPlayer, &G);

        cardDrawn = G.hand[currentPlayer][G.handCount[currentPlayer] - 1];

        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) {
            drawntreasure++;
        }

        else {
            temphand[z] = cardDrawn;
            G.handCount[currentPlayer]--;
            z++;
        }
    }

    while(z-1 >= 0) {
        G.discard[currentPlayer][G.discardCount[currentPlayer]++]=temphand[z-1];
        z = z-1;
    }

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
    // NO TREASURE IN DECK
    printf("TEST %i STARTED\n", testNumber);
    memcpy(&G, &BASE, sizeof(struct gameState));
    retVal = 0;
    card = adventurer;

    currentPlayer = whoseTurn(&G);

    // STAGE HAND/DECK test
    G.deck[currentPlayer][0] = estate;
    G.deck[currentPlayer][1] = estate;
    G.deck[currentPlayer][2] = estate;
    G.deck[currentPlayer][3] = estate;
    G.deck[currentPlayer][4] = estate;

    memcpy(&testG, &G, sizeof(struct gameState));
    retValTest = adventurerRefactor(card, choice1, choice2, choice3, &testG, handPos, &bonus);

    if (printTestHand) {
        printf("PRE-TEST HANDS\n");
        printHand(currentPlayer, &G);
        printDeck(currentPlayer, &G);
        printPlayed(currentPlayer, &G);
        printDiscard(currentPlayer, &G);
    }

    z = 0;
    drawntreasure = 0;
    currentPlayer = whoseTurn(&G);

    while (drawntreasure < 2) {
        if (G.deckCount[currentPlayer] < 1) {
            shuffle(currentPlayer, &G);
        }
        drawCard(currentPlayer, &G);

        cardDrawn = G.hand[currentPlayer][G.handCount[currentPlayer] - 1];

        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) {
            drawntreasure++;
        }

        else {
            temphand[z] = cardDrawn;
            G.handCount[currentPlayer]--;
            z++;
        }
    }

    while(z-1 >= 0) {
        G.discard[currentPlayer][G.discardCount[currentPlayer]++]=temphand[z-1];
        z = z-1;
    }

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
    // TEST EMPTY DECK
    printf("TEST %i STARTED\n", testNumber);
    memcpy(&G, &BASE, sizeof(struct gameState));
    retVal = 0;
    card = adventurer;

    currentPlayer = whoseTurn(&G);

    // STAGE HAND/DECK
    G.deckCount[currentPlayer] = 0;

    memcpy(&testG, &G, sizeof(struct gameState));
    retValTest = adventurerRefactor(card, choice1, choice2, choice3, &testG, handPos, &bonus);

    // FOR TESTING
    if (printTestHand) {
        printf("PRE-TEST HANDS\n");
        printHand(currentPlayer, &G);
        printDeck(currentPlayer, &G);
        printPlayed(currentPlayer, &G);
        printDiscard(currentPlayer, &G);
    }

    z = 0;
    drawntreasure = 0;
    currentPlayer = whoseTurn(&G);

    while (drawntreasure < 2) {
        if (G.deckCount[currentPlayer] < 1) {
            shuffle(currentPlayer, &G);
        }
        drawCard(currentPlayer, &G);

        cardDrawn = G.hand[currentPlayer][G.handCount[currentPlayer] - 1];

        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) {
            drawntreasure++;
        }

        else {
            temphand[z] = cardDrawn;
            G.handCount[currentPlayer]--;
            z++;
        }
    }

    while(z-1 >= 0) {
        G.discard[currentPlayer][G.discardCount[currentPlayer]++]=temphand[z-1];
        z = z-1;
    }

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

    // TEST 5
    // TEST EMPTY DECK
    printf("TEST %i STARTED\n", testNumber);
    memcpy(&G, &BASE, sizeof(struct gameState));
    retVal = 0;
    card = adventurer;

    currentPlayer = whoseTurn(&G);

    // STAGE HAND/DECK
    G.deckCount[currentPlayer] = 0;
    G.discardCount[currentPlayer] = 0;

    memcpy(&testG, &G, sizeof(struct gameState));
    retValTest = adventurerRefactor(card, choice1, choice2, choice3, &testG, handPos, &bonus);

    // FOR TESTING
    if (printTestHand) {
        printf("PRE-TEST HANDS\n");
        printHand(currentPlayer, &G);
        printDeck(currentPlayer, &G);
        printPlayed(currentPlayer, &G);
        printDiscard(currentPlayer, &G);
    }

    z = 0;
    drawntreasure = 0;
    currentPlayer = whoseTurn(&G);

    while (drawntreasure < 2) {
        if (G.deckCount[currentPlayer] < 1) {
            shuffle(currentPlayer, &G);
        }
        drawCard(currentPlayer, &G);

        cardDrawn = G.hand[currentPlayer][G.handCount[currentPlayer] - 1];

        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) {
            drawntreasure++;
        }

        else {
            temphand[z] = cardDrawn;
            G.handCount[currentPlayer]--;
            z++;
        }
    }

    while(z-1 >= 0) {
        G.discard[currentPlayer][G.discardCount[currentPlayer]++]=temphand[z-1];
        z = z-1;
    }

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

    // TEST 6
    // TEST EMPTY DECK
    printf("TEST %i STARTED\n", testNumber);
    memcpy(&G, &BASE, sizeof(struct gameState));
    retVal = 0;
    card = adventurer;

    currentPlayer = whoseTurn(&G);

    // STAGE HAND/DECK
    G.deckCount[currentPlayer] = 0;
    G.handCount[currentPlayer] = 0;
    G.discardCount[currentPlayer] = 0;

    memcpy(&testG, &G, sizeof(struct gameState));
    retValTest = adventurerRefactor(card, choice1, choice2, choice3, &testG, handPos, &bonus);

    // FOR TESTING
    if (printTestHand) {
        printf("PRE-TEST HANDS\n");
        printHand(currentPlayer, &G);
        printDeck(currentPlayer, &G);
        printPlayed(currentPlayer, &G);
        printDiscard(currentPlayer, &G);
    }

    z = 0;
    drawntreasure = 0;
    currentPlayer = whoseTurn(&G);

    while (drawntreasure < 2) {
        if (G.deckCount[currentPlayer] < 1) {
            shuffle(currentPlayer, &G);
        }
        drawCard(currentPlayer, &G);

        cardDrawn = G.hand[currentPlayer][G.handCount[currentPlayer] - 1];

        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) {
            drawntreasure++;
        }

        else {
            temphand[z] = cardDrawn;
            G.handCount[currentPlayer]--;
            z++;
        }
    }

    while(z-1 >= 0) {
        G.discard[currentPlayer][G.discardCount[currentPlayer]++]=temphand[z-1];
        z = z-1;
    }

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
