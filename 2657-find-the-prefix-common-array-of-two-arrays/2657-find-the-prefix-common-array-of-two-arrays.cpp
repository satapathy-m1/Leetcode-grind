class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_map<int, int> freq;
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            int a = A[i], b = B[i];
            freq[a]++;
            freq[b]++;
            int cnt = 0;
            for(auto it : freq) {
                if(it.second == 2) cnt++;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};