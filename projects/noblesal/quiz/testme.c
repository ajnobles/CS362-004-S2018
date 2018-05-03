#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define TEST_STRINGS "testStrings.txt"
#define MAX_WORDS 100
#define NUM_ASCII_CHARS 128

size_t MAX_WORD_SIZE = 25;

char inputChar()
{
    // TODO: rewrite this function
    return rand() % NUM_ASCII_CHARS;
}

char *inputString()
{
    // TODO: rewrite this function
<<<<<<< a71ccd9f485a16d263830add82b97de195af1eff

    char *tmp[MAX_WORDS];
    memset(tmp, '\0', MAX_WORDS);

    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        tmp[i] = malloc(sizeof(char) * MAX_WORD_SIZE);
        memset(tmp[i], '\0', MAX_WORD_SIZE);
    }

    char *r = malloc(sizeof(char) * MAX_WORD_SIZE);
    memset(r, '\0', MAX_WORD_SIZE);

    FILE *input = fopen(TEST_STRINGS, "r");

    i = 0;
    while(getline(&tmp[i], &MAX_WORD_SIZE, input) > 0 && i < MAX_WORDS){
        int len = strlen(tmp[i]);

        if (tmp[i][len-1] == '\n')
        {
            tmp[i][len-1] = '\0';
        }

        // FOR TESTING
        // printf("i: %i\tword: %s\n", i, tmp[i]);
        i++;
    }

    fclose(input);

    strcpy(r, tmp[rand() % i]);

    return r;
=======
    char *tmp;//**tmp;
    tmp = malloc(sizeof(char) * 6);
    memset(tmp, '\0', 6);

    for (int i = 0; i < 5; i++){
        tmp[i] = inputChar();

        if (tmp[0] == 'r') {
            strcpy(tmp, "reset");
            break;
        }
    }

    // tmp = malloc(sizeof(char *) * 10);
    //
    // tmp[0] = malloc(sizeof(char) * 255);
    // tmp[0] = "reset";
    //
    // tmp[1] = malloc(sizeof(char) * 255);
    // tmp[1] = "start";
    //
    // tmp[2] = malloc(sizeof(char) * 255);
    // tmp[2] = "end";
    //
    // tmp[3] = malloc(sizeof(char) * 255);
    // tmp[3] = "code";
    //
    // tmp[4] = malloc(sizeof(char) * 255);
    // tmp[4] = "rest";
    //
    // tmp[5] = malloc(sizeof(char) * 255);
    // tmp[5] = "set";
    //
    // tmp[6] = malloc(sizeof(char) * 255);
    // tmp[6] = "unrest";
    //
    // tmp[7] = malloc(sizeof(char) * 255);
    // tmp[7] = "resetting";
    //
    // tmp[8] = malloc(sizeof(char) * 255);
    // tmp[8] = "lots";
    //
    // tmp[9] = malloc(sizeof(char) * 255);
    // tmp[9] = "love";

    // return tmp[rand() % 10];
    return tmp;
>>>>>>> Quiz; Testing gcov
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;

  // TIMING VARIABLES
  time_t startTime = clock() / CLOCKS_PER_SEC,
         elapsedTime = clock() / CLOCKS_PER_SEC;

  while (elapsedTime < (60 * 5))
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error \n");
      // exit(200);
      break;
    }
    // [({ ax})]

    elapsedTime = (clock() / CLOCKS_PER_SEC) - startTime;
    // printf("elapsedTime: %lu\n", elapsedTime);

  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
