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
    class Info {
        public:
            int maxi;
            int mini;
            bool isBST;
            long long sum;
    };
    Info solve(TreeNode* root, long long &ans) {
        if(!root) return {INT_MIN, INT_MAX, true, 0};
        Info left = solve(root -> left, ans);
        Info right = solve(root -> right, ans);

        Info currNode;
        currNode.maxi = max(root -> val, right.maxi);
        currNode.mini = min(root -> val, left.mini);
        currNode.sum = left.sum + right.sum + root -> val;
        if(left.isBST && right.isBST && (root -> val > left.maxi && root -> val < right.mini)) {
            currNode.isBST = true;
        }
        else currNode.isBST = false;
        if(currNode.isBST) ans = max(ans, currNode.sum);
        return currNode;
    }

public:
    int maxSumBST(TreeNode* root) {
        long long ans = 0;
        Info node = solve(root, ans);
        return ans;
    }
};