class Solution {
private:
    bool isPalin(string s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int n = s.length();
        int i = 0, j = n - 1;
        while(i<j) {
            if(s[i] != s[j]) {
                return isPalin(s, i + 1, j) || isPalin(s, i, j - 1);
            }
            i++;
            j--;
        }
        return true;
    }
};