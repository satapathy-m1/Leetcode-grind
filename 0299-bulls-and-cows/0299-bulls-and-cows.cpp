class Solution {
public:
    string getHint(string secret, string guess) {
       int n = secret.size();
       int bulls = 0;
       vector<int> f1(10, 0), f2(10, 0);
        for(int i = 0; i < n; i++) {
            if(secret[i] == guess[i]) {
                bulls++;
            }
            else {
                f1[secret[i] - '0']++;
                f2[guess[i] - '0']++;
            }
        }
        int cows = 0;
        for(int i = 0; i < 10; i++) cows += min(f1[i], f2[i]);

        string ans = to_string(bulls) + "A" + to_string(cows) + "B";
        return ans;
    }
};