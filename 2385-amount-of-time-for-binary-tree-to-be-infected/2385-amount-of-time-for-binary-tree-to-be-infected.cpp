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
    void buildAdj(TreeNode* root, unordered_map<int, vector<int>>& adj) {
        if(!root) return;
        if(root -> left) {
            adj[root -> val].push_back(root -> left -> val);
            adj[root -> left -> val].push_back(root -> val);
        }
        if(root -> right) {
            adj[root -> val].push_back(root -> right -> val);
            adj[root -> right -> val].push_back(root -> val);
        }
        buildAdj(root -> left, adj);
        buildAdj(root -> right, adj);
        return;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        buildAdj(root, adj);
        queue<int> q;
        unordered_set<int> st;
        q.push(start);
        st.insert(start);
        int time = -1;
        while(!q.empty()) {
            int s = q.size();
            while(s--) {
                int node = q.front();
                q.pop();
                for(int adjNode : adj[node]) {
                    if(!st.count(adjNode)) {
                        q.push(adjNode);
                        st.insert(adjNode);
                    }
                }
            }
            time++;
        }
        return time;
    }
};