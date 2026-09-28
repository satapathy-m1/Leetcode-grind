class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lm(n, height[0]);
        vector<int> rm(n, height[n - 1]);
        for(int i = 1; i < n; i++) {
            lm[i] = max(lm[i - 1], height[i]);
        }
        for(int i = n - 2; i >= 0; i--) {
            rm[i] = max(rm[i + 1], height[i]);
        }

        int waterTrapped = 0;
        for(int i = 0; i < n; i++) {
            waterTrapped += (min(lm[i], rm[i]) - height[i]);
        }
        return waterTrapped;
    }
};