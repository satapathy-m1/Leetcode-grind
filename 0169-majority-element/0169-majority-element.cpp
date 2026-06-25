class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate = nums[0];
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == candidate) {
                cnt++;
            }
            else cnt--;
            if(cnt == 0) {
                candidate = nums[i];
                cnt = 1;
            }
        }
        cnt = 0;
        for(int i : nums) if(i == candidate) cnt++;
        if(cnt > n / 2) return candidate;
        return -1;
    }
};