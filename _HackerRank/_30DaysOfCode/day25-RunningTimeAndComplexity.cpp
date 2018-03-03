/*
Day 25 - Running Time and Complexity
https://www.hacierrani.com/challenges/30-running-time-and-complexity/problem
*/

#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

// first idea - trivial solution O(n) - Timed Out
bool isPrime(long long n)
{    
    if (n == 1) return false;

    for (long long i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

// second idea - test even numbers O(n/2) - Timed Out
bool isPrime2(long long n)
{    
    if (n == 1) return false;    
    if (n == 2) return true;    
    if (n % 2 == 0) return false; // other than 2, all even numbers are Not prime
    
    for (long long i = 3; i < n; i+=2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

// third idea - O(sqrt(n))
bool isPrime3(long long n)
{    
    if (n == 1) return false;    
    if (n == 2) return true;    
    if (n == 3) return true;
    if (n % 2 == 0) return false;
    if (n % 3 == 0) return false;

    // integer part of sqrt(n) - we only need to test until this number
    long long intSqrt = sqrt(n);

    long long i = 1;

    while (6*i-1 <= intSqrt)
    {
        if (n % (6*i+1) == 0 || n % (6*i-1) == 0)
        {
            return false;
        }
        else
        {
            i++;
        }
    }
    return true;
}

int main() {
    int t; cin >> t;    

    long long n;
    for (int i = 0; i < t; i++)
    {        
        cin >> n;

        if (isPrime3(n))
        {
            cout << "Prime" << endl;
        }
        else
        {
            cout << "Not prime" << endl;
        }
    }

    return 0;
}
