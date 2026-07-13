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
        unordered_map<string, int> mpp;
        string temp = string(5, '0');
        mpp[temp] = -1;
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            int idx = getIdx(s[i]);
            if(idx != -1) {
                temp[idx] = ((temp[idx] - '0' + 1) % 2) + '0';
            }
            if(mpp.count(temp)) maxi = max(maxi, i - mpp[temp]);
            else mpp[temp] = i;
        }
        return maxi;
    }
};