public class Solution
{
    public bool ContainsDuplicate(int[] nums)
    {
        HashSet<int> hashSet = new HashSet<int>();
        
        if (nums == null || nums.Length <= 1) return false;
        
        hashSet.Add(nums[0]);
        for (int i = 1; i < nums.Length; i++)
        {
            if (hashSet.Contains(nums[i]))
            {
                return true;
            }
            hashSet.Add(nums[i]);
        }
        return false;
    }
}