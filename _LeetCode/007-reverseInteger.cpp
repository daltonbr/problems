/*
Reverse Integer
https://leetcode.com/problems/reverse-integer/description/

Given a 32-bit signed integer, reverse digits of an integer.
// 32 bit int signed ranges From −2,147,483,648 to 2,147,483,647, from −(2^31) to (2^31) − 1
*/

#include <bitset>

class Solution
{
public:
    int reverse(int x)
    {
        std::string s = std::to_string(x);
        std::reverse(s.begin(), s.end());
        int invertedInt;
        
        try
        {
            invertedInt = std::stoi(s);    
        }
        catch (const std::out_of_range& e)
        {
            invertedInt = 0;
        }
        
        if (x < 0) { invertedInt *= -1; }
        
        return invertedInt;
    }
};