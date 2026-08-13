class Solution {
private:
    int f(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> eo(2, 0);
        int i = 0, j = 0;
        int cnt = 0;
        while(j < n) {
            if(nums[j] % 2 == 0) eo[0]++;
            else eo[1]++;
            while(eo[1] > k) {
                int num = nums[i];
                if(num%2 == 0) eo[0]--;
                else eo[1]--;
                i++;
            }
            if(eo[1] <= k) cnt += (j - i + 1);
            j++;
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k - 1);
    }
};