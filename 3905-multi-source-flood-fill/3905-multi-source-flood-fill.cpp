class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<vector<int>> timeArr(n, vector<int>(m, INT_MAX));
        queue<pair<int, pair<int, pair<int, int>>>> q;
        
        for(auto source : sources) {
            int r = source[0], c = source[1], color = source[2];
            q.push({color,{0, {r, c}}});
            grid[r][c] = color;
            timeArr[r][c] = 0;
        }

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto [color, secondPart] = q.front();
                q.pop();
                int time = secondPart.first;
                auto coordinates = secondPart.second;
                int r = coordinates.first;
                int c = coordinates.second;
                for(auto [dr, dc] : directions) {
                    int nr = r + dr, nc = c + dc;
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m) {
                        if(timeArr[nr][nc] > time + 1) {
                            grid[nr][nc] = grid[r][c];
                            timeArr[nr][nc] = time + 1;
                            q.push({color, {timeArr[nr][nc], {nr, nc}}});
                        }
                        else if(timeArr[nr][nc] == time + 1) {
                            grid[nr][nc] = max(grid[nr][nc], grid[r][c]);
                        }
                    }
                    
                }
            }
        }
        return grid;
    }
};