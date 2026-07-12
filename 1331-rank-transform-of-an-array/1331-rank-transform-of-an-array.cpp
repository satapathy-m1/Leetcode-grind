class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return {};
        vector<int> nums = arr;
        unordered_map<int, int> mpp;
        sort(begin(nums), end(nums));
        mpp[nums[0]] = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i - 1] < nums[i]) {
                mpp[nums[i]] = mpp[nums[i - 1]] + 1; 
            }
            else {
                mpp[nums[i]] = mpp[nums[i - 1]];
            }
        }
        for(int i = 0; i < n; i++) {
            arr[i] = mpp[arr[i]];
        }
        return arr;
    }
};