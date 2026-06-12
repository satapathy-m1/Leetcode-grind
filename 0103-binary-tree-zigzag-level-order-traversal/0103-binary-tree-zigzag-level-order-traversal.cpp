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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        vector<vector<int>> ans;
        while(!q.empty()) {
            int s = q.size();
            vector<int> levelVec;
            while(s--) {
                TreeNode* currNode = q.front();
                q.pop();
                levelVec.push_back(currNode -> val);
                if(currNode -> left) q.push(currNode -> left);
                if(currNode -> right) q.push(currNode -> right);
            }
            if(flag) {
                reverse(begin(levelVec), end(levelVec));
            }
            ans.push_back(levelVec);
            flag = !flag;
        }
        return ans;
    }
};