#include <stdio.h>
#include <time.h>
#include <stdlib.h>
 
int main()
{
    int i, j, r, lines = 1000;

    srand(time(NULL));   // should only be called once

    // iterating by lines
    for (j = 0; j < lines; j++)
    {
        for (i = 0; i < 7; i++ ) // 7 values per line
        {
            r = rand() % 100;      // returns a pseudo-random integer between 0 and RAND_MAX
            printf("%d ", r);
        }
            r = rand() % 100;      // off by one (just to not finish a line with a blank space)
            printf("%d\n", r);     // Do you have a more elegant solution?
    }

    return 0;
}