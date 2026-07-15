class Solution {
private:
    int findSum(int n, bool isEven) {
        int start = 1 + isEven;
        int sum = start;
        n = n - 1;
        while(n--) {
            start = start + 2;
            sum += start;
        }
        return sum;
    }
public:
    int gcdOfOddEvenSums(int n) {
        int sum1 = findSum(n, false);
        int sum2 = findSum(n, true);
        return gcd(sum1, sum2);
    }
};