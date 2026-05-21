class Solution {
public:
    int firstOcc(vector<int>& nums, int n, int target) {
        int low = 0, high = n - 1;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) {
                ans = mid;
            }
            if(nums[mid] >= target) {
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
    int lastOcc(vector<int>& nums, int n, int target) {
        int low = 0, high = n - 1;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) {
                ans = mid;
            }
            if(nums[mid] > target) {
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        return {firstOcc(nums, n, target), lastOcc(nums, n, target)};
    }
};