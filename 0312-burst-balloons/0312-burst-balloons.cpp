class Solution {
private:
    int f(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        long long maxi = 0;
        for(int k = i; k <= j; k++) {
            maxi = max(maxi, 1ll*((nums[i - 1] * nums[k] * nums[j + 1]) + f(i, k-1, nums, dp) + f(k + 1, j, nums, dp)));
        }
        return dp[i][j] = maxi;
    }
public:

    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        reverse(begin(nums), end(nums));
        nums.push_back(1);
        reverse(begin(nums), end(nums));

        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return f(1, n - 2, nums, dp);
    }
};