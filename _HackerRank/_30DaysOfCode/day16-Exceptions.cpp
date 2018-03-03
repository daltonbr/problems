/*
Day 16 - Exceptions - String to Integer
https://www.hackerrank.com/challenges/30-exceptions-string-to-integer/problem
*/

#include <iostream>
#include <string>
#include <iostream>       // std::cerr
#include <stdexcept>      // std::invalid_argument

using namespace std;

int main()
{
    string S;
    cin >> S;    
    int parsedInt;
    
    try
    {
        parsedInt = std::stoi(S);
        cout << parsedInt << endl; 
    }
    catch (const std::invalid_argument& ia)
    {
        cout << "Bad String"/* << ia.what()*/ << endl;
    }    

    return 0;
}