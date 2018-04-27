// ADVENTURER
// REVEAL CARDS FROM YOUR DECK UNTIL YOU REVEAL 2 TREASURE CARDS.
//      PUT THOSE THREASURE CARDS INTO YOUR HAND AND DISCARD THE OTHER REVEALED CARDS.
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
//
    int retVal,
        retValTest,
        testNumber = 1,
        choice1 = 0,
        choice2 = 0,
        choice3 = 0,
        handPos = 0,
        bonus;

    int z,
        temphand[MAX_HAND],
        drawntreasure,
        cardDrawn,
        currentPlayer,
        card;

    initializeGame(numPlayers, kingdomCards, seed, &G);

    // TEST 1
    // TEST EMPTY DECK

    printf("TEST %i STARTED\n", testNumber);

    retVal = 0;
    card = adventurer;

    memcpy(&testG, &G, sizeof(struct gameState));
    retValTest = adventurerRefactor(card, choice1, choice2, choice3, &testG, handPos, &bonus);

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

    printf("return value: %i, expected: %i\n", retValTest, retVal);
    assert(retVal == retValTest);
    printf("drawntreasure: %i, expected: %i\n", retValTest, retVal);
    //assert(retVal == retValTest);

    printf("TEST %i PASSED\n\n", testNumber++);

    return 0;
}
