class Solution {
private:
    bool isValid(int k, vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - k;
        while(i < k && j < n) {
            if(nums[i] >= nums[j]) return false;
            else {
                i++;
                j++;
            }
        }
        return true;
    }
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n / 2;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isValid(mid, nums)) {
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return n - 2 * high;
    }
};