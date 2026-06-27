class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long, int> mpp;
        for(int i : nums) {
            mpp[i]++;
        }
        int ans = 0;
        if(mpp[1] % 2 == 1) ans = max(ans, mpp[1]);
        else ans = max(ans, mpp[1] - 1);
        for(auto &[x, freq] : mpp) {
            if(x == 1) continue;
            int len = 0;
            long long num = x;
            while(mpp.count(num) && mpp[num] >= 2) {
                len += 2;
                if(num > 1e9) break;
                num = num * num;
            }
            if(mpp.count(num)) len++;
            else len--;
            ans = max(ans, len);
        }
        return ans;
    }
};