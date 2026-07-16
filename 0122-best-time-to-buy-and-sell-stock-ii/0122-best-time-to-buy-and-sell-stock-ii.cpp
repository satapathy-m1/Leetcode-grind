class Solution {
private:
    int n;
    vector<vector<int>> dp;
    int f(int i, bool buy, vector<int>& prices) {
        if(i == n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int take = 0, notT = 0;
        if(buy) {
            take = -prices[i] + f(i + 1, !buy, prices);
            notT = f(i + 1, buy, prices);
        }
        else {
            take = prices[i] + f(i + 1, !buy, prices);
            notT = f(i + 1, buy, prices);
        }
        return dp[i][buy] = max(take, notT);
    }
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.resize(n + 1, vector<int>(2, -1));
        return f(0, 1, prices);
    }
};