class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr = 0;
        for(int i : nums) xorr ^= i;
        int setBit = -1;
        for(int i = 0; i < 32; i++) {
            if((xorr & (1 << i)) != 0) {
                setBit = i;
                break;
            }
        }
        if(setBit == -1) {
            return {-1, -1};
        }
        int f = 0, s = 0;
        for(int i : nums) {
            if((i & (1 << setBit)) != 0) f ^= i;
            else s ^= i;
        }
        return {f, s};
    }
};