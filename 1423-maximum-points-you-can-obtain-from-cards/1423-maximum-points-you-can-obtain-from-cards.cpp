class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> pre(n, 0);
        pre[0] = cardPoints[0];
        for(int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + cardPoints[i];
        }
        int i = 0, j = n - k;
        if(j == 0) return pre[n - 1];
        int ans = 0;
        while(j <= n) {
            int sumOfCurrWindow = pre[j-1] - (i > 0 ? pre[i - 1] : 0);
            ans = max(ans, pre[n - 1] - sumOfCurrWindow);
            i++;
            j++; 
        }
        return ans;
    }
};