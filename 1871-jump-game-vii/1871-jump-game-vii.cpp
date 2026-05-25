class Solution {
public:
    int minJ, maxJ;
    int f(int i, int n, string s, vector<int>& dp) {
        if(i == n - 1) return true;
        if(i >= n) return false;
        if(dp[i] != -1) return dp[i];
        bool ans = false;
        for(int j = i + minJ; j <= min(n - 1, i + maxJ); j++) {
            if(s[j] == '0') ans = ans || f(j, n, s, dp);
        }
        return dp[i] = ans;
    }
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if(s[n - 1] == '1') return false;
        int farthest = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int i = q.front();
            q.pop();
            if(i == n - 1) return true;
            int j = max(i + minJump, farthest + 1);
            while(j <= min(n - 1, i + maxJump)) {
                if(s[j] == '0') {
                    q.push(j);
                }
                farthest = j;
                j++;
            }
        }
        return false;
    }
};