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
        dp.resize(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        for(int i = n - 1; i >= 0; i--) {
            for(int flag = 0; flag < 2; flag++) {
                for(int K = 1; K <= k ; K++) {
                    int profit = 0;
                if(flag) {
                    int buyProfit = max(-prices[i] + dp[i + 1][!flag][K],  0 + dp[i + 1][flag][K]);
                    profit = max(profit, buyProfit);
                }
                else {
                    int sellProfit = max(prices[i] + dp[i + 1][!flag][K - 1],  0 + dp[i + 1][flag][K]); 
                    profit = max(profit, sellProfit);
                }
                dp[i][flag][K] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
};