class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int mini = 1e9;
        for(int i : right) mini = min(mini, i);
        int maxi = -1;
        for(int i : left) maxi = max(maxi, i);
        return max(maxi, n - mini);
    }
};