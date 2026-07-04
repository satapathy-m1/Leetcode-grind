class Solution {
private:
    vector<long long> dp;
    long long f(int i, vector<vector<int>>& questions, int n) {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        long long skip = f(i + 1, questions, n);
        long long solve = questions[i][0] + f(i + questions[i][1] + 1, questions, n);

        return dp[i] = max(skip, solve);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        dp.resize(n + 1, 0);

        for(int i = n - 1; i >= 0; i--) {

            long long skip = dp[i + 1];
            long long solve = questions[i][0] + dp[min(n, i + questions[i][1] + 1)];

            dp[i] = max(skip, solve);
        }
        return dp[0];
    }
};