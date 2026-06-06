class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1) return 1;
        int maxi = 1;
        for(int i = 0; i < n; i++) {
            unordered_map<double, int> mpp;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];
                double angle = atan2(dy, dx);
                if(mpp.find(angle) == mpp.end()) {
                    mpp[angle] = 2;
                }
                else mpp[angle]++;
            }
            for(auto it : mpp) maxi = max(maxi, it.second);
        }
        return maxi;
    }
};