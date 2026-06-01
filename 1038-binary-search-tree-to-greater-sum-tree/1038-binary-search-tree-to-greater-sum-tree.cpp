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
    int sum;
    void postOrder(TreeNode* root) {
        if(!root) return;
        postOrder(root -> right);
        sum += root -> val;
        root -> val = sum;
        postOrder(root -> left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(!root) return NULL;
        sum = 0;
        postOrder(root);
        return root;
    }
};