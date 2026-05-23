class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int noOfRotations = 0;
        int i = 0;
        while(i < n-1){
            if(nums[i] > nums[i + 1]) noOfRotations++;

            i++;
        }
        if(nums[0] < nums[n - 1]) noOfRotations++;

        return noOfRotations <= 1;
    }
};