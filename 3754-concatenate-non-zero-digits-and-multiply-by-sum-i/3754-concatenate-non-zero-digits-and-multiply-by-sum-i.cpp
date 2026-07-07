class Solution {
public:
    long long sumAndMultiply(int n) {
        long long runningNum = 0;
        long long runningSum = 0;
        while(n) {
            int d = n % 10;
            if(d != 0) runningNum = runningNum * 10 + d;
            runningSum += d;
            n /= 10;
        }
        if(runningNum == 0) return 1ll*runningSum;
        long long reversedNum = 0;
        while(runningNum) {
            int d = runningNum % 10;
            reversedNum = reversedNum*10 + d;
            runningNum /= 10;
        }
        return 1ll*reversedNum*runningSum;
    }
};