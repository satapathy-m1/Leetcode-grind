class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = size(nums);
        sort(begin(nums), end(nums));
        long long i = 0, j = 0, sum = 0;
        long long ans = 0;
        while(j < n) {
            sum += nums[j];
            long long cost = (j - i + 1) * (nums[j]) - sum;
            while(i <= j && cost > k) {
                cost -= nums[i];
                sum -= nums[i];
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};