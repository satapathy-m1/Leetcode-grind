class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        vector<int> pre(n + 1, 0);
        for(int i = 0; i < n; i++) pre[i + 1] = pre[i] + (nums[i] == target); 
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int len = (j - i + 1);
                int cnt = pre[j + 1] - pre[i];
                ans += (cnt > len / 2);
            }
        }
        return ans;
    }
};