class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int> freq(26, 0);
        int i = 0, j = 0;
        int maxLen = 0;
        while(j < n) {
            freq[s[j] - 'A']++;
            while(i < j && (*max_element(begin(freq), end(freq)) + k < (j - i + 1))) {
                freq[s[i] - 'A']--;
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};