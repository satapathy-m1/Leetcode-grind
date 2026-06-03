class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int>(k + 1, 0));
        for(int i = n - 1; i >= 0; i--) {
            for(int flag = 0; flag < 2; flag++) {
                for(int K = 1; K <= k ; K++) {
                    int profit = 0;
                    if(flag) {
                        int buyProfit = max(-prices[i] + ahead[!flag][K],  0 + ahead[flag][K]);
                        profit = max(profit, buyProfit);
                    }
                    else {
                        int sellProfit = max(prices[i] + ahead[!flag][K - 1],  0 + ahead[flag][K]); 
                        profit = max(profit, sellProfit);
                    }
                    ahead[flag][K] = profit;
                }
            }
        }
        return ahead[1][k];
    }
};