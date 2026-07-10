class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        priority_queue<pair<long long, pair<int, int>>> pq;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                long long sum = nums1[i] + nums2[j];
                if(pq.size() < k) {
                    pq.push({sum, {i, j}});
                }
                else if(pq.top().first > sum) {
                    pq.pop();
                    pq.push({sum, {i, j}});
                }
                else break;
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()) {
            auto [s, c] = pq.top();
            pq.pop();
            int i = c.first, j = c.second;
            ans.push_back({nums1[i], nums2[j]});
        }
        return ans;
    }
};