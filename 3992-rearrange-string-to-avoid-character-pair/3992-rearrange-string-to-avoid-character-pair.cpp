class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int cnt = 0;
        string runningS = "";
        for(char c : s) {
            if(c == y) cnt++;
            else runningS += c;
        }
        string ans = string(cnt, y) + runningS;
        return ans;
    }
};