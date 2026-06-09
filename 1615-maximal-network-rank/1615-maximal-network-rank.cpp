class Solution {
public:
    int networkRank(int u, int v, unordered_map<int, vector<int>>& adj) {
        int cnt = adj[u].size() + adj[v].size();
        bool flag = 0;
        for(auto j : adj[u]) if(j == v) flag = 1;
        return flag == 1 ? cnt - 1 : cnt;
    }
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<int>> adj;
        for(auto road : roads) {
            int u = road[0], v = road[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                maxi = max(maxi, networkRank(i, j, adj));
            }
        }
        return maxi;
    }
};