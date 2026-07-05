class Solution {
public:
    const int MOD = 1e9 + 7;
    int m, n;

    vector<pair<int,int>> dirs = {{0,-1}, {-1,0}, {-1,-1}};

    // {maxScore, ways}
    vector<vector<pair<int,int>>> dp;
    vector<vector<bool>> vis;

    pair<int,int> dfs(int i, int j, vector<string>& board) {

        if(i < 0 || j < 0 || board[i][j] == 'X')
            return {-1, 0};

        if(i == 0 && j == 0)
            return {0, 1};

        if(vis[i][j])
            return dp[i][j];

        vis[i][j] = true;

        int best = -1;
        int ways = 0;

        for(auto &[di, dj] : dirs) {

            auto [score, cnt] = dfs(i + di, j + dj, board);

            if(score == -1)
                continue;

            if(score > best) {
                best = score;
                ways = cnt;
            }
            else if(score == best) {
                ways = (ways + cnt) % MOD;
            }
        }

        if(best == -1)
            return dp[i][j] = {-1, 0};

        int val = 0;
        if(board[i][j] != 'S' && board[i][j] != 'E')
            val = board[i][j] - '0';

        return dp[i][j] = {best + val, ways};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {

        m = board.size();
        n = board[0].size();

        dp.assign(m, vector<pair<int,int>>(n));
        vis.assign(m, vector<bool>(n, false));

        auto [score, ways] = dfs(m - 1, n - 1, board);

        if(score == -1)
            return {0, 0};

        return {score, ways};
    }
};