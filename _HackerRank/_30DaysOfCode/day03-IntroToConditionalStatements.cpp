/*
Task
Given an integer, n, perform the following conditional actions:

If n is odd, print Weird
If n is even and in the inclusive range of 2 to 5, print Not Weird
If n is even and in the inclusive range of 6 to 20, print Weird
If n is even and greater than 20, print Not Weird

Constraints: 1 <= n <= 100
*/

#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    string answer;
    int remainder = N % 2;
    
    if (remainder == 1)
    {
        // odd
        cout << "Weird" << endl;
        return 0;
    }
    else
    {
        // even
        if (N <= 5) 
        {
            cout << "Not Weird" << endl;
            return 0;
        } 
        if (N <= 20)
        {
            cout << "Weird" << endl;
            return 0;
        }
        else
        {
            cout << "Not Weird" << endl;
            return 0;
        }        
    }   
}