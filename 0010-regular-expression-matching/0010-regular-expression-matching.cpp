class Solution {
private:
    vector<vector<int>> dp;
    bool f(int i, int j, int m, int n, string s, string p) {
        if(j == n) {
            return i == m;
        }
        if(dp[i][j] != -1) return dp[i][j];
        bool c1 = (i < m) && (s[i] == p[j] || p[j] == '.');
        if(j + 1 < n && p[j + 1] == '*') {
            return dp[i][j] = f(i, j + 2, m, n, s, p) || c1 && f(i + 1, j, m, n, s, p);
        }
        else {
            return dp[i][j] = c1 && f(i + 1, j + 1, m, n, s, p);
        }
    }
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        dp.assign(m + 1, vector<int>(n + 1, -1));
        return f(0, 0, m, n, s, p);
    }
};