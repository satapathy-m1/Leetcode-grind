class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        unordered_map<int, int> mpp;
        int maxLen = 1;
        while(j < n) {
            mpp[nums[j]]++;
            while(i < j && mpp[nums[j]] > k) {
                mpp[nums[i]]--;
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};