class Solution {
private:
    int n;
    vector<int> dp;
    int f(int i, vector<int>& stoneValue) {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        int result = stoneValue[i] - f(i + 1, stoneValue);
        if(i + 1 < n) result = max(result, stoneValue[i] + stoneValue[i + 1] - f(i + 2, stoneValue));
        if(i + 2 < n) {
            result = max(result, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - f(i + 3, stoneValue));
        }

        return dp[i] = result;
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        n = size(stoneValue);
        dp.resize(n + 1, -1);
        int ans = f(0, stoneValue);
        if(ans > 0) return "Alice";
        else if(ans < 0) return "Bob";
        else return "Tie";
    }
};