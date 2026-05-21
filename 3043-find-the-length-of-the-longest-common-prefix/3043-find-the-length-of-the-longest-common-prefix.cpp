class Solution {
public:
    void putAllPrefixIntoSet(int num, unordered_set<int>& st) {
        while(num) {
            st.insert(num);
            num /= 10;
        }
    }
    int checkLength(int num) {
        int cnt = 0;
        while(num) {
            cnt++;
            num /= 10;
        }
        return cnt;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        unordered_set<int> st;
        for(int i = 0; i < n; i++) {
            int num = arr1[i];
            putAllPrefixIntoSet(num, st);
        }
        int maxi = 0;
        for(int i = 0; i < m; i++) {
            int num = arr2[i];
            while(num) {
                if(st.count(num)) {
                    maxi = max(maxi, checkLength(num));
                    break;
                }
                num /= 10;
            }
        }
        return maxi;
    }
};