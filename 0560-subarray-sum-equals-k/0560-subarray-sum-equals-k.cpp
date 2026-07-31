class Solution {
private:
    
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int runningSum = 0;
        int cnt = 0;
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        while(i < n) {
            runningSum += nums[i];
            if(mpp.find(runningSum - k) == mpp.end()) {
                mpp[runningSum]++;
            }
            else {
                cnt += mpp[runningSum - k];
                mpp[runningSum]++;
            }
            i++;
        }
        return cnt;
    }
};