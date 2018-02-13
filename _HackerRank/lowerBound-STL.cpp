/*
https://www.hackerrank.com/challenges/cpp-lower-bound/problem
*/

#include <vector>       // std::vector
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
using namespace std;

int main()
{
    int n, q;
    vector<int> v, queries;
    
    cin >> n;
    
    // reading the sorted array
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    // q - number of queries
    cin >> q;

    // reading the queries
    for (int i = 0; i < q; i++)
    {
        int temp;
        cin >> temp;
        queries.push_back(temp);
    }

    // outputing the queries
    for (int i = 0; i < q; i++)
    {    
        std::vector<int>::iterator lowIt;
        lowIt = std::lower_bound (v.begin(), v.end(), queries[i]);
        int lowPosition = lowIt - v.begin();
        //cout << "query[" << i << "] lower_bound at position " << (lowIt - v.begin()) << endl;
        if (v[lowPosition] == queries[i])
        {
            cout << "Yes ";
        }
        else
        {
            cout << "No ";
        }
        cout << lowIt - v.begin() + 1 << endl; // (1-based index)
    }

    return 0;
}
