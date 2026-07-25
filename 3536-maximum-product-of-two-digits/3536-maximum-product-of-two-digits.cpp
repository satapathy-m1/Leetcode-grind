class Solution {
public:
    int maxProduct(int n) {
        string num = to_string(n);
        sort(begin(num), end(num));
        int s = num.size();
        int a = num[s - 1] - '0';
        int b = num[s - 2] - '0';
        int maxi = (a) * (b);
        return maxi;
    }
};