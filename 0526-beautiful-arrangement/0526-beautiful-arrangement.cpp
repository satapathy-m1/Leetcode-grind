class Solution {
private:
    void backTrack(int index, vector<int>& nums, int n, int &cnt) {
        if(index >= n) {
            bool flag = true;
            for(int i = 0; i < n; i++) {
                if(nums[i] % (i + 1) != 0 && (i + 1) % nums[i] != 0) flag = false;
            }
            cnt += flag;
            return;
        }
        for(int i = index; i < n; i++) {
            swap(nums[index], nums[i]);

            int pos = index + 1;
            if(nums[index] % pos == 0 || pos % nums[index] == 0) {
                backTrack(index + 1, nums, n, cnt);
            }
            swap(nums[index], nums[i]);
        }
    }
public:
    int countArrangement(int n) {
        vector<int> nums;
        for(int i = 0; i < n; i++) nums.push_back(i + 1);
        int index = 0;
        int cnt = 0;
        backTrack(index, nums, n, cnt);
        return cnt;
    }
};