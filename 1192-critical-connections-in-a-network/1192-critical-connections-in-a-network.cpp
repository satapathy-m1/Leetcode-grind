class Solution {
public:
    int time = 1;
    void dfs(int node, int parent, vector<int> adj[], vector<bool>& vis, int tin[], int low[]
    , vector<vector<int>>& bridges) {
        vis[node] = true;
        tin[node] = low[node] = time;
        time++;
        for(auto it : adj[node]) {
            if(it == parent) continue;
            else if(vis[it] == false) {
                dfs(it, node, adj, vis, tin, low, bridges);
                low[node] = min(low[node], low[it]);
                if(low[it] > tin[node]) {
                    bridges.push_back({node, it});
                }
            }
            else {
                low[node] = min(low[node], low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto vec : connections) {
            int u = vec[0], v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int low[n];
        int tin[n];
        vector<bool> vis(n, false);
        vector<vector<int>> bridges;
        dfs(0, -1, adj, vis, tin, low, bridges);
        return bridges;
    }
};