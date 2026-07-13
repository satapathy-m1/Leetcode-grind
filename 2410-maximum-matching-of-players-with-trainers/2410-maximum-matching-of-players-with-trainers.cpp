class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int m = players.size(), n = trainers.size();
        sort(begin(players), end(players));
        sort(begin(trainers), end(trainers));
        int cnt = 0, i = 0, j = 0;
        while(i < m && j < n) {
            if(players[i] <= trainers[j]) {
                cnt++;
                i++;
                j++;
            }
            else j++;
        }
        return cnt;
    }
};