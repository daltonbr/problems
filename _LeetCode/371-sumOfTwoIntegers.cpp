/*
Sum of Two Integers
https://leetcode.com/problems/sum-of-two-integers/description/

Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
*/

#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include<algorithm>

using namespace std;

class Solution
{
public:
    int getSum(int a, int b)
    {
        while (b != 0)
        {
            int carry = a & b;

            // sum without carries
            a = a ^ b;

            // b for the next iteration will have some queries
            b = carry << 1;
        }
        
        return a;
    }
};

// Brute Force
/* 
class Solution
{
public:
    int getSum(int a, int b)
    {
        int sum = 0;
        
        if (a > 0)
        {
            for (int i = 0; i < a; i++)
            {
                sum++;
            }
        }
        else
        {
            for (int i = 0; i > a; i--)
            {
                sum--;
            }
        }
        
        if (b > 0)
        {
            for (int i = 0; i < b; i++)
            {
                sum++;
            }    
        }
        else
        {
            for (int i = 0; i > b; i--)
            {
                sum--;
            }    
        }
        return sum;
    }
};
*/

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int a = stringToInteger(line);
        getline(cin, line);
        int b = stringToInteger(line);
        
        int ret = Solution().getSum(a, b);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}