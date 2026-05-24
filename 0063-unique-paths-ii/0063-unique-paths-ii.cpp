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
        vector<long long> curr(n + 1, 0), ahead(n + 1, 0);
        curr[n - 1] = 1;

        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(i == m - 1 && j == n - 1) continue;
                if(obstacleGrid[i][j] == 1) curr[j] = 0;
                else curr[j] = ahead[j] + curr[j + 1];
            }
            ahead = curr;
        }
        return ahead[0];
    }
};