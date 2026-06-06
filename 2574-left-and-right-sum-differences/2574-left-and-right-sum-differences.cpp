class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(begin(nums), end(nums), 0);
        int runningSum = 0;
        int cumSum = 0;
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            cumSum += nums[i];
            ans.push_back(abs(totalSum - cumSum - runningSum));
            runningSum += nums[i];
        }
        return ans;
    }
};