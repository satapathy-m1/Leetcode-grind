class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(begin(cost), end(cost));
        int n = cost.size();
        int i = n - 1, buys = 0;
        int minCost = 0;
        while(i >= 0) {
            if(buys == 0 || buys == 1) {
                minCost += cost[i];
                buys++;
            }
            else if(buys == 2) {
                minCost += 0;
                buys++;
            }
            if(buys == 3) buys = 0;
            i--;
        }
        return minCost;
    }
};