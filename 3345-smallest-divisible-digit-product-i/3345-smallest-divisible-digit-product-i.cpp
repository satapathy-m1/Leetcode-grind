class Solution {
private:
    int prodDigits(int n) {
        int prod = 1;
        while(n) {
            prod *= (n % 10);
            n /= 10;
        }
        return prod;
    }
public:
    int smallestNumber(int n, int t) {
        while(1) {
            if(prodDigits(n)%t == 0) return n;
            n++;
        }
        return -1;
    }
};