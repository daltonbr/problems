/*
344. Reverse String
https://leetcode.com/problems/reverse-string/description/

Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
*/

class Solution {
public:
    string reverseString(string s) {
        std::string reversedString;
        for (std::string::reverse_iterator rit = s.rbegin(); rit!=s.rend(); ++rit) {
            reversedString.push_back(*rit);
        }
        return reversedString;
    }
};