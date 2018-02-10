/*
https://www.hackerrank.com/challenges/ctci-bubble-sort/problem
*/

#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin >> n;
    int swapCount = 0;

    vector<int> a(n);

    // input
    for(int i = 0; i < n; i++)
    {
       cin >> a[i];
    }

    bool isSorted = false;

    while (!isSorted)
    {
        isSorted = true;
        // bubble Sort
        for (int i = 0; i < n-1; i++)
        {
            if (a[i+1] < a[i])
            {
                isSorted = false;
                iter_swap(a.begin()+i, a.begin()+i+1);                    
                swapCount++;
            }
        }
    }

    cout << "Array is sorted in " << swapCount << " swaps." << endl;
    cout << "First Element: " << a[0] << endl;
    cout << "Last Element: " << a[n-1] << endl;

  return 0;
}
