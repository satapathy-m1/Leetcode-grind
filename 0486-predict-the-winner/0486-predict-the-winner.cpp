class Solution {
private:
    int f(int i, int j, vector<int>& nums) {
        if(i > j) return 0;

        int c1 = nums[i] + min(f(i + 2, j, nums), f(i + 1, j - 1, nums));
        int c2 = nums[j] + min(f(i, j - 2, nums), f(i + 1, j - 1, nums));

        return max(c1, c2);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        int sum = accumulate(begin(nums), end(nums), 0);
        int ans = f(i, j, nums);
        return ans >= (sum+1) / 2;
    }
};