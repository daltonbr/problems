// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

public class Solution
{
    public int MaxProfit(int[] prices)
    {
        var output = 0;
        for (int buyIndex = 0; buyIndex < prices.Length - 1; buyIndex++)
        {
            for (int sellIndex = buyIndex + 1; sellIndex < prices.Length; sellIndex++)
            {                
                int currentProfit;
                                
                if ((currentProfit = prices[sellIndex] - prices[buyIndex]) > output)
                {
                    output = currentProfit;
                }
            }
        }
        return output;
    }
}