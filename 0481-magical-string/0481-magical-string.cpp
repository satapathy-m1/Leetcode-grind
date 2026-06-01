class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        int head = 2;
        int cnt = 1;
        char next = '1';
        while(s.length() < n) {
            int freq = s[head] - '0';
            while(freq-- && s.size() < n) {
                s += next;
                if(next == '1') cnt++;
            }
            next = next == '1' ? '2' : '1';
            head++;
        }
        return cnt;
    }
};