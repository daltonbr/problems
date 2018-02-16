/*
RookieRank4
Server Room Safety
https://www.hackerrank.com/contests/rookierank-4/challenges/server-room-safety
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define max(a, b) a=(a>b?a:b)
#define min(a, b) a=(a<b?a:b)
using namespace std;

int n;
vector<int> x, h;

//left to right
bool leftCheck()
{
    int maxReach = x[0];
    for (int i = 0; i < n; i++)
    {
        int currentReach = x[i] + h[i];
        if (currentReach >= x[i+1] || maxReach >= x[i+1])
        {
            maxReach = max(maxReach, currentReach);
        }
        else
        {
            return false;
        }
    }
    return true;
}

// right to left
bool rightCheck()
{
    int maxReach = x[h.size()-1];
    for (int i = n-1; i > 0; i--)
    {
        int currentReach = x[i] - h[i];
        if (currentReach <= x[i-1] || maxReach <= x[i-1])
        {
            maxReach = min(maxReach, currentReach);
        }
        else
        {
            return false;
        }
    }
    return true;
}

void checkAll()
{
    bool testLeft = leftCheck();
    bool testRight = rightCheck();

    if (testRight && testLeft)
        cout << "BOTH";
    else if (testRight)
        cout << "RIGHT";
    else if (testLeft)
        cout << "LEFT";
    else
        cout << "NONE";

    return;
}

int main() {
  cin >> n;

    // input positions
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        x.push_back(temp);
    }

    // input heights
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        h.push_back(temp);
    }

    checkAll();

    return 0;
}
