// scoreFor
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

// CARD SCORE VALUES
#define RET_VAL_START 3
#define CURSE_VAL -1
#define ESTATE_VAL 1
#define DUCHY_VAL 3
#define PROVINCE_VAL 6
#define GREAT_HALL_VAL 1
// GARDENS DOES NOT HAVE A SET DEFINED VALUE
int GARDENS_VAL(int player, struct gameState *state)
{
    return(fullDeckCount(player, 0, state) / 10);
}


int main (int argc, char *argv[])
{
    // GAME SETUP
    int numPlayers = 2;
    int kingdomCards[10] = {adventurer, smithy, gardens, curse, great_hall, village, council_room, minion, steward, ambassador};
    int seed = 1000,
        passed;

    struct gameState BASE, G, testG;
//
    int card,
        retVal,
        retValTest,
        currentPlayer,
        i,
        handPos,
        trashFlag,
        testNumber = 1;

    initializeGame(numPlayers, kingdomCards, seed, &BASE);

    // TEST 1
    printf("\nTEST %i STARTED\n", testNumber++);
    memcpy(&G, &BASE, sizeof(struct gameState));
    memcpy(&testG, &G, sizeof(struct gameState));

    currentPlayer = whoseTurn(&G);
    retVal = RET_VAL_START;

    retValTest = scoreFor(currentPlayer, &testG);

    printf("score: %i, expected: %i...\t", RET_VAL_START, retVal);
    passed = assertInt(retVal, retValTest);
    if (passed) printf("PASSED\n");
    else printf("FAILED\tretVal: %i\n", retValTest);


    // TEST 2
    printf("\nTEST %i STARTED\n", testNumber++);
    //memcpy(&G, &BASE, sizeof(struct gameState));

    currentPlayer = whoseTurn(&G);

    // GAIN Cards
    //  ADD DUCHY TO HAND(2)
    gainCard(duchy, &G, 2, currentPlayer);
    retVal += DUCHY_VAL;

    // DISCARD Cards

    // TRASH CARDS


    memcpy(&testG, &G, sizeof(struct gameState));
    retValTest = scoreFor(currentPlayer, &testG);

    printf("score: %i, expected: %i...\t", RET_VAL_START, retVal);
    passed = assertInt(retVal, retValTest);
    if (passed) printf("PASSED\n");
    else printf("FAILED\tretVal: %i\n", retValTest);


    // TEST 3
    printf("\nTEST %i STARTED\n", testNumber++);
    //memcpy(&G, &BASE, sizeof(struct gameState));

    currentPlayer = whoseTurn(&G);
    //retVal = RET_VAL_START;

    // GAIN Cards

    // DISCARD Cards
    //    DISCARD ESTATE CARD
    discardCard(1, currentPlayer, &G, 0);

    // TRASH CARDS

    memcpy(&testG, &G, sizeof(struct gameState));
    retValTest = scoreFor(currentPlayer, &testG);

    printf("score: %i, expected: %i...\t", RET_VAL_START, retVal);
    passed = assertInt(retVal, retValTest);
    if (passed) printf("PASSED\n");
    else printf("FAILED\tretVal: %i\n", retValTest);


    // TEST 4
    printf("\nTEST %i STARTED\n", testNumber++);
    //memcpy(&G, &BASE, sizeof(struct gameState));

    currentPlayer = whoseTurn(&G);
    // printHand(currentPlayer,&G);
    // printDeck(currentPlayer,&G);
    // printDiscard(currentPlayer,&G);

    // GAIN Cards

    // DISCARD Cards

    // TRASH CARDS
    //    TRASH ESTATE CARD
    discardCard(2, currentPlayer, &G, 1);
    retVal -= ESTATE_VAL;

    memcpy(&testG, &G, sizeof(struct gameState));
    retValTest = scoreFor(currentPlayer, &testG);

    printf("return value: %i, expected: %i...\t", retValTest, retVal);
    passed = assertInt(retVal, retValTest);
    if (passed) printf("PASSED\n");
    else printf("FAILED\tretVal: %i\n", retValTest);


    // TEST 5
    printf("\nTEST %i STARTED\n", testNumber++);
    //memcpy(&G, &BASE, sizeof(struct gameState));

    currentPlayer = whoseTurn(&G);
    // printHand(currentPlayer,&G);
    // printDeck(currentPlayer,&G);
    // printDiscard(currentPlayer,&G);

    // GAIN Cards
    gainCard(gardens, &G, 2, currentPlayer);
    retVal += GARDENS_VAL(currentPlayer, &G);

    // DISCARD Cards

    // TRASH CARDS

    memcpy(&testG, &G, sizeof(struct gameState));
    retValTest = scoreFor(currentPlayer, &testG);

    printf("return value: %i, expected: %i...\t", retValTest, retVal);
    passed = assertInt(retVal, retValTest);
    if (passed) printf("PASSED\n");
    else printf("FAILED\tretVal: %i\n", retValTest);

    return 0;
}
