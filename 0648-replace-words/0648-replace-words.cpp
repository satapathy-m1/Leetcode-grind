class Solution {
public:
    struct TrieNode {
        bool endOfWord;
        string word;
        TrieNode* children[26];
    };
    TrieNode* getNode() {
        TrieNode* newNode = new TrieNode();

        newNode -> endOfWord = false;
        newNode -> word = "";
        for(int i = 0; i < 26; i++) newNode -> children[i] = NULL;

        return newNode;
    }

    void insert(string word, TrieNode* root) {
        TrieNode* pCrawl = root;
        for(char c : word) {
            int i = c - 'a';
            if(pCrawl -> children[i] == NULL) {
                pCrawl -> children[i] = getNode();
            }
            pCrawl = pCrawl -> children[i];
        }
        pCrawl -> endOfWord = true;
        pCrawl -> word = word;
    }

    string getRootWord(string word, TrieNode* root) {
        TrieNode* pCrawl = root;
        for(char c : word) {
            int i = c - 'a';
            if(pCrawl -> children[i] == NULL) {
                return word;
            }
            pCrawl = pCrawl -> children[i];
            if(pCrawl -> endOfWord == true) return pCrawl -> word;
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<string> vec;
        string temp = "";
        for(char c : sentence) {
            if(c != ' ') temp += string(1, c);
            else {
                vec.push_back(temp);
                temp = "";
            }
        }
        vec.push_back(temp);
        
        TrieNode* root = getNode();
        for(string word : dictionary) {
            insert(word, root);
        }
        for(int i = 0; i < vec.size(); i++) {
            string word = vec[i];
            vec[i] = getRootWord(word, root);
        }
        string ans = "";
        for(string s : vec) {
            ans += s;
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};