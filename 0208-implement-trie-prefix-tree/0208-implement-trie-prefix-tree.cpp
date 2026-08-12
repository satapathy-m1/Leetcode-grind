class Trie {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool endOfWord;
    };
    TrieNode* getNode() {
        TrieNode* root = new TrieNode();
        root -> endOfWord = false;
        for(int i = 0; i < 26; i++) root -> children[i] = NULL;
        return root;
    }
    TrieNode* root;
public:
    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        TrieNode* crawler = root;
        for(char c : word) {
            int i = c - 'a';
            if(crawler -> children[i] == NULL) {
                crawler -> children[i] = getNode();
            }
            crawler = crawler -> children[i];
        }
        crawler -> endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* crawler = root;
        for(char c : word) {
            int i = c - 'a';
            if(crawler -> children[i] == NULL) {
                return false;
            }
            crawler = crawler -> children[i];
        }
        return crawler -> endOfWord == true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* crawler = root;
        for(char c : prefix) {
            int i = c - 'a';
            if(crawler -> children[i] == NULL) {
                return false;
            }
            crawler = crawler -> children[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */