class Solution {
public:
    int getNumLen(int num) {
        int cnt = 0;
        while(num) {
            num /= 10;
            cnt++;
        }
        return cnt;
    }
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        
        int idx = 0;
        while(i < n) {
            char currCh = chars[i];
            int cnt = 0;
            while(i < n && chars[i] == currCh) {
                cnt++;
                i++;
            }
            chars[idx] = currCh;
            idx++;
            if(cnt > 1) {
                string s = to_string(cnt);
                for(char ch : s) chars[idx++] = ch;                           
            }
        }
        
        return idx;
    }
};