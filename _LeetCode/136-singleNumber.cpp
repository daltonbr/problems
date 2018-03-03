/*
Given an array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

https://leetcode.com/problems/single-number/description/
*/

#include <unordered_set>

class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        std::unordered_set<int> lookup;
        std::vector<int>::iterator it;        
        
        for (it = nums.begin(); it != nums.end(); it++)
        {
            std::unordered_set<int>::const_iterator cit = lookup.find(*it);
            
            if (cit != lookup.end())
            {
                // found; remove from the set
                lookup.erase(*it);
            }
            else
            {
                // not found; add to the set
                lookup.insert(*it);
            }
        }
        
        return *lookup.begin();   
        
    }
};