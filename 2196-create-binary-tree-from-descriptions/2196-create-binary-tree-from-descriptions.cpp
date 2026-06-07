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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode* root = NULL;
        unordered_set<int> st;
        unordered_map<int, vector<pair<int, int>>> mpp; //map of parent to both its children / one of its child
        for(auto vec : descriptions) {
            st.insert(vec[1]);
            mpp[vec[0]].push_back({vec[1], vec[2]});
        }
        for(auto vec : descriptions) {
            if(!st.count(vec[0])) {
                root = new TreeNode(vec[0]);
                break;
            }
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();
            for(auto child : mpp[currNode -> val]) {
                int val = child.first;
                int isLeftChild = child.second;
                TreeNode* childNode = new TreeNode(val);
                if(isLeftChild == 1) currNode -> left = childNode;
                else currNode -> right = childNode;
                q.push(childNode);
            }
        }
        return root;
    }
};