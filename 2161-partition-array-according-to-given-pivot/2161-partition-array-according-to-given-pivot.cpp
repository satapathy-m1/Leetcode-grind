class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> smallers, greaters;
        int cnt = 0;
        for(int i : nums) {
            if(i < pivot) smallers.push_back(i);
            else if(i > pivot) greaters.push_back(i);
            else cnt++;
        }
        vector<int> ans;
        for(int i : smallers) ans.push_back(i);
        while(cnt > 0) {
            ans.push_back(pivot);
            cnt--;
        }
        for(int i : greaters) ans.push_back(i);
        return ans;
    }
};