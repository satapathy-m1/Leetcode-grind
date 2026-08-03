class Solution {
private:
vector<int> dp;
    bool dfs(int i, string cur, int n, string s, unordered_set<string>& st) {
        if(i == n) {
            if(cur.size() == 0 || st.count(cur)) return true;
            return false; 
        }
        if(dp[i] != -1) return dp[i];

        for(int j = i; j < n; j++) {
            cur += s[j];
            if(st.count(cur)) {
                if(dfs(j + 1, "", n, s, st)) return true;
            }
        }
        return dp[i] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> st(begin(wordDict), end(wordDict));
        dp.resize(n, -1);
        return dfs(0, "", n, s, st);
    }
};