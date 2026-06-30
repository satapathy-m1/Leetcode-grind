class Solution {
private:
    vector<int> getLPS(string s) {
        int n = s.length();
        vector<int> LPS(n, 0);
        int pre = 0, suf = 1;
        while(suf < n) {
            if(s[pre] == s[suf]) {
                LPS[suf] = pre + 1;
                pre++;
                suf++;
            }
            else {
                if(pre == 0) {
                    LPS[suf] = 0;
                    suf++;
                }
                else {
                    pre = LPS[pre - 1];
                }
            }
            
        }
        return LPS;
    }
public:
    int strStr(string haystack, string needle) {
        vector<int> LPS = getLPS(needle);
        int n = haystack.size(), m = needle.size();
        int i = 0, j = 0;
        while(j < n) {
            if(haystack[j] == needle[i]) {
                i++;
                j++;
                if(i == m) return j - m;
            }
            else {
                if(i == 0) j++;
                else i = LPS[i - 1];
            }
        }
        return -1;
    }
};