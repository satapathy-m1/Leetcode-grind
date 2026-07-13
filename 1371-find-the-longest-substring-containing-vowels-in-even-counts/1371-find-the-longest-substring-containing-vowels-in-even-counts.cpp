class Solution {
private:
    int getIdx(char c) {
        if(c == 'a') return 0;
        else if(c == 'e') return 1;
        else if(c == 'i') return 2;
        else if(c == 'o') return 3;
        else if(c == 'u') return 4;
        else return -1;
    }
public:
    int findTheLongestSubstring(string s) {
        int n = s.length();
        unordered_map<int, int> mpp;
        int temp = 0;
        mpp[temp] = -1;
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            int idx = getIdx(s[i]);
            if(idx != -1) {
                temp = temp ^ (1 << (5 - 1 - idx));
            }
            if(mpp.count(temp)) maxi = max(maxi, i - mpp[temp]);
            else mpp[temp] = i;
        }
        return maxi;
    }
};