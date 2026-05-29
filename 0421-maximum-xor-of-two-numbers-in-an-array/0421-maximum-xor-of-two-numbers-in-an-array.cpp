class Solution {
public:
    struct TrieNode {
        TrieNode* left;
        TrieNode* right;
        int num;
    };
    TrieNode* getNode() {
        TrieNode* newNode = new TrieNode();
        newNode -> left = NULL;
        newNode -> right = NULL;
        newNode -> num = -1;

        return newNode;
    }
    void insert(int num, TrieNode* root) {
        TrieNode* pCrawl = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(bit == 0) {
                if(pCrawl -> left == NULL) {
                    pCrawl -> left = getNode();
                }
                pCrawl = pCrawl -> left;
            }
            else {
                if(pCrawl -> right == NULL) {
                    pCrawl -> right = getNode();
                }
                pCrawl = pCrawl -> right;
            }
        }
        pCrawl -> num = num;
    }
    int findBestOption(int num, TrieNode* root) {
        TrieNode* pCrawl = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int bitNeeded = !bit;
            if(bitNeeded == 0) {
                if(pCrawl -> left != NULL) {
                    pCrawl = pCrawl -> left;
                }
                else pCrawl = pCrawl -> right;
            }
            else {
                if(pCrawl -> right != NULL) {
                    pCrawl = pCrawl -> right;
                }
                else pCrawl = pCrawl -> left;
            }
        }
        return pCrawl -> num;
    }
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        TrieNode* root = getNode();
        for(int i : nums) {
            insert(i, root);
        }
        int maxi = 0;
        for(int i : nums) {
            maxi = max(maxi, i ^ findBestOption(i, root));
        }
        return maxi;
    }
};