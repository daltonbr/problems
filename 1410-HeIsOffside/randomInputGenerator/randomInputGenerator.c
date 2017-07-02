// A randon input generator for problem #1410
//Author: Dalton Lima @daltonbr

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int attackers, defenders;
    //int[] att, def;
    int i, j, k, r, output, numInputs = 1000;

    srand(time(NULL));   // should only be called once
    
    for (i = 0; i < numInputs; i++)
    {
        attackers = (rand() % 10) + 2;   // for a random integer between 2 and 11
        defenders = (rand() % 10) + 2;
        printf("%d %d\n", attackers, defenders);

        // Generating a line for attackers
        for (j = 0; j < attackers-1; j++)
        {
            output = rand() % 1000;
            printf("%d ", output);
        }
        output = rand() % 1000;     // we let this last iteration out of the loop, just to put a \n to the line
        printf("%d\n", output);

        // And a line for defenders
        for (k = 0; k < defenders-1; k++)
        {
            output = rand() % 1000;
            printf("%d ", output);
        }
        output = rand() % 1000;
        printf("%d\n", output);
    }
    printf("0 0\n");
    return 0;
}