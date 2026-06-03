class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int m = landStartTime.size();
        int n = waterStartTime.size();
        int idx = -1;
        int minTime = 1e9;

        for(int i = 0; i < m; i++) {
            if(landStartTime[i] + landDuration[i] < minTime) {
                minTime = landStartTime[i] + landDuration[i];
                idx = i;
            }
        }

        int result1 = 1e9;
        for(int i = 0; i < n; i++) {
            result1 = min(result1, max(minTime, waterStartTime[i]) + waterDuration[i]);
        }

        
        minTime = 1e9;
        idx = -1;
        for(int i = 0; i < n; i++) {
            if(waterStartTime[i] + waterDuration[i] < minTime) {
                minTime = waterStartTime[i] + waterDuration[i];
                idx = i;
            }
        }
        int result2 = 1e9;
        for(int i = 0; i < m; i++) {
            result2 = min(result2, max(minTime, landStartTime[i]) + landDuration[i]);
        }
        return min(result1, result2);
    }
};