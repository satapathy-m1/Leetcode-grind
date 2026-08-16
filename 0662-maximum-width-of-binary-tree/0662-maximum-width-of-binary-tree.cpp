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
typedef unsigned long long ll;

    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, ll>> q;
        ll maxWidth = 0;
        q.push({root, 0ll});
        while(!q.empty()) {
            ll first = q.front().second;
            ll last  =  q.back().second;
            maxWidth = max(maxWidth, last - first + 1);
            int s = q.size();
            ll low = INT_MAX, high = INT_MIN;
            while(s--) {
                auto [node, i] = q.front();
                q.pop();
                if(node -> left) q.push({node -> left, 2 * i + 1});
                if(node -> right) q.push({node -> right, 2 * i + 2});
            }
            
        }
        return (int)maxWidth;
    }
};