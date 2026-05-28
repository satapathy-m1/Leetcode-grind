class Solution {
public:
    struct TrieNode {
        int idx;
        int children[26];

        TrieNode() {
            idx = -1;
            for(int i = 0; i < 26; i++) {
                children[i] = -1;
            }
        }
    };

    vector<TrieNode> trie;

    bool isBetter(int currIdx, int newIdx, vector<string>& wordsContainer) {
        if(currIdx == -1) return true;
        int currLen = wordsContainer[currIdx].length();
        int newLen = wordsContainer[newIdx].length();
        if(newLen < currLen) return true;
        if(newLen == currLen && newIdx < currIdx) return true;
        return false;
    }

    void insert(vector<string>& wordsContainer) {
        for(int i = 0; i < wordsContainer.size(); i++) {
            string& word = wordsContainer[i];
            int crawler = 0;

            if(isBetter(trie[0].idx, i, wordsContainer)) {
                trie[0].idx = i;
            }

            for(int j = word.length() - 1; j >= 0; j--) {
                int c = word[j] - 'a';
                if(trie[crawler].children[c] == -1) {
                    trie[crawler].children[c] = trie.size();
                    trie.push_back(TrieNode());
                }
                crawler = trie[crawler].children[c];
                if(isBetter(trie[crawler].idx, i, wordsContainer)) {
                    trie[crawler].idx = i;
                }
            }
        }
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        trie.push_back(TrieNode());
        insert(wordsContainer);
        vector<int> result;

        for(string& word : wordsQuery) {
            int crawler = 0;
            int ans = trie[0].idx;

            for(int j = word.length() - 1; j >= 0; j--) {
                int c = word[j] - 'a';

                if(trie[crawler].children[c] == -1) {
                    break;
                }

                crawler = trie[crawler].children[c];
                ans = trie[crawler].idx;
            }

            result.push_back(ans);
        }
        return result;
    }
};