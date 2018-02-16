/*
https://www.hackerrank.com/contests/rookierank-4/challenges/exam-rush
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool crescentOrder (int i,int j) { return (i<j); }

int main()
{
    int n, tm;
    cin >> n >> tm;
    vector<int> chaptersHours;

    // input
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        chaptersHours.push_back(temp);        
    }

    sort (chaptersHours.begin(), chaptersHours.end(), crescentOrder);

    // debug out
    int hoursLeft = tm;
    for (int i = 0; i < n; i++)
    {
        //cout << chaptersHours[i] << " ";
        if (hoursLeft - chaptersHours[i] >= 0)
        {
            hoursLeft -= chaptersHours[i];
            //cout << "hoursLeft: " << hoursLeft << endl;
        }
        else
        {
            cout << i << endl;
            return 0;
        }    
    }
    cout << chaptersHours.size() << endl;
    return 0;
}
