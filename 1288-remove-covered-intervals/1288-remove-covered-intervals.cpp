class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        auto lambda = [&] (vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        };
        sort(begin(intervals), end(intervals), lambda);
        int lastEnd = -1;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(intervals[i][1] > lastEnd) {
                lastEnd = intervals[i][1];
                cnt++;
            } 
        }
        return cnt;
    }
};