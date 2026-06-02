class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;

        for (int i = 0; i < landStartTime.size(); i++) {
            for (int j = 0; j < waterStartTime.size(); j++) {
                int landFinish = landStartTime[i] + landDuration[i];
                int waterFinish = waterStartTime[j] + waterDuration[j];
                ans = min(
                    ans,
                    max(landFinish, waterStartTime[j]) + waterDuration[j]);
                ans = min(
                    ans,
                    max(waterFinish, landStartTime[i]) + landDuration[i]);
            }
        }

        return ans;
    }
};