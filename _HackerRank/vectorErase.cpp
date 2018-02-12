/*
https://www.hackerrank.com/challenges/vector-erase/problem
*/
/*

erase(int position):

Removes the element present at position.  
Ex: v.erase(v.begin()+4); (erases the fifth element of the vector v)
erase(int start,int end):

Removes the elements in the range from start to end inclusive of the start and exclusive of the end.
Ex:v.erase(v.begin()+2,v.begin()+5);(erases all the elements from the third element to the fifth element.)
*/

#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

void printVector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " " ;
    }
    cout << endl;
}

int main()
{
    int n; cin >> n;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    int x;  // index to remove an element (1-base index)
    int a, b; // range [a, b[ of indices to remove elements (1-base index)
    
    cin >> x;
    v.erase(v.begin()+x-1);
    //printVector(v);

    cin >> a >> b;
    v.erase(v.begin()+a-1, v.begin()+b-1);
    //printVector(v);
    cout << v.size() << endl;
    printVector(v);

    return 0;
}
