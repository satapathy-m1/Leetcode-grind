class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = size(nums);
        long long maxi = -1;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                long long curr = (1ll*nums[i]*nums[j]) / (pow(gcd(nums[i], nums[j]), 2));
                maxi = max(maxi, curr);
            }
        }
        return maxi;
    }
};