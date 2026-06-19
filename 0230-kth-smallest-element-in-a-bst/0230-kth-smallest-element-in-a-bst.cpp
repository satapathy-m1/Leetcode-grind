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
private:
    int k, ans;
    void helper(TreeNode* root) {
        if(!root) return;
        helper(root -> left);
        k--;
        if(k == 0) ans = root -> val;
        helper(root -> right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        this -> k = k;
        helper(root);
        return ans;
    }
};