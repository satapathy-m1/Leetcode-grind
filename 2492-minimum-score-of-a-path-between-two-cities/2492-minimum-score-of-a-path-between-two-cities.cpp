class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, long long>>> adj(n + 1);
        for(auto road : roads) {
            int u = road[0], v = road[1], d = road[2];
            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({1e18, 1}); //sofar dist, node
        vector<long long> dist(n + 1, 1e18);
        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if(d != dist[u]) continue;
            for(auto [v, d_v] : adj[u]) {
                long long new_d = min(d, d_v);
                if(new_d < dist[v]) {
                    pq.push({new_d, v});
                    dist[v] = new_d;
                }
            }
        }
        return dist[n];
    }
};