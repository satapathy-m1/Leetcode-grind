class Solution {
public:
    vector<vector<vector<int>>> dp;
    int f(int i, int flag, int k, int n, vector<int>& prices) {
        if(i == n || k == 0) return 0;
        if(dp[i][flag][k] != -1) return dp[i][flag][k];
        int profit = 0;
        if(flag) {
            int buyProfit = max(-prices[i] + f(i + 1, !flag, k, n, prices), 0 + f(i + 1, flag, k, n, prices));
            profit = max(profit, buyProfit);
        }
        else {
            int sellProfit = max(prices[i] + f(i + 1, !flag, k - 1, n, prices), 0 + f(i + 1, flag, k, n, prices)); 
            profit = max(profit, sellProfit);
        }
        return dp[i][flag][k] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        dp.resize(n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return f(0, 1, k, n, prices);
    }
};