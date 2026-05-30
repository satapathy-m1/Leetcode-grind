class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> rowMax(n), colMax(n);
        for(int i = 0; i < n; i++) {
            int maxi = -1;
            for(int j = 0; j < n; j++) {
                maxi = max(maxi, grid[i][j]);
            }
            rowMax[i] = maxi;
        }
        for(int j = 0; j < n; j++) {
            int maxi = -1;
            for(int i = 0; i < n; i++) {
                maxi = max(maxi, grid[i][j]);
            }
            colMax[j] = maxi;
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans += (min(rowMax[i], colMax[j]) - grid[i][j]);
            }
        }
        return ans;
    }
};