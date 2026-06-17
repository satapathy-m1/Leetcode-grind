class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp; // stores the sum with the count(the number of times we've seen this count before)
        int cnt = 0;
        int runningSum = 0;
 
        
        mpp[0] = 1;
        int i = 0;
        while(i < n) {
            runningSum = runningSum + nums[i];
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