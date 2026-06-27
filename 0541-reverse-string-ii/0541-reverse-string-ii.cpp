class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        int len = 2*k;
        int j = 0, i = 0;
        while(j < n) {
            if(j - i + 1 < len) {
                j++;
            }
            else {
                int K = min(i + k - 1, n - 1);
                int ii = i;
                while(ii < K) {
                    swap(s[ii++], s[K--]);
                }
                j++;
                i=j;
            }
        }

        if(j - i + 1 < k) reverse(begin(s) + i, end(s));
        else {

            int K = min(i + k - 1, n - 1);
            int ii = i;
            while(ii < K) {
                swap(s[ii++], s[K--]);
            }
        }
        return s;
    }
};