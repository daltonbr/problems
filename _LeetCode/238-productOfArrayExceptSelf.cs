// https://leetcode.com/problems/product-of-array-except-self/description/

public class Solution
{
    public int[] ProductExceptSelf(int[] nums)
    {
        int n = nums.Length;
        int[] output = new int[n];
        output[0] = 1;
        
        for (int i = 1; i < n; i++)
        {
            output[i] = output[i - 1] * nums[i - 1];
        }

        int right = 1;       
        
        for (int i = n - 1; i >= 0; i--)
        {
            output[i] *= right;
            right *= nums[i];
        }        
        return output;
    }
}