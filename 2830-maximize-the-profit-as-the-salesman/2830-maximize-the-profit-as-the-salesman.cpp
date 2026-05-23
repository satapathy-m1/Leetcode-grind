class Solution {
public:
    int bsHelper(int target, vector<vector<int>>& offers) {
        int low = 0, high = offers.size() - 1;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(target < offers[mid][0]) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
    int f(int idx, int n, vector<vector<int>>& offers, vector<int>& dp) {
        if(idx >= offers.size()) return INT_MIN;
        if(dp[idx] != -1) return dp[idx];
        int notT = f(idx + 1, n, offers, dp);
        int take = offers[idx][2];
        int nextIdx = bsHelper(offers[idx][1], offers);
        if(nextIdx != -1) take += f(nextIdx, n, offers, dp);

        return dp[idx] = max(take, notT);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(begin(offers), end(offers));
        int m = offers.size();
        vector<int> dp(offers.size() + 2, 0);
        dp[m] = INT_MIN;
        for(int i = m - 1; i >= 0; i--) {
            int notT = dp[i + 1];
            int take = offers[i][2];
            int nextIdx = bsHelper(offers[i][1], offers);
            if(nextIdx != -1) take += dp[nextIdx];
            dp[i] = max(notT, take);
        }
        return dp[0];
    }
};