class Solution {
private:
    int n;
    vector<vector<int>> dp;
    int f(int i, int j, vector<int>& piles) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int c1 = piles[i] + min(f(i + 2, j, piles), f(i + 1, j - 1, piles));
        int c2 = piles[j] + min(f(i, j - 2, piles), f(i + 1, j - 1, piles));

        return dp[i][j] = max(c1, c2);
    }
public:
    bool stoneGame(vector<int>& piles) {
        n = size(piles);
        dp.resize(n + 2, vector<int>(n + 2, -1));
        int ans = f(0, n - 1, piles);
        int sum = accumulate(begin(piles), end(piles), 0);
        return ans >= (sum) / 2;
    }
};