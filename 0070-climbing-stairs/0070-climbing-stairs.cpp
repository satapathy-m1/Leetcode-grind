class Solution {
public:
    int f(int i, vector<int>& dp) {
        if(i <= 1) return 1;

        if(dp[i] != -1) return dp[i];

        return dp[i] = f(i - 1, dp) + f(i - 2, dp);
    }
    int climbStairs(int n) {
        if(n <= 1) return 1;
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};