class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int i = 0, j = 0;
        vector<int> freq(26, 0);
        int maxLen = 0;
        
        while(j < n) {
            freq[s[j] - 'a']++;
            while(i < j && (*max_element(begin(freq), end(freq)) > 2)) {
                freq[s[i] - 'a']--;
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};