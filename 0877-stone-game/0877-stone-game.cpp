class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int i = 0, j = n - 1;
        bool turn = true;
        while(i < j) {
            if(turn) {
                if(piles[i] >= piles[j]) i++;
                else j--;
            }
            else {
                if(piles[i] >= piles[j]) j--;
                else i++;
            }
            turn = !turn;
        }
        return true;
    }
};