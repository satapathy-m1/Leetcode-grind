class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int i = 0, j = 0;
        int arr[101] = {0};
        vector<int> ans;
        while(j < n) {
            arr[nums[j] + 50]++;
            if(j - i + 1 == k) {
                int temp = x;
                int idx = 0;
                while(idx < 50 && temp > 0) {
                    
                    if(arr[idx] > 0) {
                        temp -= arr[idx];
                    }
                    idx++;
                }
                if(temp > 0) {
                    ans.push_back(0);
                }
                else ans.push_back(idx - 1 - 50);
                arr[nums[i] + 50]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};