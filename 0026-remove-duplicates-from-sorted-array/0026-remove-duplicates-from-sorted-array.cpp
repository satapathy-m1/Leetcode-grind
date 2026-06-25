class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = size(nums);
        int i = 0, j = 0;
        int el = nums[0];
        while(j < n) {
            if(nums[i] == nums[j]) j++;
            else {
                i++;
                el = nums[j];
                nums[i] = el;
            }
        }
        nums[i] = el;
        return i + 1;
    }
};