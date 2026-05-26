class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> v1(26, 0), v2(26, 0);
        for(char c : word) {
            if(c >= 'a') v2[c - 'a']++;
            else v1[c - 'A']++;
        }
        int cnt = 0;
        for(int i = 0; i < 26; i++) {
            if(v1[i] != 0 && v2[i] != 0) cnt++;
        }
        return cnt;
    }
};