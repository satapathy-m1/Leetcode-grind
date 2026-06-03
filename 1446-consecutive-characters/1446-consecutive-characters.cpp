class Solution {
public:
    int maxPower(string s) {
        int n = s.length();
        int i = 0, j = 1;
        int ans = 1;
        while(j < n) {
            if(s[i] == s[j]) j++;
            else {
                ans = max(ans, j - i);
                i = j;
                j++;
            }
        }
        ans = max(ans, j - i);
        return ans;
    }
};