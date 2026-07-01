class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        vector<int> pre(n), suf(n);
        pre[0] = 1;
        suf[n - 1] = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] >= nums[i - 1]) {
                pre[i] = pre[i - 1] + 1;
            }
            else pre[i] = 1;
        }
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i + 1] >= nums[i]) {
                suf[i] = suf[i + 1] + 1;
            }
            else suf[i] = 1;
        }
        int maxi = max(*max_element(begin(pre), end(pre)), *max_element(begin(suf), end(suf)));
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                maxi = max(maxi, suf[i + 1] + 1) ;
            }
            else if(i == n - 1) {
                maxi = max(maxi, pre[i - 1] + 1);
            }
            else if(nums[i - 1] > nums[i + 1]) {
                maxi = max(maxi, max(pre[i - 1], suf[i + 1]) + 1);
            }
            else {
                maxi = max(maxi, pre[i - 1] + suf[i + 1] + 1);
            }
        }
        return maxi;
    }
};