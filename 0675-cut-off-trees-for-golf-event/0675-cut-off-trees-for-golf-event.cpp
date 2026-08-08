class Solution {
private:
    typedef pair<int, pair<int, int>> pp;
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int bfs(int srcR, int srcC, int destR, int destC, vector<vector<int>>& forest) {
        int m = forest.size(), n = forest[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        vis[srcR][srcC] = true;
        queue<pp> q;
        q.push({0, {srcR, srcC}});
        
        while(!q.empty()) {
            auto [steps, co] = q.front();
            q.pop();
            auto [r, c] = co;

            if(r == destR && c == destC) return steps;

            for(auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && forest[nr][nc] != 0) {
                    q.push({steps+1, {nr, nc}});
                    vis[nr][nc] = true;
                }
            }
        }
        return -1;
    }
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size(), n = forest[0].size();
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(forest[i][j] > 1) {
                    pq.push({forest[i][j], {i, j}});
                }
            }
        }
        int minSteps = 0;
        int curR = 0, curC = 0;
        while(!pq.empty()) {
            auto [h, co] = pq.top();
            pq.pop();
            auto [destR, destC] = co;
            int steps = bfs(curR, curC, destR, destC, forest);
            if(steps == -1) return -1;
            minSteps += steps;
            curR = destR;
            curC = destC;
        }
        return minSteps;
    }
};