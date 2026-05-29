class Solution {
public:
    struct TrieNode {
        bool endOfNum;
        string num;
        TrieNode* children[10];
    };

    TrieNode* getNode() {
        TrieNode* newNode = new TrieNode();

        newNode -> endOfNum = false;
        newNode -> num = "";
        for(int i = 0; i < 10; i++) newNode -> children[i] = NULL;

        return newNode;
    }

    void insert(TrieNode* root, string num) {
        TrieNode* pCrawl = root;
        for(char c : num) {
            int i = c - '0';
            if(pCrawl -> children[i] == NULL) {
                pCrawl -> children[i] = getNode();
            } 
            pCrawl = pCrawl -> children[i];
        }
        pCrawl -> endOfNum = true;
        pCrawl -> num = num;
    }

    int getLenOfPrefix(TrieNode* root, string num) {
        TrieNode* pCrawl = root;
        int len = 0;
        for(char c : num) {
            int i = c - '0';
            if(pCrawl -> children[i] == NULL) break;
            pCrawl = pCrawl -> children[i];
            len++;
        }
        return len;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root = getNode();
        for(int i : arr2) {
            string num = to_string(i);
            insert(root, num);
        }
        int maxi = 0;
        for(int i : arr1) {
            string num = to_string(i);
            maxi = max(maxi, getLenOfPrefix(root, num));
        }
        return maxi;
    }
};