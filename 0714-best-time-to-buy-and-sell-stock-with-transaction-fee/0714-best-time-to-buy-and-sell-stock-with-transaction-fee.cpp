class Solution {
public:
    int fee;
    vector<vector<int>> dp;
    int f(int i, int flag, int n, vector<int>& prices) {
        if(i == n) return 0;
        if(dp[i][flag] != -1) return dp[i][flag];
        int buyProf = 0, sellProf = 0;
        if(flag) {
            buyProf = max(-prices[i] + f(i + 1, !flag, n, prices), f(i + 1, flag, n, prices));
        }
        else {
            sellProf = max(prices[i] + f(i + 1, !flag, n, prices) - fee, f(i + 1, flag, n, prices));
        }
        return dp[i][flag] = max(buyProf, sellProf);
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        this -> fee = fee;
        dp.resize(n + 1, vector<int>(2, -1));
        return f(0, 1, n, prices);
    }
};