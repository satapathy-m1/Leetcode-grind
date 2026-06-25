class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minBuy = INT_MAX;
        for(int i : prices) {
            minBuy = min(minBuy, i);
            maxProfit = max(maxProfit, i - minBuy);
        }
        return maxProfit;
    }
};