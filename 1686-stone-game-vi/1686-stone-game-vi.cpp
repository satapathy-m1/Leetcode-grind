class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = size(aliceValues);
        priority_queue<pair<int, int>> pq;
        int sum1 = 0, sum2 = 0;
        bool flag = 1;
        for(int i = 0; i < n; i++) {
            pq.push({aliceValues[i] + bobValues[i], i});
        }

        while(!pq.empty()) {
            auto [s, i] = pq.top();
            pq.pop();
            if(flag) {
                sum1 += aliceValues[i];
            }
            else sum2 += bobValues[i];
            flag = !flag;
        }
        if(sum1 > sum2) return 1;
        else if(sum1 < sum2) return -1;
        else return 0;
    }
};