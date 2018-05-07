#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define TEST_STRINGS "testStrings.txt"
#define MAX_WORDS 100


size_t MAX_WORD_SIZE = 25;

char inputChar()
{
    // TODO: rewrite this function
    int numChars = 26 + 3 + 3 + 1;

    char tmp = rand() % numChars;

    if (tmp < 26) tmp += 'a';

    else if (tmp == 26) tmp = '[';
    else if (tmp == 27) tmp = ']';

    else if (tmp == 28) tmp = '(';
    else if (tmp == 29) tmp = ')';

    else if (tmp == 30) tmp = '{';
    else if (tmp == 31) tmp = '}';
    else if (tmp == 31) tmp = ' ';

    return tmp;
}

char *inputString()
{
    // TODO: rewrite this function

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
    while(getline(&tmp[i], &MAX_WORD_SIZE, input) > 0){
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
      printf("error ");
      exit(200);
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
