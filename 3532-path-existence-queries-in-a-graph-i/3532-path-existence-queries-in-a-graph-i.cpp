class Solution {
private:
    vector<int> par;
    void unionFunc(int x, int y, vector<int>& nums, int maxDiff) {
        if(par[x] == par[y]) return;
        if(abs(nums[x] - nums[y]) <= maxDiff) {
            par[y] = par[x];
        }
        return;
    }
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        par.resize(n);
        for(int i = 0; i < n; i++) par[i] = i;
        for(int i = 0; i < n - 1; i++) {
            unionFunc(i, i + 1, nums, maxDiff);
        }
        vector<bool> ans;
        for(auto query : queries) {
            int u = query[0], v = query[1];
            if(par[u] == par[v]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};