class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> st(begin(banned), end(banned));
        unordered_map<string, int> mpp;
        string temp = "";
        for(char c : paragraph) {
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) temp += tolower(c);
            else {
                if(!temp.empty()) {
                    mpp[temp]++;
                    temp = "";
                }
            }
        }
        if (!temp.empty()) {
            mpp[temp]++;
        }
        int maxF = 0;
        string ans = "";
        for(auto it : mpp) {
            if(it.second > maxF && !st.count(it.first)) {
                maxF = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};