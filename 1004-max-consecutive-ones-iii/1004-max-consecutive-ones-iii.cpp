class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        int maxi = 0;
        int zerosCnt = 0;
        while(j < n) {
            if(nums[j] == 1) {
                j++;
            }
            else {
                zerosCnt++;
                while(zerosCnt > k) {
                    maxi = max(maxi, j - i);
                    if(nums[i] == 0) zerosCnt--;
                    i++;
                }
                j++;
            }
        }
        maxi = max(maxi, j - i);
        return maxi;
    }
};