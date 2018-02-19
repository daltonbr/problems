/*
Day 20 - Sorting (Bubble Sort)
https://www.hackerrank.com/challenges/30-sorting/problem
*/

#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int n; cin >> n;
    size_t size = n;
    vector<int> v(n);

    // input
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int currentSwaps;
    int totalNumberOfSwaps = 0;

    // Bubble Sort
    for (int i = 0; i < n; i++)
    {
        currentSwaps = 0;
        for (int j = 0; j < n-1; j++)
        {
            if (v[j] > v[j+1])
            {
                swap(v[j], v[j+1]);
                currentSwaps++;
                totalNumberOfSwaps++;
            }
        }
        if (currentSwaps == 0) break;        
    }

    cout << "Array is sorted in " << totalNumberOfSwaps << " swaps." << endl;
    cout << "First Element: " << *v.begin() << endl;
    cout << "Last Element: " << *(v.end()-1) << endl;

    return 0;
}

