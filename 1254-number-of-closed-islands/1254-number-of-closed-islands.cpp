class Solution {
private:
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(int i, int j, int m, int n, vector<vector<int>>& grid) {
        if(i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 0) {
            grid[i][j] = 1;
            for(auto [di, dj] : dirs) {
                int ni = i + di, nj = j + dj;
                dfs(ni, nj, m, n, grid);
            }
        }
        else return;
    }
public:

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++) {
            dfs(i, 0, m, n, grid);
            dfs(i, n - 1, m, n, grid);
        }
        for(int j = 0; j < n; j++) {
            dfs(0, j, m, n, grid);
            dfs(m - 1, j, m, n, grid);
        }

        int numOfIslands = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    dfs(i, j, m, n, grid); 
                    numOfIslands++;
                }
            }
        }
        return numOfIslands;
    }
};