class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int x = 0, y = 0, z = 0, ans = 0, m = 1e9 + 7;
        for(int &i : nums) {
            if(i < a) {
                x++;
                ans = (ans + y + z)%m;
            }
            else if(i > b) {
                z++;
            }
            else {
                y++;
                ans = (ans + z)%m;
            }
        }
        return ans%m;
    }
};