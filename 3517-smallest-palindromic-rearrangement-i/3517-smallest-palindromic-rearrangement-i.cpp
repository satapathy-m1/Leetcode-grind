class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        string half = s.substr(0, n / 2);
        sort(begin(half), end(half));
        string ans = half;
        if(n % 2 == 1) ans += s[n / 2];
        reverse(begin(half), end(half));
        ans += half;
        return ans;
    }
};