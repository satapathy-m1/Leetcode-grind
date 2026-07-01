class Solution {
private:
    vector<pair<int, int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    void multiSourceBFS(vector<vector<int>>& dist, vector<vector<int>>& grid, int n) {
        queue<pair<int, pair<int, int>>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.push({0, {i, j}});
                    dist[i][j] = 0;
                }
            }
        }
        while(!q.empty()) {
            int s = q.size();
            while(s--) {
                auto [d, co] = q.front();
                int i = co.first, j = co.second;
                q.pop();
                for(auto [di, dj] : dirs) {
                    int ni = i + di, nj = j + dj;
                    if(ni >= 0 && ni < n && nj >= 0 && nj < n && dist[ni][nj] > d + 1) {
                        dist[ni][nj] = d + 1;
                        q.push({d + 1, {ni, nj}});
                    }
                }
            }
        }
    }
    int getMax(vector<vector<int>>& dist, int n) {
        int maxi = -1;
        for(int i  = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                maxi = max(maxi, dist[i][j]);
            }
        }
        return maxi;
    }
    bool isPossibleForMid(int mid, vector<vector<int>>& dist, int n) {
        if(dist[0][0] < mid) return false;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        while(!q.empty()) {
            auto[i, j] = q.front();
            q.pop();
            if(i == n - 1 && j == n - 1) return true;
            for(auto [di, dj] : dirs) {
                int ni = i + di, nj = j + dj;
                if(ni >= 0 && ni < n && nj >= 0 && nj < n && dist[ni][nj] >= mid && !visited[ni][nj]) {
                    q.push({ni, nj});
                    visited[ni][nj] = true;
                }
            }
        }
        return false;
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return 0;
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        multiSourceBFS(dist, grid, n);
        int low = 0, high = getMax(dist, n), ans = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isPossibleForMid(mid, dist, n)) {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};