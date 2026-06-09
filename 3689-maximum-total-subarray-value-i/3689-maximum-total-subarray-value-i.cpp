class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxi = *max_element(begin(nums), end(nums));
        int mini = *min_element(begin(nums), end(nums));
        return 1ll * (maxi - mini) * k;
    }
};