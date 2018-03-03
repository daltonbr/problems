/*
Day 26 - Nested Logic
https://www.hackerrank.com/challenges/30-nested-logic/problem
*/

#include <iostream>
using namespace std;

int main()
{
    int da, ma, ya, de, me, ye;
    cin >> da >> ma >> ya >> de >> me >> ye;

    int fine = 0;

    if (ya < ye)
    {        
        cout << fine;
        return 0;
    }    

    if (ya > ye)
    {
        fine = 10000;
        cout << fine;
        return 0;
    }
    
    if (ma < me)
    {
        fine = 0;
    } else
        if (ma == me)   
        {
            if (da <= de)
            {
                fine = 0;                                
            }
            else
            {
                // daily fine
                fine = (da - de) * 15;
            }
        }
        else
        {
            // monthly fine
            fine = (ma - me) * 500;
        }

    cout << fine;
    return 0;
}
