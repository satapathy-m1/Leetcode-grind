class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, long long>>> adj(n + 1);
        for(auto road : roads) {
            int u = road[0], v = road[1], d = road[2];
            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }
        long long minWeight =  1e18;
        queue<int> q;
        vector<bool> vis(n + 1, 0);
        q.push(1);
        vis[1] = true;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto [v, d_v] : adj[u]) {
                minWeight = min(minWeight, d_v);
                if(!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
        return minWeight;
    }
};