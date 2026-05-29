class Solution {
private:
    int util(int num) {
        int sum = 0;
        while(num) {
            sum += (num%10);
            num /= 10;
        }
        return sum;
    }
public:
    int minElement(vector<int>& nums) {
        int mini = 1e9;
        for(int i = 0; i < nums.size(); i++) {
            mini = min(mini, util(nums[i]));
        }
        return mini;
    }
};