class Solution {
private:
    int noOfNodes, noOfEdges;
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[u] = true;
        noOfNodes++;
        noOfEdges += adj[u].size();
        for(int v : adj[u]) {
            if(!vis[v]) {
                dfs(v, adj, vis);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        noOfNodes = 0;
        noOfEdges = 0;
        vector<vector<int>> adj(n);
        for(auto edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n, false);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, adj, vis);
                noOfEdges /= 2; 
                if (noOfEdges == noOfNodes * (noOfNodes - 1) / 2)
                    cnt++;
                noOfNodes = 0;
                noOfEdges = 0;
            }
        }
        return cnt;
    }
};