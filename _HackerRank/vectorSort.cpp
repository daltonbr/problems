/*
https://www.hackerrank.com/challenges/vector-sort/problem
*/
#include <vector>
#include <iostream>
#include <algorithm> // std::sort
using namespace std;

int main()
{
    vector<int> v;
    int n; cin >> n;      
  
    // input
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;      
        getchar();    // blank space
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());
    
    // output
    for (int i = 0; i < n; i++) { cout << v[i] << " "; }
    
    return 0;
}
