#ifndef _DOMINION_REFACTOR_H
#define _DOMINION_REFACTOR_H

#include "dominion.h"

int adventurer(int card, int choice1, int choice2, int choice3,
	       struct gameState *state, int handPos, int *bonus);
int smithy(int card, int choice1, int choice2, int choice3,
	       struct gameState *state, int handPos, int *bonus);
int village(int card, int choice1, int choice2, int choice3,
	       struct gameState *state, int handPos, int *bonus);
int garden(int card, int choice1, int choice2, int choice3,
	       struct gameState *state, int handPos, int *bonus);
int council_room(int card, int choice1, int choice2, int choice3,
	       struct gameState *state, int handPos, int *bonus);

#endif