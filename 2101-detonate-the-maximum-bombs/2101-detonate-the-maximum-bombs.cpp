class Solution {
public:
    int bfsUtil(int src, unordered_map<int, vector<int>>& adj) {
        queue<int> q;
        unordered_set<int> st;
        q.push(src);
        st.insert(src);
        int cnt = 0;
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            cnt += 1;
            for(auto neigh : adj[node]) {
                if(st.find(neigh) == st.end()) {
                    st.insert(neigh);
                    q.push(neigh);
                }
            }
        }
        return cnt;

    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i < n; i++) {
            int x1 = bombs[i][0], y1 = bombs[i][1], r = bombs[i][2];
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                int x2 = bombs[j][0], y2 = bombs[j][1];
                long long dx = x1 - x2;
                long long dy = y1 - y2;
                long long distSq = dx * dx + dy * dy;
                long long rSq = 1LL * r * r;

                if(distSq <= rSq) adj[i].push_back(j);
            }
        }
        int maxi = 1;
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, bfsUtil(i, adj));
        }
        return maxi;
    }
};