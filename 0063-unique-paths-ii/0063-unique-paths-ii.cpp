class Solution {
public:
    int f(int i, int j, int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        if(i >= m || j >= n || obstacleGrid[i][j]) return 0;
        if(i == m - 1 && j == n - 1) return 1;
        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = f(i + 1, j, m, n, obstacleGrid, dp) + f(i, j + 1, m, n, obstacleGrid, dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        dp[m - 1][n - 1] = 1;

        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(i == m - 1 && j == n - 1) continue;
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }
        return dp[0][0];
    }
};