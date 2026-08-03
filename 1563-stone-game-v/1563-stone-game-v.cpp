class Solution {
private:
vector<vector<int>> dp;
    int f(int s, int e, vector<int>& stoneValue) {
        if(s > e) return 0;
        if(dp[s][e] != -1) return dp[s][e];

        int r = 0;
        for(int i = s; i <= e; i++) {
            r += stoneValue[i];
        }

        int l = 0;
        int ans = 0;
        for(int i = s; i < e; i++) {
            r -= stoneValue[i];
            l += stoneValue[i];
            if(r > l) {
                ans = max(ans, l + f(s, i, stoneValue));
            }
            else if(l > r) {
                ans = max(ans, r + f(i + 1, e, stoneValue));
            }
            else {
                ans = max({ans, l + f(i + 1, e, stoneValue), r + f(s, i, stoneValue)});
            }
        }
        return dp[s][e] = ans;
    }
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.resize(n, vector<int>(n, -1));
        return f(0, n - 1, stoneValue);
    }
};