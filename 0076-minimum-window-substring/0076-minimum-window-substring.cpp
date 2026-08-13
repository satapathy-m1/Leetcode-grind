class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        unordered_map<char, int> ms, mt;
        for(char c : t) mt[c]++;
        int i = 0, j = 0;
        int minLen = INT_MAX;
        int cnt = 0;
        int start = 0;
        string ans = "";
        while(j < m) {
            ms[s[j]]++;
            if(mt.count(s[j]) && ms[s[j]] == mt[s[j]]) cnt++;
            while(cnt == mt.size()) {
                if(j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }
                char left = s[i];
                ms[left]--;
                if(mt.count(left) && ms[left] < mt[left]) cnt--;
                i++;
            }
            j++;
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};