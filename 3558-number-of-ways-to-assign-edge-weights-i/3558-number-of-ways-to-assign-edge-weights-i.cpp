class Solution {
public:
    int max_depth;
    int max_depth_ele;
    const int MOD = 1e9 + 7;

    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
    void dfs(int node, int curr_depth, unordered_map<int, vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        if(curr_depth > max_depth) {
            max_depth = curr_depth;
            max_depth_ele = node;
        } 
        for(auto neighbourNode : adj[node]) {
            if(!visited[neighbourNode]) {
                dfs(neighbourNode, curr_depth + 1, adj, visited);
            }
        }
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int n = edges.size();
        vector<bool> visited(n + 2, false);
        dfs(1, 0, adj, visited);

        return modPow(2, max_depth - 1, MOD);
    }
};