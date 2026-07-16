class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = 1e9;
        int maxProfit = 0;
        for(int i : prices) {
            minBuy = min(minBuy, i);
            maxProfit = max(maxProfit, i - minBuy);
        }
        return maxProfit;
    }
};