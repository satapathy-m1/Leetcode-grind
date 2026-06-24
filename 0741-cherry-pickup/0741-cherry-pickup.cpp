class Solution {
private:
    int dp[51][51][51];
    int f(int r1, int c1, int r2, int n, vector<vector<int>>& grid) {
        int c2 = r1 + c1 - r2;

        if(r1 == n - 1 && c1 == n - 1)
            return grid[r1][c1];
        if(r1 >= n || c1 >= n || r2 >= n || c2 >= n) return INT_MIN;
        if(grid[r1][c1] == -1 || grid[r2][c2] == -1) return INT_MIN;
        if(dp[r1][c1][r2] != -1) return dp[r1][c1][r2];

        int curr = 0;
        if(r1 == r2 && c1 == c2) curr += grid[r1][c1];
        else curr += (grid[r1][c1] + grid[r2][c2]);

        int best = max({
            f(r1 + 1, c1, r2 + 1, n, grid),
            f(r1 + 1, c1, r2, n, grid),
            f(r1, c1 + 1, r2 + 1, n, grid),
            f(r1, c1 + 1, r2, n, grid)
        });

        return dp[r1][c1][r2] = curr + best;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        memset(dp, -1, sizeof(dp));
        int ans = f(0, 0, 0, n, grid);
        return ans < 0 ? 0 : ans;
    }
};