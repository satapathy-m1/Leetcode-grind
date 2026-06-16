class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int, int>> plantDetail(n);
        for(int i = 0; i < n; i++) {
            plantDetail.push_back({plantTime[i], growTime[i]});
        }
        auto lambda = [&](pair<int, int>& p1, pair<int, int>& p2) {
            return p1.second > p2.second;
        };
        sort(begin(plantDetail), end(plantDetail), lambda);
        
        int currPlantTime = 0;
        int currEndGrow = 0;
        for(auto detail : plantDetail) {
            currPlantTime = currPlantTime + detail.first;
            currEndGrow = max(currEndGrow, currPlantTime + detail.second);
        }

        return currEndGrow;
    }
};