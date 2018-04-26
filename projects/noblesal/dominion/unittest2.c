// fullDeckCount
//
#include "dominion.h"
#include "dominion_helpers.h"

#include "refactor.h"

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

    int card,
        player,
        i,
        count,
        countTest,
        testNumber = 1;

    initializeGame(numPlayers, kingdomCards, seed, &G);

    // TEST 1
    printf("TEST %i STARTED\n", testNumber);
    memcpy(&testG, &G, sizeof(struct gameState));
    player = G.whoseTurn;
    countTest = fullDeckCount(player, card, &testG);

    count = 0;
    for (i = 0; i < G.deckCount[player]; i++)
      {
        if (G.deck[player][i] == card) count++;
      }

    for (i = 0; i < G.handCount[player]; i++)
      {
        if (G.hand[player][i] == card) count++;
      }

    for (i = 0; i < G.discardCount[player]; i++)
      {
        if (G.discard[player][i] == card) count++;
      }

    printf("count: %i, expected: %i\n", countTest, count);
    assert(count == countTest);

    printf("TEST %i PASSED\n\n", testNumber++);

    return 0;
}
