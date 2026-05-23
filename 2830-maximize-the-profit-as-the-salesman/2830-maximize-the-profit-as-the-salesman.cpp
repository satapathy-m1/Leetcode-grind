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
        vector<int> dp(offers.size() + 1, -1);
        return f(0, n, offers, dp);
    }
};