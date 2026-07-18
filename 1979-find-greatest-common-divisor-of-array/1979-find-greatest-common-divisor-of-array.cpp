class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxi = 1, mini = 1001;
        for(int i : nums) {
            if(maxi < i) maxi = i;
            if(mini > i) mini = i;
        }
        return gcd(maxi, mini);
    }
};