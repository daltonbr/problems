//#include <unordered_set>

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::unordered_set<int> mySet;
        for(int i = 0; i <= nums.size(); i++) {
            mySet.insert(i);
        }
        
        for(int i = 0; i < nums.size(); i++) {
            mySet.erase(nums[i]);
        }

        return *mySet.begin();
    }
};