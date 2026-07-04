class Solution {
private:
    vector<vector<int>> dp;
    int f(int i, int j, int m, int n, vector<int>& nums1, vector<int>& nums2) {
        if(i >= m || j >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ways1 = 0, ways2 = 0;
        if(nums1[i] == nums2[j]) {
            ways1 = 1 + f(i + 1, j + 1, m, n, nums1, nums2);
        }
        else {
            ways2 = max(f(i, j + 1, m, n, nums1, nums2), f(i + 1, j, m, n, nums1, nums2));
        }
        return dp[i][j] = max(ways1, ways2);
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        dp.resize(m + 1, vector<int>(n + 1, 0));
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                int ways1 = 0, ways2 = 0;
                if(nums1[i] == nums2[j]) ways1 = 1 + dp[i + 1][j + 1];
                else {
                    ways2 = max(dp[i + 1][j], dp[i][j + 1]);
                }
                dp[i][j] = max(ways1, ways2);
            }
        }
        return dp[0][0];
    }
};