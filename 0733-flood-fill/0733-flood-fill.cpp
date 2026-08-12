class Solution {
private:
    vector<pair<int, int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int ogc = image[sr][sc];
        if(ogc == color) return image;
        image[sr][sc] = color;
        while(!q.empty()) {
            int s = q.size();
            while(s--) {
                auto [r, c] = q.front();
                q.pop();
                
                for(auto [dr, dc] : dirs) {
                    int nr = r + dr, nc = c + dc;
                    if(nr >= 0 && nr < m && nc >= 0 && nc < n && image[nr][nc] == ogc) {
                        q.push({nr, nc});
                        image[nr][nc] = color;
                    }
                }
            }
        }
        return image;
    }
};