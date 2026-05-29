class Solution {
public:
    struct TrieNode {
        TrieNode* children[26];
        int cnt;
    };

    TrieNode* getNode() {
        TrieNode* newNode = new TrieNode();
        
        for(int i = 0; i < 26; i++) newNode -> children[i] = NULL;
        newNode -> cnt = 0;
        return newNode;
    }
    void insert(string s, TrieNode* root) {
        TrieNode* crawl = root;
        for(char c : s) {
            int i = c - 'a';
            if(crawl -> children[i] == NULL) {
                crawl -> children[i] = getNode();   
            }
            crawl -> children[i] -> cnt = crawl -> children[i] -> cnt + 1;
            crawl = crawl -> children[i];
        }
    }
    int getScore(string s, TrieNode* root) {
        TrieNode* crawl = root;
        int score = 0;
        for(char c : s) {
            int i = c - 'a';
            if(crawl -> children[i] == NULL) break;
            else {
                score += crawl -> children[i] -> cnt;
            }
            crawl = crawl -> children[i];
        }
        return score;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = getNode();
        for(string s : words) {
            insert(s, root);
        }
        vector<int> ans;
        for(string s : words) {
            ans.push_back(getScore(s, root));
        }
        return ans;
    }
};