class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n == 1) return s;
        if(n%2 == 1) n = n - 1;
        long long a = (1ll*m * n) / 2;
        long long b = (n - 1) / 2;
        return 1ll*(a - b + s);
    }
};