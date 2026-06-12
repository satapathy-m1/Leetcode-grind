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
    void buildMap(TreeNode* root, int curr_x, int curr_lvl, map<int, vector<pair<int, int>>>& mpp) {
        if(!root) return;
        mpp[curr_x].push_back({curr_lvl, root -> val});
        buildMap(root -> left, curr_x - 1, curr_lvl + 1, mpp);
        buildMap(root -> right, curr_x + 1, curr_lvl + 1, mpp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root -> left && !root -> right) return {{root -> val}};
        map<int, vector<pair<int, int>>> mpp;
        buildMap(root, 0, 0, mpp);
        vector<vector<int>> ans;
        for(auto it : mpp) {
            auto vec = it.second;
            sort(begin(vec), end(vec));
            vector<int> t;
            for(auto [lvl, i] : vec) {
                t.push_back(i);
            }
            ans.push_back(t);
        }
        return ans;
    }
};