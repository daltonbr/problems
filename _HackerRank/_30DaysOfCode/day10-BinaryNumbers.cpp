/*
https://www.hackerrank.com/challenges/30-binary-numbers/problem
*/

#include <iostream>
using namespace std;

int BinaryStreak(int n)
{
    int streak = 0;
    int maxStreak = 0;        
    
    while (n != 0)
    {        
        if ((n%2) == 1)
        {
            streak++;
            if (streak > maxStreak) { maxStreak = streak; }
        }
        else
        { streak = 0; }
        n /= 2;        
    }
    return maxStreak;
};

int main() {
    int n; cin >> n;

    cout << BinaryStreak(n);
    
    return 0;
}
