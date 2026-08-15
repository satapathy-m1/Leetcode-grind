class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(2, 0);
        int k = 1;
        int i = 0, j = 0;
        int maxLen = 0;
        while(j < n) {
            freq[nums[j]]++;
            while(i <= j && nums[j] == 0 && freq[0] > k) {
                freq[nums[i]]--;
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        
        return maxLen - 1;
    }
};