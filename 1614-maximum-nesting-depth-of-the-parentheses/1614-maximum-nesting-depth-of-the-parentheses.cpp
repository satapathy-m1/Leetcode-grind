class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0, cnt = 0;
        for(char c : s) {
            if(c == '(') cnt++;
            else if(c == ')') cnt--;
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};