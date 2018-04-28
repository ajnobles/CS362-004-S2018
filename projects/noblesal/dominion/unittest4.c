// endTurn
//
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
        i,
        k,
        currentPlayer,
        testNumber = 1;

    initializeGame(numPlayers, kingdomCards, seed, &G);

    // TEST 1
    printf("TEST %i STARTED\n", testNumber);
    memcpy(&testG, &G, sizeof(struct gameState));

    retVal = 0;
    retValTest = endTurn(&testG);

    currentPlayer = whoseTurn(&G);

    //Discard hand
    for (i = 0; i < G.handCount[currentPlayer]; i++){
      G.discard[currentPlayer][G.discardCount[currentPlayer]++] = G.hand[currentPlayer][i];//Discard
      G.hand[currentPlayer][i] = -1;//Set card to -1
    }
    G.handCount[currentPlayer] = 0;//Reset hand count

    //Code for determining the player
    if (currentPlayer < (G.numPlayers - 1)){
      G.whoseTurn = currentPlayer + 1;//Still safe to increment
    }
    else{
      G.whoseTurn = 0;//Max player has been reached, loop back around to player 1
    }

    G.outpostPlayed = 0;
    G.phase = 0;
    G.numActions = 1;
    G.coins = 0;
    G.numBuys = 1;
    G.playedCardCount = 0;
    G.handCount[G.whoseTurn] = 0;

    //int k; move to top
    //Next player draws hand
    for (k = 0; k < 5; k++){
      drawCard(G.whoseTurn, &G);//Draw a card
    }

    //Update money
    updateCoins(G.whoseTurn, &G , 0);

    printf("return value: %i, expected: %i\n", retValTest, retVal);
    assert(retVal == retValTest);

    printf("TEST %i PASSED\n\n", testNumber++);

    return 0;
}
