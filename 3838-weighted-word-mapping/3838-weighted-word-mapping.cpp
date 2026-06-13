class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(string& s : words) {
            int sum = 0;
            for(char c : s) {
                sum += weights[c - 'a'];
            }
            int rem = sum % 26;
            int toJump = 25 - rem;
           
            ans += string(1, 'a' + toJump);
        }
        return ans;
    }
};