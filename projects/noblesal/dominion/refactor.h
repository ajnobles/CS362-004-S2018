#ifndef _DOMINION_REFACTOR_H
#define _DOMINION_REFACTOR_H

#include "dominion.h"
#include "dominion_helpers.h"


int adventurerRefactor(int card, int choice1, int choice2, int choice3,
	       struct gameState *state, int handPos, int *bonus);

int smithyRefactor(int card, int choice1, int choice2, int choice3,
	       struct gameState *state, int handPos, int *bonus);

int villageRefactor(int card, int choice1, int choice2, int choice3,
	       struct gameState *state, int handPos, int *bonus);

int gardensRefactor();

int council_roomRefactor(int card, int choice1, int choice2, int choice3,
	       struct gameState *state, int handPos, int *bonus);

#endif
