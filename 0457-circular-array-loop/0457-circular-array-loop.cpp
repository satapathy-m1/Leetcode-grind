class Solution {
private:
    int next(vector<int>& nums, int i) {
        int n = size(nums);
        return ((i + nums[i])%n + n) % n;
    }
    bool direction(vector<int>& nums, int i) {
        return nums[i] > 0;
    }
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = size(nums);
        for(int i = 0; i < n; i++) {
            bool forward = (nums[i] > 0);
            int slow = i, fast = i;
            while(direction(nums, slow) == forward && direction(nums, fast) == forward && direction(nums, next(nums, fast)) == forward) {
                slow = next(nums, slow);
                fast = next(nums, next(nums, fast));
                if(slow == fast) {
                    if (slow == next(nums, slow))
                        break; 
                    return true;
                }
            }
        }
        return false;
    }
};