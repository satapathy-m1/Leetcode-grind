class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1) return 1;
        int maxi = 2;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int cnt = 2;
                double slope = (double)(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                for(int k = 0; k < n; k++) {
                    if(k == i || k == j) continue;
                    double slope_2 = (double)(points[k][1] - points[i][1]) / (points[k][0] - points[i][0]);
                    cnt += (slope_2 == slope);
                    maxi = max(cnt, maxi);
                }
            }
        }
        return maxi;
    }
};