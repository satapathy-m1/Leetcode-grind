class Solution {
public:
    string util1(string s, int a) {
        for(int i = 0; i < s.length(); i++) {
            if(i%2==1) {
                int dig = s[i] - '0';
                dig += a;
                s[i] = (dig%10 + '0');
            }
        }
        return s;
    }
    string util2(string s, int b) {
        int n = s.length();
        reverse(begin(s), begin(s) + n - b);
        reverse(begin(s) + n - b, end(s));
        reverse(begin(s), end(s));
        return s;
    }
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        unordered_set<string> st;
        q.push(s);
        st.insert(s);
        string ans = s;
        while(!q.empty()) {
            string currStr = q.front();
            q.pop();
            if(currStr < ans) ans = currStr;
            string op1 = util1(currStr, a);
            if(!st.count(op1)) {
                st.insert(op1);
                q.push(op1);
            }
            string op2 = util2(currStr, b);
            if(!st.count(op2)) {
                st.insert(op2);
                q.push(op2);
            }
        }
        return ans;
    }
};