class Solution {
public:
    vector<int> dp;
    int f(int i, vector<int>& stoneValue, int n) {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int result = stoneValue[i] - f(i + 1, stoneValue, n);
        if(i + 1 < n) result = max(result, stoneValue[i] + stoneValue[i + 1] - f(i + 2, stoneValue, n));
        if(i + 2 < n) result = max(result, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - f(i + 3, stoneValue, n));

        return dp[i] = result;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.assign(n + 1, 0);
        int a1 = 0, a2 = 0, a3 = 0;
        for(int i = n - 1; i >= 0; i--) {
            int result = stoneValue[i] - a1;
            if(i + 1 < n) result = max(result, stoneValue[i] + stoneValue[i + 1] - a2);
            if(i + 2 < n) result = max(result, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - a3);

            dp[i] = result;
            a3 = a2;
            a2 = a1;
            a1 = dp[i];
        }
        int diff = dp[0];
        if(diff > 0) return "Alice";
        else if(diff < 0) return "Bob";
        else return "Tie";
    }
};