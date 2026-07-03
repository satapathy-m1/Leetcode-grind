class Solution {
private:
    bool isPossible(long long mid,  vector<vector<int>>& edges, vector<bool>& online, vector<int>& topo, vector<vector<pair<int, int>>>& adj, long long k) {
        
        const long long INF = LLONG_MAX / 4;
        int n = online.size();
        vector<long long> dist(n, INF);
        dist[0] = 0;
        for(int u : topo) {
            if(dist[u] == INF) continue;
            if (u != 0 && u != n - 1 && !online[u]) continue;
            for(auto [v, c] : adj[u]) {
                if (c < mid) continue;
                if (v != n - 1 && !online[v]) continue;
                dist[v] = min(dist[v], dist[u] + c);
            }
        }
        return dist[n - 1] <= k;
    }
    int getMax(vector<vector<int>>& edges) {
        int maxi = -1;
        for(auto e : edges) {
            maxi = max(maxi, e[2]);
        }
        return maxi;
    }
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<int> indeg(n, 0);
        vector<vector<pair<int, int>>> adj(n);
        for(auto e : edges) {
            int u = e[0], v = e[1], cost = e[2];
            indeg[v]++;
            adj[u].push_back({v, cost});
        }
        vector<int> topo;
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indeg[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            int node = q.front();
            topo.push_back(node);
            q.pop();
            for(auto [v, c] : adj[node]) {
                indeg[v]--;
                if(indeg[v] == 0) {
                    q.push(v);
                }
            }
        }
        int low = 0, high = getMax(edges);
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isPossible(mid, edges, online, topo, adj, k)) {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};