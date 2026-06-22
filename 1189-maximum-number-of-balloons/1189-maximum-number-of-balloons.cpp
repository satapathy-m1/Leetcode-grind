class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        unordered_map<char, int> mpp;
        for(char c : text) {
            if(c == 'b' || c == 'a' || c == 'l' || c == 'o' || c == 'n') mpp[c]++; 
        }
        int numOfBalloons = 0, maxi = 1e9;
        if(mpp['b'] == 0 || mpp['a'] == 0 || mpp['l'] < 2 || mpp['o'] < 2 || mpp['n'] == 0) return numOfBalloons;
        for(auto it : mpp) {
            if(it.first == 'o' || it.first == 'l') maxi = min(maxi, it.second / 2);
            else maxi = min(maxi, it.second);
        }
        return max(maxi, numOfBalloons);
    }
};