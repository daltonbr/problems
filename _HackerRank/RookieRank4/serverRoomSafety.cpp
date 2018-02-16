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
    int maxReach = 0;
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

// bool leftIsDangerous(int i)
// {    
//     return x[i-1] + h[i-1] >= x[i];
// }

// bool rightIsDangerous(int i)
// {
//     return x[i+1] - h[i+1] <= x[i];
// }

void checkAll()
{
    bool testLeft = leftCheck();
    bool testRight = rightCheck();
        
    // int i = 1;
    // //left to right test - starts at the second element
    // while (testLeft && i < n)
    // {
      
    //     i++;
    // }
    // //cout << testLeft << endl;

    // i = n-2; // start at penultimate element
    // // right to left test
    // while (testRight && i >= 0)
    // {
    //     testRight = rightCheck();
    //     i--;
    // }
    // //cout << testRight << endl;

    if (testRight && testLeft)
        cout << "BOTH";
    else if (testRight)
        cout << "LEFT";
    else if (testLeft)
        cout << "RIGHT";
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

    //debug
    // for (int i = 0; i < n; i++)
    // {        
    //     cout << x[i] << " : " << h[i] << endl;
    // }

    checkAll();


    return 0;
}
