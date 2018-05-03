#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

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
    char **tmp;

    tmp = malloc(sizeof(char *) * 10);

    tmp[0] = malloc(sizeof(char) * 255);
    tmp[0] = "reset";

    tmp[1] = malloc(sizeof(char) * 255);
    tmp[1] = "start";

    tmp[2] = malloc(sizeof(char) * 255);
    tmp[2] = "end";

    tmp[3] = malloc(sizeof(char) * 255);
    tmp[3] = "code";

    tmp[4] = malloc(sizeof(char) * 255);
    tmp[4] = "rest";

    tmp[5] = malloc(sizeof(char) * 255);
    tmp[5] = "set";

    tmp[6] = malloc(sizeof(char) * 255);
    tmp[6] = "unrest";

    tmp[7] = malloc(sizeof(char) * 255);
    tmp[7] = "resetting";

    tmp[8] = malloc(sizeof(char) * 255);
    tmp[8] = "lots";

    tmp[9] = malloc(sizeof(char) * 255);
    tmp[9] = "love";



    return tmp[rand() % 10];
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
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

  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
