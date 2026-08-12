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
    int solve(TreeNode* root, int &sum) {
        if(!root) return 0;

        int leftSum = max(0, solve(root -> left, sum));
        int rightSum = max(0, solve(root -> right, sum));

        sum = max({sum, root -> val + leftSum + rightSum});

        return root -> val + max(leftSum, rightSum);
    }
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int sum = INT_MIN;
        int twerk = solve(root, sum);
        return sum;
    }
};