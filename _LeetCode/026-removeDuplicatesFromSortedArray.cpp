/*
026 - Remove Duplicates from Sorted Array
https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std::vector<int>::iterator current = nums.begin();
        
        // empty vector
        if (current == nums.end()) return 0;

        while (current+1 != nums.end())
        {            
            if (*current == *(current+1))
            {
                nums.erase(current+1);
            }
            else                
            {
               ++current;
            }
        }
                        
        return nums.size();
    }
};