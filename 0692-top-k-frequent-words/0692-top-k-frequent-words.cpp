class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mpp;
        for(auto word : words) {
            mpp[word]++;
        }
        vector<pair<int, string>> temp;
        for(auto it : mpp) {
            temp.push_back({it.second, it.first});
        }
        auto lambda = [&](pair<int, string>& p1, pair<int, string>& p2) {
            if (p1.first != p2.first)
                return p1.first < p2.first;

            return p1.second > p2.second;
        };
        sort(begin(temp), end(temp), lambda);
        int n = size(temp);
        vector<string> ans;
        for(int i = n - 1; i >= n - k; i--) {
            ans.push_back(temp[i].second);
        }
        
        return ans;
    }
};