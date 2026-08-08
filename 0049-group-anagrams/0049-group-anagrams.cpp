class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        for(string s : strs) {
            string temp = s;
            sort(begin(temp), end(temp));
            mpp[temp].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto it : mpp) {
            auto vec = it.second;
            sort(begin(vec), end(vec));
            ans.push_back(vec);
        }
        return ans;
    }
};