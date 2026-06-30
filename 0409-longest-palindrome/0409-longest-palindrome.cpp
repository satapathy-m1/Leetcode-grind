class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        vector<int> lower(26, 0), upper(26, 0);
        for(char c : s) {
            if(c >= 'a' && c <= 'z') lower[c - 'a']++;
            else upper[c - 'A']++;
        }
        int cnt = 0;
        bool flag = false;
        for(int i = 0; i < 26; i++) {
            if(lower[i] % 2 == 0) {
                cnt += lower[i];
                lower[i] = 0;
            } 
            else {
                cnt += lower[i] - 1;
                lower[i] = 1;
                flag = true;
            }
            
            if(upper[i] % 2 == 0) {
                cnt += upper[i];
                upper[i] = 0;
            }
            else {
                cnt += upper[i] - 1;
                upper[i] = 1;
                flag = true;
            }
        }
        if(flag == true) cnt += 1;
        return cnt;
    }
};