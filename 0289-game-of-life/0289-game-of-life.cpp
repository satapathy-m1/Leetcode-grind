class Solution {
private:
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, -1}, {1, 1}, {-1, 1}, {-1, -1}};
    int m, n;
    bool isSafe(int ni, int nj) {
        return ni >= 0 && ni < m && nj >= 0 && nj < n;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size(), n = board[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                bool isLive = board[i][j];
                int liveCnt = 0, deadCnt = 0;
                for(auto [di, dj] : dirs) {
                    int ni = i + di, nj = j + dj;
                    if(isSafe(ni, nj)) {
                        if(board[ni][nj] == 1) liveCnt++;
                        else deadCnt++;
                    }
                }
                if(isLive) {
                    if(liveCnt == 2 || liveCnt == 3) ans[i][j] = 1;
                    else ans[i][j] = 0;
                }
                else {
                    if(liveCnt == 3) ans[i][j] = 1;
                }
            }
        }
        board = ans;
    }
};