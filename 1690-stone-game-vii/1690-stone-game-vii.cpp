class Solution {
private:
    int n;
    vector<int> pre;
    vector<vector<int>> dp;
    
    int f(int l, int r, vector<int>& stones) {
        if(l >= r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        
        int c1 = pre[r + 1] - pre[l + 1] - f(l + 1, r, stones);
        int c2 = pre[r] - pre[l] - f(l, r - 1, stones);

        return dp[l][r] = max(c1, c2);
    }
public:
    int stoneGameVII(vector<int>& stones) {
        n = stones.size();
        pre.resize(n + 1, 0);
        dp.resize(n, vector<int>(n, -1));
        pre[0] = 0;
        for(int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + stones[i];
        }
        return f(0, n - 1, stones);
    }
};