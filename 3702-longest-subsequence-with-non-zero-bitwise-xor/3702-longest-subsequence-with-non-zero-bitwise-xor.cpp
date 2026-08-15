class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xorr = 0;

        int z = 0;
        for(int i : nums) {
            xorr ^= i;
            if(i == 0) z++;
        }
        if(z == n) return 0;
        else if(xorr) return n;
        return n - 1;
    }
};