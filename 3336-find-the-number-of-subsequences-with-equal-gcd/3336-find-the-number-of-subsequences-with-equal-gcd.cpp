class Solution {
private:
    int n;
    int dp[201][201][201];
    const int mod = 1e9 + 7;
    int f(int i, int g1, int g2, vector<int>& nums) {
        if(i == n) return g1 == g2;
        if(dp[i][g1][g2] != -1) return dp[i][g1][g2];
        int c1 = f(i + 1, g1, g2, nums);
        int c2 = f(i + 1, gcd(g1, nums[i]), g2, nums);
        int c3 = f(i + 1, g1, gcd(g2, nums[i]), nums);

        return dp[i][g1][g2] = ((long long)c1 + c2 + c3) % mod;
    }
public:
    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return (f(0, 0, 0, nums) - 1 + mod) % mod;
    }
};