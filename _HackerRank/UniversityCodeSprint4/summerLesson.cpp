/*
Summer Lesson
https://www.hackerrank.com/contests/university-codesprint-4/challenges/summer-lesson
*/

#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;    
    vector<int> classes;
    classes.reserve(m);

    int temp;
    for (int i = 0; i < n; i++)
    {        
        cin >> temp;
        classes[temp]++;
    }

    for (int i = 0; i < m; i++) { cout << classes[i] << " "; }

    return 0;
}
