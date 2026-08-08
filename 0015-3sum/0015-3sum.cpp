class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        set<vector<int>> st;
        vector<vector<int>> ans;
        for(int i = 0; i < n - 2; i++) {
            int j = i + 1, k = n - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0) j++;
                else if(sum > 0) k--;
                else {
                    st.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
            }
        }
        for(auto v : st) {
            ans.push_back(v);
        }
        return ans;
    }
};