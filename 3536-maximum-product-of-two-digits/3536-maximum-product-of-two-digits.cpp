class Solution {
public:
    int maxProduct(int n) {
        string num = to_string(n);
        int s = num.size();
        int maxi = 0;
        for(int i = 0; i < s; i++) {
            for(int j = i + 1; j < s; j++) {
                maxi = max(maxi, (num[i] - '0')*(num[j] - '0'));
            }
        }
        return maxi;
    }
};