class Solution {
public:
    typedef pair<long double, pair<int, int>> pp;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        for(auto point : points) {
            long double d = sqrt(pow(abs(point[0]), 2) + pow(abs(point[1]), 2));
            pq.push({d, {point[0], point[1]}});
        }
        vector<vector<int>> ans;
        while(k--) {
            auto [d, p] = pq.top();
            pq.pop();
            auto [a, b] = p;
            ans.push_back({a, b});
        }
        return ans;
    }
};