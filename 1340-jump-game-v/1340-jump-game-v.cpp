class Solution {
public:
vector<int> dp;
    int f(int i, int n, vector<int>& arr, vector<pair<int, int>>& range) {
        if(i < 0 || i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int maxi = 1;
        int leftRange = range[i].first;
        int rightRange = range[i].second;
        for(int j = i - 1; j >= leftRange; j--) {
            maxi = max(maxi, 1 + f(j, n, arr, range));
        }
        for(int j = i + 1; j <= rightRange; j++) {
            maxi = max(maxi, 1 + f(j, n, arr, range));
        }
        return dp[i] = maxi;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        dp.assign(n, -1);
        vector<pair<int, int>> range(n);
        for(int i = 0; i < n; i++) {
            int leftRange = i;
            for(int j = i - 1; j >= max(0, i - d); j--) {
                if(arr[j] < arr[i]) {
                    leftRange = j;
                }
                else break;
            }
            int rightRange = i;
            for(int j = i + 1; j <= min(n - 1, i + d); j++) {
                if(arr[j] < arr[i]) {
                    rightRange = j;
                }
                else break;
            }
            range[i] = make_pair(leftRange, rightRange);
        }
        int maxi = 1;
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, f(i, n, arr, range));
        }
        return maxi;
    }
};