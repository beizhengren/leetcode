// Solution 1
// dp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int> > dp (prices.size(), vector<int>(2, 0));
        dp[0][0] = 0; //持有现金
        dp[0][1] = -prices[0]; //持有股票

        for (int i = 1; i < prices.size(); ++i) {
            //第i天持有现金 = max( 第i-1天持有现金, 第i-1天持有股票 + 第i天的股价）
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            //第i天持有股票 = max( 第i-1天持有股票, 第i-1天持有现金 - 第i天的股价）
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }

        return dp[prices.size()-1][0];
    }
};

// Solution 2
// 贪心
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        
        for (int i = 1; i < prices.size(); ++i) {
            //计算相邻两天的买入卖出后的利润
            int profit = prices[i] - prices[i-1];
            if (profit > 0) {
                result += profit;
            }
        }
        return result;
    }
};
