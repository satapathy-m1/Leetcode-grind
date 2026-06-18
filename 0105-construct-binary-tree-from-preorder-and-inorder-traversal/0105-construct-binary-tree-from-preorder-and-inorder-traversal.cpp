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
int n;
    TreeNode* buildBT(int &idx, int left, int right, vector<int>& preorder, vector<int>& inorder) {
        if(left > right) return NULL;

        TreeNode* root = new TreeNode(preorder[idx]);

        int findInIdx = -1;
        for(int i = left; i <= right ; i++) {
            if(inorder[i] == preorder[idx]) {
                findInIdx = i;
                break;
            }
        }
        idx++;
        root -> left = buildBT(idx, left, findInIdx - 1, preorder, inorder);
        root -> right = buildBT(idx, findInIdx + 1, right, preorder, inorder);

        return root;
    } 
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n = preorder.size();
        int idx = 0;
        return buildBT(idx, 0, n - 1, preorder, inorder);
    }
};