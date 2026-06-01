class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> ms(begin(nums1), end(nums1));
        vector<int> ans;
        
        for(int i : nums2) {
            auto x = ms.upper_bound(i);
            if(x == ms.end()) {
                x = ms.begin();
            }
            ans.push_back(*x);
            ms.erase(x);
        }
        
        return ans;
    }
};