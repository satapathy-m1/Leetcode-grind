class Solution {
public:
    vector<vector<int>> dp;
    int f(int i, int m, vector<int>& suffix, vector<int>& piles, int n) {
        if(i == n) return 0;
        if(dp[i][m] != -1) return dp[i][m];
        int maxi = -1;
        for(int x = 1; x <= 2*m; x++) {
            
            int nextIdx = min(i + x, n);

            int nextM = max(m,x);
            maxi = max(maxi, suffix[i] - f(nextIdx, nextM, suffix, piles, n));
        }
        return dp[i][m] = maxi;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        if(n == 1) return piles[0];
        vector<int> suffix(n);
        suffix[n - 1] = piles[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }
        dp.assign(n, vector<int>(n, -1));
        return f(0, 1, suffix, piles, n);
    }
};