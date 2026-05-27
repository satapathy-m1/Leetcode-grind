class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<pair<int, int>> v1(26), v2(26);
        for(int i = 0; i < 26; i++) {
            v1[i] = {-1, -1};
            v2[i] = {-1, -1};
        }
        int idx = 0;
        for(char c : word) {
            if(c >= 'a') {
                v1[c- 'a'] = {1, idx};
            }
            else {
                if(v2[c - 'A'].first != -1) continue;
                else v2[c - 'A'] = {1, idx};
            }
            idx++;
        }
        int cnt = 0;
        for(int i = 0; i < 26; i++) {
            if(v1[i].first != -1 && v2[i].first != -1 
                && v1[i].second < v2[i].second) cnt++;
        }
        return cnt;
    }
};