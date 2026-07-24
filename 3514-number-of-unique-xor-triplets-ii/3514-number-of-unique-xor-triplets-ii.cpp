class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                st.insert(nums[i] ^ nums[j]);
            }
        }
        unordered_set<int> ans;
        for(auto x : st) {
            
            for(int i : nums) {
                ans.insert(i ^ x);
            }
        }
        return ans.size();
    }
};