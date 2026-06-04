class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, maxCnt = 0;
        for(int i : nums) {
            if(i == 1) cnt++;
            else {
                maxCnt = max(maxCnt, cnt);
                cnt = 0;
            }
        }
        maxCnt = max(maxCnt, cnt);
        return maxCnt;
    }
};