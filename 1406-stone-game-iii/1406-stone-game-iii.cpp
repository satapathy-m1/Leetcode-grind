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
        dp.assign(n, -1);
        int diff = f(0, stoneValue, n);
        if(diff > 0) return "Alice";
        else if(diff < 0) return "Bob";
        else return "Tie";
    }
};