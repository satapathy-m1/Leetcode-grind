class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int j = n - 1;
        vector<int> rightSideMatcgLen(m + 1, 0);
        
        for(int i = m - 1; i >= 0; i--) {
            rightSideMatcgLen[i] = rightSideMatcgLen[i + 1];
            if(j >= 0 && word1[i] == word2[j]) {
                rightSideMatcgLen[i]++;
                j--;
            }
        }
        j = 0;
        int i = 0;
        vector<int> ans;
        bool power = true;
        while(i < m && j < n) {
            if(word1[i] == word2[j]) {
                ans.push_back(i);
                i++;
                j++;
            }
            else {
                if(power && n - (j + 1) <= rightSideMatcgLen[i + 1]) {
                    power = false;
                    ans.push_back(i);
                    i++;
                    j++;
                }
                else i++;
            }
        }
        if (j == n)
            return ans;

        return {};
    }
};