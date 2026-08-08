class Solution {
private:
    int m, n, s;
    vector<pair<int, int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool dfs(int i, int j, int idx, string word, vector<vector<bool>>& vis, vector<vector<char>>& board) {
        if(idx == s) return true;
        vis[i][j] = true;
        for(auto [di, dj] : dirs) {
            int ni = i + di, nj = j + dj;
            if(ni >= 0 && ni < m && nj >= 0 && nj < n && !vis[ni][nj] && board[ni][nj] == word[idx]) {
                if(dfs(ni, nj, idx+1, word, vis, board)) return true;
            }
        } 
        vis[i][j] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size(), s = word.size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    vector<vector<bool>> vis(m, vector<bool>(n, 0));
                    if(dfs(i, j, 1, word, vis, board)) return true;
                }
            }
        }
        return false;
    }
};