class Solution {
private:
    int m, n;
    vector<vector<int>> dp;
    int f(int i, int j) {
        if(i == m - 1 && j == n - 1) return 1;
        if(i >= m || j >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = f(i + 1, j) + f(i, j + 1);
    }
public:
    int uniquePaths(int m, int n) {
        this -> m = m;
        this -> n = n;
        dp.assign(m + 1, vector<int>(n + 1, 0));

        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(i == m - 1 && j == n - 1) dp[i][j] = 1;
                else dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }
        return dp[0][0];
    }
};