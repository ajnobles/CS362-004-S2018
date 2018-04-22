//
#include "dominion.h"
#include "dominion_helpers.h"

#include "refactor.h"

#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>



int main (int argc, char *argv[])
{
    struct gameState *test = malloc(sizeof(struct gameState));
    if(!test) {
      printf("gameState test failed to malloc\n");
      return 1;
    }

    int i, j, n;
    int testCases[] = {-100, 0, 1, 10, 40};

    n = sizeof(testCases)/sizeof(testCases[0]);

    for (i = 0; i < n; i++) {
      test->numPlayers = testCases[i];

      for (j=0; j < testCases[i];j++) {
        test->whoseTurn = j;

        if (whoseTurn(test) != j) {
          printf("TEST FAILED\n");
          exit(1);
        }
      }
    }

    //
    // // TEST 1
    // numPlayersTest = 4;
    // test->numPlayers = numPlayersTest;
    // for(i = 0; i < numPlayersTest; i++) {
    //   test->whoseTurn = i;
    //
    //   if(whoseTurn(test) != i) {
    //     printf("TEST FAILED\n");
    //     exit(1);
    //   }
    // }
    //
    // // TEST 2
    // numPlayersTest = 0;
    // test->numPlayers = numPlayersTest;
    // for(i = 0; i < numPlayersTest; i++) {
    //   test->whoseTurn = i;
    //
    //   if(whoseTurn(test) != i) {
    //     printf("TEST FAILED\n");
    //     exit(1);
    //   }
    // }
    //
    // // TEST 3
    // numPlayersTest = -1;
    // test->numPlayers = numPlayersTest;
    // for(i = 0; i < numPlayersTest; i++) {
    //   test->whoseTurn = i;
    //
    //   if(whoseTurn(test) != i) {
    //     printf("TEST FAILED\n");
    //     exit(1);
    //   }
    // }

    printf("TEST PASSED\n");
    return 0;
}
