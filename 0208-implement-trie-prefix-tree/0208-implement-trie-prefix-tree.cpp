class Trie {
public:
    struct TrieNode {
        bool isEndOfWord;
        TrieNode* children[26];
    };
    TrieNode* root;
    TrieNode* getNode() {
        TrieNode* newNode = new TrieNode();
        newNode -> isEndOfWord = false;
        for(int i = 0; i < 26; i++) {
            newNode -> children[i] = NULL;
        }
        return newNode;
    }
    Trie() {
       root = getNode();
    }
    
    void insert(string word) {
        TrieNode* crawler = root;
        for(char c : word) {
            if(crawler -> children[c - 'a'] == NULL) {
                crawler -> children[c - 'a'] = getNode();
            }
            crawler = crawler -> children[c - 'a'];
        }
        crawler -> isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* crawler = root;
        for(char c : word) {
            if(crawler -> children[c - 'a'] == NULL) {
                return false;
            }
            crawler = crawler -> children[c - 'a'];
        }
        return crawler -> isEndOfWord == true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* crawler = root;
        for(char c : prefix) {
            if(crawler -> children[c - 'a'] == NULL) {
                return false;
            }
            crawler = crawler -> children[c - 'a'];
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