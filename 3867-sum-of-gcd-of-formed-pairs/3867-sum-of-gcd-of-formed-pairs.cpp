class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1;
        vector<long long> pre(n);
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            pre[i] = gcd(nums[i], maxi);
        }
        sort(begin(pre), end(pre));
        int i = 0, j = n - 1;
        long long sum = 0;
        while(i < j) {
            sum += gcd(pre[i++], pre[j--]);
        }
        return sum;
    }
};