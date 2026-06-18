class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currOnesCnt = 0, maxCnt = 0;
        for(int i : nums) {
            if(i == 1) {
                currOnesCnt++;
            }
            else {
                maxCnt = max(maxCnt, currOnesCnt);
                currOnesCnt = 0;
            }
        }
        maxCnt = max(maxCnt, currOnesCnt);
        return maxCnt;
    }
};