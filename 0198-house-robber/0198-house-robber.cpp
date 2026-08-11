class Solution {
private:
    int n;
    vector<int> dp;
    int f(int i, vector<int>& nums) {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        int steal = nums[i] + f(i + 2, nums);
        int notSteal = 0 + f(i + 1, nums);
        
        return dp[i] = max(steal, notSteal);
    }
public:
    int rob(vector<int>& nums) {
        n = nums.size();
        dp.assign(n + 1, -1);
        return f(0, nums);
    }
};