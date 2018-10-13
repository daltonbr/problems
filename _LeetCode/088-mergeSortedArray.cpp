// Merge sorted array
// https://leetcode.com/submissions/detail/182533504/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) { return; }                        
        if (m == 0) { 
            nums1 = nums2;
            return;
        }
        
        int indexM = m-1;
        int indexN = n-1;
        int indexTotal = m+n-1;
        
        while ((indexM > -1) && (indexN > -1)) {
            if (nums1[indexM] > nums2[indexN]) {
                nums1[indexTotal] = nums1[indexM];
                indexM--;
                indexTotal--;                
            } else {
                nums1[indexTotal] = nums2[indexN];                
                indexN--;
                indexTotal--;                
            }
        }

        while (indexN > -1)
        {
            nums1[indexTotal] = nums2[indexN];
            indexN--;
            indexTotal--;
        }                
    }
};
