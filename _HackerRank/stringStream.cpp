/*
https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem
*/

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str)
{  
    vector<int> output;
    stringstream ss(str);
    char ch;
    
    int counter = 0;
    do
    {
        int tempInt;
        ss >> tempInt >> ch;
        output.push_back(tempInt);
    } while (!ss.eof());
    
    return output;
}

int main()
{
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
