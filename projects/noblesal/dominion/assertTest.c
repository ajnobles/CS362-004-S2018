#include "assertTest.h"

int assertInt(int a, int b)
{
    if (a == b) {
        return 1;
    }

    return 0;
}


int assertIntArr(int *a, int *b)
{
    int aN = sizeof(a)/sizeof(a[0]);
    int bN = sizeof(b)/sizeof(b[0]);

    if (aN != bN) {
        return 0;
    }

    for (int i = 0; i < aN; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }

    return 1;
}
