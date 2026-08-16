/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> mpp;
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()) {
            int s = q.size();
            while(s--) {
                auto [node, other] = q.front();
                q.pop();
                auto [x_ax, lvl] = other;
                mpp[x_ax].push_back({lvl, node -> val});
                if(node -> left) q.push({node -> left, {x_ax - 1, lvl + 1}});
                if(node -> right) q.push({node -> right, {x_ax + 1, lvl + 1}});
            }
        }
        for(auto &it : mpp) {
            int x_ax = it.first;
            auto vec = it.second;
            sort(begin(vec), end(vec));
            vector<int> cur;
            for(auto [lvl, el] : vec) cur.push_back(el);
            ans.push_back(cur);
        }
        return ans;
    }
};