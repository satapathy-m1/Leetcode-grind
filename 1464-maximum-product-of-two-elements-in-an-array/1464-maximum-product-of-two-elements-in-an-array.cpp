class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        int curr_max = nums[0];
        for(int i = 1; i < n; i++)
        {
            result = max(result, (curr_max - 1) * (nums[i] - 1));
            curr_max = max(curr_max, nums[i]);
        }
        return result;
    }
};