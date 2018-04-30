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
        passed = 0;

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
    int currentPlayer,
        card;


    // TEST 1
    printf("\nTEST %i STARTED\n", testNumber++);
    memcpy(&G, &BASE, sizeof(struct gameState));

    retVal = 0;
    card = adventurer;

    currentPlayer = whoseTurn(&G);

    memcpy(&testG, &G, sizeof(struct gameState));
    retValTest = adventurerRefactor(card, choice1, choice2, choice3, &testG, handPos, &bonus);

    // printHand(G.whoseTurn, &G);
    // printDeck(G.whoseTurn, &G);
    // printDiscard(G.whoseTurn, &G);


    printf("return value: %i, expected: %i\t", retVal, retVal);
    passed = assertInt(retVal, retValTest);
    if (passed) printf("PASSED\n");
    else printf("FAILED\treturn value: %i\n", retValTest);

    printf("handCount: %i, expected: %i\t", G.handCount[currentPlayer], G.handCount[currentPlayer]+2);
    passed = assertInt(testG.handCount[currentPlayer], G.handCount[currentPlayer]+2);
    if (passed) printf("PASSED\n");
    else printf("FAILED\thandCount: %i\n", testG.handCount[currentPlayer]);


    // TEST 2
    printf("\nTEST %i STARTED\n", testNumber++);
    memcpy(&G, &BASE, sizeof(struct gameState));

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

    // printHand(G.whoseTurn, &G);
    // printDeck(G.whoseTurn, &G);
    // printDiscard(G.whoseTurn, &G);


    printf("return value: %i, expected: %i\t", retVal, retVal);
    passed = assertInt(retVal, retValTest);
    if (passed) printf("PASSED\n");
    else printf("FAILED\treturn value: %i\n", retValTest);

    printf("handCount: %i, expected: %i\t", G.handCount[currentPlayer], G.handCount[currentPlayer]+2);
    passed = assertInt(testG.handCount[currentPlayer], G.handCount[currentPlayer]+2);
    if (passed) printf("PASSED\n");
    else printf("FAILED\thandCount: %i\n", testG.handCount[currentPlayer]);


    // TEST 3
    // NO TREASURE IN DECK
    printf("\nTEST %i STARTED\n", testNumber++);
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

    // printHand(G.whoseTurn, &G);
    // printDeck(G.whoseTurn, &G);
    // printDiscard(G.whoseTurn, &G);


    printf("return value: %i, expected: %i\t", retVal, retVal);
    passed = assertInt(retVal, retValTest);
    if (passed) printf("PASSED\n");
    else printf("FAILED\treturn value: %i\n", retValTest);

    printf("handCount: %i, expected: %i\t", G.handCount[currentPlayer], G.handCount[currentPlayer]+2);
    passed = assertInt(testG.handCount[currentPlayer], G.handCount[currentPlayer]+2);
    if (passed) printf("PASSED\n");
    else printf("FAILED\thandCount: %i\n", testG.handCount[currentPlayer]);

    // TEST 4
    // TEST EMPTY DECK
    printf("\nTEST %i STARTED\n", testNumber++);
    memcpy(&G, &BASE, sizeof(struct gameState));
    retVal = 0;
    card = adventurer;

    currentPlayer = whoseTurn(&G);

    // STAGE HAND/DECK
    G.deckCount[currentPlayer] = 0;

    memcpy(&testG, &G, sizeof(struct gameState));
    retValTest = adventurerRefactor(card, choice1, choice2, choice3, &testG, handPos, &bonus);

    // printHand(G.whoseTurn, &G);
    // printDeck(G.whoseTurn, &G);
    // printDiscard(G.whoseTurn, &G);


    printf("return value: %i, expected: %i\t", retVal, retVal);
    passed = assertInt(retVal, retValTest);
    if (passed) printf("PASSED\n");
    else printf("FAILED\treturn value: %i\n", retValTest);

    printf("handCount: %i, expected: %i\t", G.handCount[currentPlayer], G.handCount[currentPlayer]+2);
    passed = assertInt(testG.handCount[currentPlayer], G.handCount[currentPlayer]+2);
    if (passed) printf("PASSED\n");
    else printf("FAILED\thandCount: %i\n", testG.handCount[currentPlayer]);

    // TEST 5
    // TEST EMPTY DECK
    printf("\nTEST %i STARTED\n", testNumber++);
    memcpy(&G, &BASE, sizeof(struct gameState));
    retVal = 0;
    card = adventurer;

    currentPlayer = whoseTurn(&G);

    // STAGE HAND/DECK
    G.deckCount[currentPlayer] = 0;
    G.discardCount[currentPlayer] = 0;

    memcpy(&testG, &G, sizeof(struct gameState));
    retValTest = adventurerRefactor(card, choice1, choice2, choice3, &testG, handPos, &bonus);

    // printHand(G.whoseTurn, &G);
    // printDeck(G.whoseTurn, &G);
    // printDiscard(G.whoseTurn, &G);


    printf("return value: %i, expected: %i\t", retVal, retVal);
    passed = assertInt(retVal, retValTest);
    if (passed) printf("PASSED\n");
    else printf("FAILED\treturn value: %i\n", retValTest);

    printf("handCount: %i, expected: %i\t", G.handCount[currentPlayer], G.handCount[currentPlayer]+2);
    passed = assertInt(testG.handCount[currentPlayer], G.handCount[currentPlayer]+2);
    if (passed) printf("PASSED\n");
    else printf("FAILED\thandCount: %i\n", testG.handCount[currentPlayer]);

    // TEST 6
    // TEST EMPTY DECK
    printf("\nTEST %i STARTED\n", testNumber++);
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

    // printHand(G.whoseTurn, &G);
    // printDeck(G.whoseTurn, &G);
    // printDiscard(G.whoseTurn, &G);


    printf("return value: %i, expected: %i\t", retVal, retVal);
    passed = assertInt(retVal, retValTest);
    if (passed) printf("PASSED\n");
    else printf("FAILED\treturn value: %i\n", retValTest);

    printf("handCount: %i, expected: %i\t", G.handCount[currentPlayer], G.handCount[currentPlayer]+2);
    passed = assertInt(testG.handCount[currentPlayer], G.handCount[currentPlayer]+2);
    if (passed) printf("PASSED\n");
    else printf("FAILED\thandCount: %i\n", testG.handCount[currentPlayer]);

    return 0;
}
