class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(begin(clips), end(clips), [&](vector<int>& a, vector<int>& b) {
            if(a[0] == b[0]) return b[1] < a[1];
            return a[0] < b[0];
        });
        int currEnd = 0, nextEnd = 0;
        int i = 0, n = clips.size(), cnt = 0;
        while(i < n && clips[i][0] <= currEnd) {
            while(i < n && clips[i][0] <= currEnd) {
                nextEnd = max(nextEnd, clips[i][1]);
                i++;
            }
            cnt++;
            currEnd = nextEnd;
            if(currEnd >= time) return cnt;
        }
        return -1;
    }
};