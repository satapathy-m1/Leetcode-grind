class Solution {
public:
    int f(int i, int xorr, int n, vector<int>& nums, int target, vector<vector<int>>& dp) {
        if(i >= n) return (xorr == target ? 0 : 1e9);
        if(dp[i][xorr] != -1) return dp[i][xorr];

        int take = f(i + 1, xorr^nums[i], n, nums, target, dp);
        int notT = 1 + f(i + 1, xorr, n, nums, target, dp);

        return dp[i][xorr] = min(take, notT);
    }
    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(16384, 1e9));
        dp[n][target] = 0;
        for(int i = n - 1; i >= 0; i--) {
            for(int xorr = 0; xorr <= 16383; xorr++) {
                int take = dp[i + 1][xorr ^ nums[i]];
                int notT = 1 + dp[i + 1][xorr];
                dp[i][xorr] = min(take, notT);
            }
        }
        
        return dp[0][0] >= 1e9 ? -1 : dp[0][0];
    }
};