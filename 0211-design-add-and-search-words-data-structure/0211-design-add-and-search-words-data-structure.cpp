class WordDictionary {
private:
    struct TrieNode {
        bool endOfWord;
        TrieNode* children[26];
    };
    TrieNode* getNode() {
        TrieNode* node = new TrieNode();
        node -> endOfWord = false;
        for(int i = 0; i < 26; i++) node -> children[i] = NULL;
        return node;
    }
    void add(TrieNode* root, string s) {
        TrieNode* crawler = root;
        for(char c : s) {
            if(crawler -> children[c - 'a'] == NULL) {
                crawler -> children[c - 'a'] = getNode();
            }
            crawler = crawler -> children[c - 'a'];
        }
        crawler -> endOfWord = true;
    }
    bool searchWord(TrieNode* root, string s, int pos) {
        if(root == NULL) return false;
        if(pos == s.length()) return root -> endOfWord;
        if(s[pos] == '.') {
            for(int i = 0; i < 26; i++) {
                if(root -> children[i] && searchWord(root -> children[i], s, pos + 1)) return true;
            }
            return false;
        }
        else {
            if(root -> children[s[pos] - 'a'] == NULL) return false;
            return searchWord(root -> children[s[pos] - 'a'], s, pos + 1);
        }
    }
public:
    TrieNode *root;
    WordDictionary() {
        root = getNode();
    }
    
    void addWord(string word) {
        add(root, word);
    }
    
    bool search(string word) {
        return searchWord(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */