// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

/*
Time Limit Exceeded 
*/

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {   
        std::vector<int>::iterator buy = prices.begin();
        std::vector<int>::iterator sell = prices.end(); // pointer PAST the last element
        
        // empty vector;
        if (buy == sell) return 0;
                   
        int maxProfit = 0;
        bool hasMoved = true;
        
        //while (buy != sell/* && hasMoved*/)
        
        for (buy = prices.begin(); buy != prices.end()-2; buy++)
        {
            for (sell = buy+1; sell < prices.end(); sell++)
            {                
                int currentProfit;                                
                if ((currentProfit = *sell - *buy) > maxProfit)
                {
                    maxProfit = currentProfit;
                }
            }
        }
        return maxProfit;
    }
};


/*
not working attempt
 */

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {         
        std::vector<int>::iterator buy = prices.begin();
        std::vector<int>::iterator sell = prices.end(); // pointer PAST the last element
        
        // empty vector;
        if (buy == sell) return 0;
        
        sell--;  // move the last element itself        
        int maxProfit = 0;
        bool hasMoved = true;
        
        while (buy != sell/* && hasMoved*/)
        {
            hasMoved = false;
            // move iterator right
            while (buy != sell && *(buy+1) <= *buy) {buy++; hasMoved = true;}
            // move iterator left
            while (buy != sell && *sell <= *(sell-1)) {sell--; hasMoved = true;}                        

            // maybe we are stucked in a local maximum or minimum
            if (buy != sell && !hasMoved)
            {
                // we give a little bump to the side which has the lesser difference :D
                int leftDifference = *(buy+1) - *buy;
                int rightDifference = *sell - *(sell-1);
                if (leftDifference < rightDifference)
                { buy++; }
                else
                { sell--; }
                hasMoved = true;
            }
            
            int currentProfit = *sell - *buy;
            if (currentProfit > maxProfit) {maxProfit = currentProfit; }
        }
        
        return maxProfit;
    }
};