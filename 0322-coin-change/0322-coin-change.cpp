class Solution {
private:
int n;
    int f(int i, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        
        if(i == n - 1) {
            if(amount % coins[i] == 0) return amount / coins[i];
            return 1e9;
        }
        if(dp[i][amount] != -1) return dp[i][amount];
        int take = 1e9;
        if(coins[i] <= amount) take = 1 + f(i, coins, amount - coins[i], dp);
        int notT = f(i + 1, coins, amount, dp);

        return dp[i][amount] = min(take, notT);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = f(0, coins, amount, dp);
        return ans == 1e9 ? -1 : ans;
    }
};