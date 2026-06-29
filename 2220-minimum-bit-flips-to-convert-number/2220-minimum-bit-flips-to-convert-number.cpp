class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        for(int i = 0; i < 32; i++) {
            if((start & (1 << i)) != 0 && (goal & (1 << i)) != 0) {

            }
            else if(((start & (1 << i)) != 0 && (goal & (1 << i)) == 0) || ((start & (1 << i)) == 0 && (goal & (1 << i)) != 0)) {
                cnt++;
            }
        }
        return cnt;
    }
};