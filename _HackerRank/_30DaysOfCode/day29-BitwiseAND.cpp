/*
Day 29 Bitwise AND
https://www.hackerrank.com/challenges/30-bitwise-and/problem
*/

#include <cstdio>
#include <iostream>

int main()
{
    int t; std::cin >> t;
    unsigned int n, k, max;

    // looping test cases
    for (int i = 0; i < t; i++)
    {
        max = 0;   
        std::cin >> n >> k;
        for (unsigned int j = 1; j < n; j++)
        {
            for (unsigned int m = j+1; m <= n; m++)
            {
                unsigned int current = j & m;
                if (current > max && current < k)
                {
                    max = current;
                }
            }
        }
        std::cout << max << std::endl;
    }
    
    return 0;
}
