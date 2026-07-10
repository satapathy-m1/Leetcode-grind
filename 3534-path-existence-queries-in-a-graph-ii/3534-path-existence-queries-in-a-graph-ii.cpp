class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        
        int m = vals.size();
        
        vector<int> compId(m, 0);
        for (int i = 1; i < m; i++) {
            if (vals[i] - vals[i-1] <= maxDiff) {
                compId[i] = compId[i-1];
            } else {
                compId[i] = compId[i-1] + 1;
            }
        }
        
        int LOG = 20;
        vector<vector<int>> up(m, vector<int>(LOG, 0));
        
        for (int i = 0; i < m; i++) {
            int nxtVal = vals[i] + maxDiff;
            int nxtIdx = upper_bound(vals.begin(), vals.end(), nxtVal) - vals.begin() - 1;
            up[i][0] = nxtIdx;
        }
        
        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < m; i++) {
                up[i][k] = up[up[i][k-1]][k-1];
            }
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            int u = q[0];
            int v = q[1];
            
            if (u == v) {
                ans.push_back(0);
                continue;
            }
            
            int val_u = nums[u];
            int val_v = nums[v];
            
            if (val_u == val_v) {
                ans.push_back(1);
                continue;
            }
            
            if (val_u > val_v) {
                swap(val_u, val_v);
            }
            
            int i = lower_bound(vals.begin(), vals.end(), val_u) - vals.begin();
            int j = lower_bound(vals.begin(), vals.end(), val_v) - vals.begin();
            
            if (compId[i] != compId[j]) {
                ans.push_back(-1);
                continue;
            }
            
            int jumps = 0;
            for (int k = LOG - 1; k >= 0; k--) {
                if (up[i][k] < j) {
                    i = up[i][k];
                    jumps += (1 << k);
                }
            }
            
            ans.push_back(jumps + 1);
        }
        
        return ans;
    }
};