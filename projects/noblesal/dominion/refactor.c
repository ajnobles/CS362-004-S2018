#include "refactor.h"

int adventurerRefactor(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
{
    int z = 0;
    int temphand[MAX_HAND];// moved above the if statement
    int drawntreasure=0;
    int cardDrawn;
    int currentPlayer = whoseTurn(state);

    // BUG ADDED
      //while(drawntreasure<2){
      while(drawntreasure <= 2){

        if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
            shuffle(currentPlayer, state);
        }
        drawCard(currentPlayer, state);
        cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.

        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
            drawntreasure++;

        else{
            temphand[z]=cardDrawn;
            state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
            z++;
        }
    }

    while(z-1>=0){
        state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
        z=z-1;
    }

    return 0;
}

int smithyRefactor(int card, int choice1, int choice2, int choice3,
	       struct gameState *state, int handPos, int *bonus)
{
		int currentPlayer = whoseTurn(state);
		int i;

		//+3 Cards

    // BUG ADDED
		//for (i = 0; i < 3; i++)
		for (i = 0; i <= 3; i++)
		{
        drawCard(currentPlayer, state);
		}

		//discard card from hand
		discardCard(handPos, currentPlayer, state, 0);
		return 0;
}

int villageRefactor(int card, int choice1, int choice2, int choice3,
	       struct gameState *state, int handPos, int *bonus)
{
    int currentPlayer = whoseTurn(state);

    //+1 Card
    drawCard(currentPlayer, state);

    // BUG ADDED
    //+2 Actions
    //state->numActions = state->numActions + 2;
    state->numActions = state->numActions + 1;

    //discard played card from hand
    discardCard(handPos, currentPlayer, state, 0);
    return 0;
}

int gardensRefactor()
{
    return -1;
}

int council_roomRefactor(int card, int choice1, int choice2, int choice3,
	       struct gameState *state, int handPos, int *bonus)
{
	  int currentPlayer = whoseTurn(state);
	  int i;

    // BUG ADDED
    //+4 Cards
	//for (i = 0; i < 4; i++)
	for (i = 0; i <= 4; i++)
	{
	  drawCard(currentPlayer, state);
	}

    //+1 Buy
    state->numBuys++;

    //Each other player draws a card
    for (i = 0; i < state->numPlayers; i++)
	{
	  if ( i != currentPlayer )
	    {
	      drawCard(i, state);
	    }
	}

    //put played card in played card pile
    discardCard(handPos, currentPlayer, state, 0);

    return 0;
}
