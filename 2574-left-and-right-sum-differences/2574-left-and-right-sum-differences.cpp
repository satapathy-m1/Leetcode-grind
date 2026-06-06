class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, 0), suf(n, 0), ans(n, 0);

        for(int i = 1; i < n; i++) pref[i] = pref[i - 1] + nums[i - 1];
        for(int i = n - 1; i >= 0; i--) {
            if(i != n - 1) suf[i] = suf[i + 1] + nums[i + 1];
            ans[i] = abs(suf[i] - pref[i]);
        }
        return ans;
    }
};