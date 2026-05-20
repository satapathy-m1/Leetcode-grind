class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_map<int, int> freq;
        vector<int> ans(n);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            int a = A[i], b = B[i];
            freq[a]++;
            if(freq[a] == 2) cnt++;
            freq[b]++;
            if(freq[b] == 2) cnt++;
            ans[i] = cnt;
        }
        return ans;
    }
};