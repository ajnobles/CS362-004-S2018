// scoreFor 421
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
    int retVal,
        retValTest,
        currentPlayer,
        testNumber = 1;

    initializeGame(numPlayers, kingdomCards, seed, &BASE);

    // TEST 1
    printf("\n\nTEST %i STARTED\n", testNumber++);
    printf("Test Initial Game Initialization\n\n");
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
    printf("\n\nTEST %i STARTED\n", testNumber++);
    printf("Add a duchy Card to Hand\n\n");
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
    printf("\n\nTEST %i STARTED\n", testNumber++);
    printf("Discard Estate Card to Discard\n\n");
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
    printf("\n\nTEST %i STARTED\n", testNumber++);
    printf("Trash an Estate Card\n\n");
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
    printf("\n\nTEST %i STARTED\n", testNumber++);
    printf("Add a Gardens Card to Hand\n\n");
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


    // TEST 6
    printf("\n\nTEST %i STARTED\n", testNumber++);
    printf("Stage Deck, Discard, and Hand to include special Cards\n");
    printf("deckCount = 6, handCount = 6, discardCount = 6\n\n");
    //memcpy(&G, &BASE, sizeof(struct gameState));

    currentPlayer = whoseTurn(&G);
    // printHand(currentPlayer,&G);
    // printDeck(currentPlayer,&G);
    // printDiscard(currentPlayer,&G);

    // STAGE Hand
    G.handCount[currentPlayer] = 6;
    G.deckCount[currentPlayer] = 6;
    G.discardCount[currentPlayer] = 6;

    G.hand[currentPlayer][0] = curse;
    G.hand[currentPlayer][1] = estate;
    G.hand[currentPlayer][2] = duchy;
    G.hand[currentPlayer][3] = province;
    G.hand[currentPlayer][4] = great_hall;
    G.hand[currentPlayer][5] = gardens;

    G.deck[currentPlayer][0] = curse;
    G.deck[currentPlayer][1] = estate;
    G.deck[currentPlayer][2] = duchy;
    G.deck[currentPlayer][3] = province;
    G.deck[currentPlayer][4] = great_hall;
    G.deck[currentPlayer][5] = gardens;

    G.discard[currentPlayer][0] = curse;
    G.discard[currentPlayer][1] = estate;
    G.discard[currentPlayer][2] = duchy;
    G.discard[currentPlayer][3] = province;
    G.discard[currentPlayer][4] = great_hall;
    G.discard[currentPlayer][5] = gardens;

    retVal = 3 * (CURSE_VAL + ESTATE_VAL + DUCHY_VAL + PROVINCE_VAL + GREAT_HALL_VAL);
    retVal += GARDENS_VAL(currentPlayer, &G);
    retVal += GARDENS_VAL(currentPlayer, &G);
    retVal += GARDENS_VAL(currentPlayer, &G);

    // GAIN Cards

    // DISCARD Cards

    // TRASH CARDS

    memcpy(&testG, &G, sizeof(struct gameState));
    retValTest = scoreFor(currentPlayer, &testG);

    printf("return value: %i, expected: %i...\t", retValTest, retVal);
    passed = assertInt(retVal, retValTest);
    if (passed) printf("PASSED\n");
    else printf("FAILED\tretVal: %i\n", retValTest);


    // TEST 7
    printf("\n\nTEST %i STARTED\n", testNumber++);
    printf("Stage Deck, Discard, and Hand to include special Cards\n\n");
    printf("deckCount = 3, handCount = 4, discardCount = 6\n\n");
    //memcpy(&G, &BASE, sizeof(struct gameState));

    currentPlayer = whoseTurn(&G);

    // STAGE Hand
    G.handCount[currentPlayer] = 3;
    G.deckCount[currentPlayer] = 4;
    G.discardCount[currentPlayer] = 6;

    G.hand[currentPlayer][0] = curse;
    G.hand[currentPlayer][1] = estate;
    G.hand[currentPlayer][2] = duchy;
    retVal = (CURSE_VAL + ESTATE_VAL + DUCHY_VAL);

    G.deck[currentPlayer][0] = curse;
    G.deck[currentPlayer][1] = estate;
    G.deck[currentPlayer][2] = duchy;
    G.deck[currentPlayer][3] = province;
    retVal += (CURSE_VAL + ESTATE_VAL + DUCHY_VAL + PROVINCE_VAL);

    G.discard[currentPlayer][0] = curse;
    G.discard[currentPlayer][1] = estate;
    G.discard[currentPlayer][2] = duchy;
    G.discard[currentPlayer][3] = province;
    G.discard[currentPlayer][4] = great_hall;
    G.discard[currentPlayer][5] = gardens;
    retVal += (CURSE_VAL + ESTATE_VAL + DUCHY_VAL + PROVINCE_VAL + GREAT_HALL_VAL);
    retVal += GARDENS_VAL(currentPlayer, &G);


    memcpy(&testG, &G, sizeof(struct gameState));
    retValTest = scoreFor(currentPlayer, &testG);

    printf("return value: %i, expected: %i...\t", retValTest, retVal);
    passed = assertInt(retVal, retValTest);
    if (passed) printf("PASSED\n");
    else printf("FAILED\tretVal: %i\n", retValTest);


    // TEST 8
    printf("\n\nTEST %i STARTED\n", testNumber++);
    printf("Stage Deck, Discard, and Hand to include special Cards\n\n");
    printf("deckCount = 4, handCount = 6, discardCount = 3\n\n");
    //memcpy(&G, &BASE, sizeof(struct gameState));

    currentPlayer = whoseTurn(&G);

    // STAGE Hand
    G.handCount[currentPlayer] = 4;
    G.deckCount[currentPlayer] = 6;
    G.discardCount[currentPlayer] = 3;

    G.discard[currentPlayer][0] = curse;
    G.discard[currentPlayer][1] = estate;
    G.discard[currentPlayer][2] = duchy;
    retVal = (CURSE_VAL + ESTATE_VAL + DUCHY_VAL);

    G.hand[currentPlayer][0] = curse;
    G.hand[currentPlayer][1] = estate;
    G.hand[currentPlayer][2] = duchy;
    G.hand[currentPlayer][3] = province;
    retVal += (CURSE_VAL + ESTATE_VAL + DUCHY_VAL + PROVINCE_VAL);

    G.deck[currentPlayer][0] = curse;
    G.deck[currentPlayer][1] = estate;
    G.deck[currentPlayer][2] = duchy;
    G.deck[currentPlayer][3] = province;
    G.deck[currentPlayer][4] = great_hall;
    G.deck[currentPlayer][5] = gardens;
    retVal += (CURSE_VAL + ESTATE_VAL + DUCHY_VAL + PROVINCE_VAL + GREAT_HALL_VAL);
    retVal += GARDENS_VAL(currentPlayer, &G);


    memcpy(&testG, &G, sizeof(struct gameState));
    retValTest = scoreFor(currentPlayer, &testG);

    printf("return value: %i, expected: %i...\t", retValTest, retVal);
    passed = assertInt(retVal, retValTest);
    if (passed) printf("PASSED\n");
    else printf("FAILED\tretVal: %i\n", retValTest);


    // TEST 9
    printf("\n\nTEST %i STARTED\n", testNumber++);
    printf("Stage Deck, Discard, and Hand to include special Cards\n\n");
    printf("deckCount = 6, handCount = 3, discardCount = 4\n\n");
    //memcpy(&G, &BASE, sizeof(struct gameState));

    currentPlayer = whoseTurn(&G);

    // STAGE Hand
    G.handCount[currentPlayer] = 6;
    G.deckCount[currentPlayer] = 3;
    G.discardCount[currentPlayer] = 4;

    G.deck[currentPlayer][0] = curse;
    G.deck[currentPlayer][1] = estate;
    G.deck[currentPlayer][2] = duchy;
    retVal = (CURSE_VAL + ESTATE_VAL + DUCHY_VAL);

    G.discard[currentPlayer][0] = curse;
    G.discard[currentPlayer][1] = estate;
    G.discard[currentPlayer][2] = duchy;
    G.discard[currentPlayer][3] = province;
    retVal += (CURSE_VAL + ESTATE_VAL + DUCHY_VAL + PROVINCE_VAL);

    G.hand[currentPlayer][0] = curse;
    G.hand[currentPlayer][1] = estate;
    G.hand[currentPlayer][2] = duchy;
    G.hand[currentPlayer][3] = province;
    G.hand[currentPlayer][4] = great_hall;
    G.hand[currentPlayer][5] = gardens;
    retVal += (CURSE_VAL + ESTATE_VAL + DUCHY_VAL + PROVINCE_VAL + GREAT_HALL_VAL);
    retVal += GARDENS_VAL(currentPlayer, &G);


    memcpy(&testG, &G, sizeof(struct gameState));
    retValTest = scoreFor(currentPlayer, &testG);

    printf("return value: %i, expected: %i...\t", retValTest, retVal);
    passed = assertInt(retVal, retValTest);
    if (passed) printf("PASSED\n");
    else printf("FAILED\tretVal: %i\n", retValTest);

    return 0;
}
