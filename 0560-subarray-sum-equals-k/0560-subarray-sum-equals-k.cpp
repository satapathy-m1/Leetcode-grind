class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int runningSum = 0;
        int i = 0;
        int ans = 0;
        while(i < n) {
            runningSum += nums[i];
            int rem = runningSum - k;
            if(mpp.count(rem)) ans += mpp[rem];
            mpp[runningSum]++;
            i++;
        }
        return ans;
    }
};