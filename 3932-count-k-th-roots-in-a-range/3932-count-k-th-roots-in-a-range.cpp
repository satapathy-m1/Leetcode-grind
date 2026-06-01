class Solution {
public:
    bool isValid(int mid, int k, int num) {
        if(mid == 0) return true;
        int ans = 1;
        for(int i = 0; i < k; i++) {
            if(ans > num / mid) return false;
            ans = ans * mid;
        }
        return ans <= num;
    }
    int bs(int l, int num, int k) {
        int low = l, high = num;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isValid(mid, k, num)) {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
    int countKthRoots(int l, int r, int k) {
        if(k == 1) return r - l + 1;
        int rightRange = bs(0, r, k);
        int leftRange = bs(0, l - 1, k);
        return rightRange - leftRange;
    }
};