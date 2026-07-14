class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int lowest = 1e9, lowestIdx = -1;
        int curr = 0;
        for(int i = 0; i < n; i++) {
            curr = curr + gas[i] - cost[i];
            if(curr < lowest) {
                lowest = curr;
                lowestIdx = (i + 1) % n;
            }
        }
        int tank = 0;

        for (int k = 0; k < n; k++) {
            int i = (lowestIdx + k) % n;
            tank += gas[i] - cost[i];
            if (tank < 0)
                return -1;
        }

        return lowestIdx;
    }
};