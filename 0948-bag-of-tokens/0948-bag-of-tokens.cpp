class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(begin(tokens), end(tokens));
        int i = 0, j = tokens.size() - 1;
        int score = 0;
        while(i <= j) {
            if(score == 0) {
                if(power < tokens[i]) return score;
                else {
                    power -= tokens[i];
                    score += 1;
                    i++;
                }
            }
            else {
                if(power >= tokens[i]) {
                    power -= tokens[i];
                    score += 1;
                    i++;
                }
                else {
                    if(i == j) break;
                    power += tokens[j];
                    score -= 1;
                    j--;
                }
            }
        }
        return score;
    }
};