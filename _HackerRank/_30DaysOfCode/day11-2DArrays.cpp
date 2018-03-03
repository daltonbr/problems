/*
https://www.hackerrank.com/challenges/30-2d-arrays/problem
*/

#include <vector>
#include <iostream>
#include <limits>       // std::numeric_limits
using namespace std;

#define MAX(a, b) ((a > b) ? a : b)
const int ARRAY_SIZE = 6;

// gets a sum of all elements of an hourglass
// params are the array and the "most top-left" index of the hourglass
int getHourlassSum(vector< vector<int> > array, int i, int j)
{
    int sum = 0;
    sum += array[i]  [j];
    sum += array[i]  [j+1];
    sum += array[i]  [j+2];
    sum += array[i+1][j+1];
    sum += array[i+2][j];
    sum += array[i+2][j+1];
    sum += array[i+2][j+2];
    return sum;    
}

int main()
{
    vector< vector<int> > arr(ARRAY_SIZE,vector<int>(ARRAY_SIZE));

    // input
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
       for (int j = 0; j < ARRAY_SIZE; j++)
       {
          cin >> arr[i][j];          
       }       
    }

    // we could use -9 * 7 = -63 (for the initial maxSum)
    // according to the problem conditions 
    // this is the minimum possible value for a hourglass
    int maxSum = numeric_limits<int>::min(); 
    int currentSum;

    // loop for all top-left index, for each hourglass
    for (int i = 0; i < ARRAY_SIZE-2; i++)
    {
        for (int j = 0; j < ARRAY_SIZE-2; j++)
        {            
            currentSum = getHourlassSum(arr, i, j);            
            maxSum = MAX(currentSum, maxSum);
        }
    }
    cout << maxSum;

    return 0;
}

