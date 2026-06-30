class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int> freq(256, 0);
        int i = 0, j = 0, len = 0;
        while(j < n) {
            while(i < j && freq[s[j]] != 0) {
                freq[s[i]]--;
                i++;
            }
            freq[s[j]] = 1;
            len = max(len, j - i + 1);
            j++;
        }
        return len;
    }
};