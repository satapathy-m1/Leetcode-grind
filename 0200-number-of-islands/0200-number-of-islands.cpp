class Solution {
public:
    int m, n;
    vector<pair<int, int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    void dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<char>>& grid) {
        vis[i][j] = true;
        for(auto [di, dj] : dirs) {
            int ni = i + di, nj = j + dj;
            if(ni >= 0 && ni < m && nj >= 0 && nj < n && !vis[ni][nj] && grid[ni][nj] == '1') {
                dfs(ni, nj, vis, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int cnt = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    dfs(i, j, vis, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};