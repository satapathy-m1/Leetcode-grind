class Solution {
public:
    string solve(int cnt, int n, string ans) {
        if(cnt == n) return ans;
        int s = ans.size();
        int i = 0;
        string next = "";
        while(i < s) {
            int curCnt = 0;
            char c = ans[i];
            while(i < s && ans[i] == c) {
                curCnt++;
                i++;
            }
            next += to_string(curCnt);
            next += string(1, c);
        }
        return solve(cnt + 1, n, next);
    }
    string countAndSay(int n) {
        if(n == 1) return "1";
        int cnt = 0;
        string ans = "1";
        return solve(cnt, n - 1, ans);
    }
};