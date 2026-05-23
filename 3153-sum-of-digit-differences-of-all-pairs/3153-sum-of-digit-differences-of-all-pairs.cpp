class Solution {
private:
    int findNumOfDigits(int num) {
        int cnt = 0;
        while(num) {
            cnt++;
            num /= 10;
        }
        return cnt;
    }
public:
    void updateOccCount(int num, unordered_map<int, unordered_map<int, long long>>& mpp) {
        int pos = 0;
        while(num) {
            int dig = num % 10;
            num /= 10;
            mpp[pos][dig]++;
            pos++;
        }
    }
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        int m = findNumOfDigits(nums[0]);
        unordered_map<int, unordered_map<int, long long>> mpp;
        for(int i : nums) {
            updateOccCount(i, mpp);
        }
        long long cnt = 0;
        for(auto it : mpp) {
            unordered_map<int, long long> mp2 = it.second;
            for(auto it2 : mp2) {
                cnt += (1ll*it2.second*(n - it2.second));
            } 
        }
        return cnt /2;
    }
};