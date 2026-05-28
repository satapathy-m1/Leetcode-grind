class Solution {
public:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m, n;
    vector<string> result;
    struct TrieNode {
        bool endOfWord;
        string word;
        TrieNode* children[26];
    };

    TrieNode* getNode() {
        TrieNode* newNode = new TrieNode();
        newNode -> endOfWord = false;
        newNode -> word = "";
        for(int i = 0; i < 26; i++) {
            newNode -> children[i] = NULL;
        }
        return newNode;
    }
    void insert(TrieNode* root, string& word) {
        TrieNode* crawler = root;
        for(int i = 0; i < word.length(); i++) {
            char c = word[i];
            if(crawler -> children[c - 'a'] == NULL) {
                crawler -> children[c - 'a'] = getNode();
            }
            crawler = crawler -> children[c - 'a'];
        }
        crawler -> endOfWord = true;
        crawler -> word = word;
    }
    void findTrieWords(vector<vector<char>>& board, int i, int j, TrieNode* root) {
        if(i < 0 || i >= m || j < 0 || j >= n) return;
        if(board[i][j] == '$' || root -> children[board[i][j] - 'a'] == NULL) return;
        root = root -> children[board[i][j] - 'a'];
        if(root -> endOfWord == true) {
            result.push_back(root -> word);
            root -> endOfWord = false;
        }
        char c = board[i][j];
        board[i][j] = '$';
        for(auto [di, dj]: directions) {
            int ni = i + di;
            int nj = j + dj;
            findTrieWords(board, ni, nj, root);
        }
        board[i][j] = c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        TrieNode* root = getNode();
        for(string& s: words) {
            insert(root, s);
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                char c = board[i][j];
                if(root -> children[c - 'a'] != NULL) {
                    findTrieWords(board, i, j, root);
                }
            }
        }
        return result;
    }
};