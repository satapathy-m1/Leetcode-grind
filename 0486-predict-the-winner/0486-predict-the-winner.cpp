class Solution {
private:
vector<vector<int>> dp;
    int f(int i, int j, vector<int>& nums) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int c1 = nums[i] + min(f(i + 2, j, nums), f(i + 1, j - 1, nums));
        int c2 = nums[j] + min(f(i, j - 2, nums), f(i + 1, j - 1, nums));

        return dp[i][j] = max(c1, c2);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = size(nums);
        int i = 0, j = n - 1;
        dp.resize(n + 2, vector<int>(n + 2, -1));
        int sum = accumulate(begin(nums), end(nums), 0);
        int ans = f(i, j, nums);
        return ans >= (sum+1) / 2;
    }
};