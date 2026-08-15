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
    int maxi;
    vector<int> f(TreeNode* root) {
        if(!root) {
            return {INT_MAX, INT_MIN, 0, 1};
        }
        vector<int> left = f(root -> left);
        vector<int> right = f(root -> right);
        if(left[3] == 1 && right[3] == 1 && root -> val > left[1] && root -> val < right[0]) {
            int sum = root -> val + left[2] + right[2];
            maxi = max(sum, maxi);
            int value = root -> val;
            return {min(left[0], value), max(right[1], value), sum, 1};
        }
        else return {INT_MAX, INT_MIN, 0, 0};

    }
public:
    int maxSumBST(TreeNode* root) {
        if(!root) return 0;
        maxi = 0;
        vector<int> vec =  f(root);
        return maxi;
    }
};