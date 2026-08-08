class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(begin(intervals), end(intervals));
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int lastEnding = intervals[0][1];

        for(int i = 1; i < n; i++) {
            if(intervals[i][0] <= lastEnding) {
                lastEnding = max(lastEnding, intervals[i][1]);
                ans[ans.size() - 1][1] = lastEnding;
            }
            else {
                lastEnding = intervals[i][1];
                ans.push_back({intervals[i][0], lastEnding});
            }
        }
        return ans;
    }
};