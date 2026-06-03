class Solution {
public:
    vector<vector<int>> dp;
    int f(int i, int flag, int n, vector<int>& prices) {
        if(i == n) return 0;
        if(dp[i][flag] != -1) return dp[i][flag];
        int profit = 0;
        if(flag) {
            int buyProfit = max(-prices[i] + f(i + 1, !flag, n, prices), 0 + f(i + 1, flag, n, prices));
            profit = max(profit, buyProfit);
        }
        else {
            int sellProfit = max(prices[i] + f(i + 1, !flag, n, prices), 0 + f(i + 1, flag, n, prices));
            profit = max(profit, sellProfit);
        }
        return dp[i][flag] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n + 1, vector<int>(2, -1));
        return f(0, 1, n, prices);
    }
};