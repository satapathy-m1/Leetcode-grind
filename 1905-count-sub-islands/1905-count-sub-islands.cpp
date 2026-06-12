class Solution {
public:
    int m, n;
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    bool isSafe(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    void dfs(int i, int j, vector<vector<bool>>& visited, bool &flag, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        visited[i][j] = true;
        if(grid1[i][j] != 1) flag = true;
        for(auto [di, dj] : dirs) {
            int ni = i + di, nj = j + dj;
            if(isSafe(ni, nj) && !visited[ni][nj] && grid2[ni][nj] == 1) {
                dfs(ni, nj, visited, flag, grid1, grid2);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size(), n = grid1[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int cnt = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && grid2[i][j] == 1) {
                    bool flag = false;
                    dfs(i, j, visited, flag, grid1, grid2);
                    if(flag == false) cnt++;
                }
            }
        }
        return cnt;
    }
};