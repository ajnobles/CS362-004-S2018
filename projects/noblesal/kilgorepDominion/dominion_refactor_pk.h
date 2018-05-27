
#ifndef DOMINION_REFACTOR
#define DOMINION_REFACTOR

// KILGORE REFACTORED CARDS
int effectOfAdventurer(struct gameState *state, int currentPlayer);
int effectOfSmithy(struct gameState *state, int currentPlayer, int handPos);
int effectOfSeaHag(struct gameState *state, int currentPlayer);
int effectOfCouncilRoom(struct gameState *state, int currentPlayer, int handPos);
int effectOfSteward(struct gameState *state, int currentPlayer, int handPos, int choice1, int choice2, int choice3);

// NOBLES REFACTORED CARDS
int villageRefactor(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);
int gardensRefactor(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);

#endif
