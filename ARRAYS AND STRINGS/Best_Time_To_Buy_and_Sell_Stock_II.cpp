/*

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
 

Constraints:

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104

*/

#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        
        // Iterate through the array starting from the second day
        for (int i = 1; i < prices.size(); i++) {
            // If today's price is higher than yesterday's
            if (prices[i] > prices[i-1]) {
                // Add the profit from buying yesterday and selling today
                maxProfit += prices[i] - prices[i-1];
            }
        }
        
        return maxProfit;
    }
};

// Time Complexity: O(n), where n is the number of days (length of the prices array).
// We simply iterate through the array once.
// 
// Space Complexity: O(1), as we only use a single variable to track profit.
//
// Approach:
// This is a greedy algorithm that capitalizes on every price increase in the market.
// The key insight is that any profitable sequence of trades can be broken down into
// a series of adjacent profitable trades (buy low, sell high on consecutive days).
// - If prices[i] > prices[i-1], we buy at i-1 and sell at i
// - Otherwise, we don't make any transaction

