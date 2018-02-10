/*
https://www.hackerrank.com/contests/w36/challenges/revised-russian-roulette
*/

#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> v;
    v.reserve(n);
    
    int min = 0, max = 0;
    int temp;
    bool lastWasOne = false;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp == 1)
        {
            max++;
            if (lastWasOne == false)
            {
                lastWasOne = true;
                min++;                
            }
            else
            {
                lastWasOne = false;
            }            
        }
        else
        {
            lastWasOne = false;
        }
    }
    
    cout << min << " " << max << endl;

    return 0;
}
