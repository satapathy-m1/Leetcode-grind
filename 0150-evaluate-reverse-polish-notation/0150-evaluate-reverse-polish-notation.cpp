class Solution {
public:

    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> s;
        int ans = 0;
        vector<string> v = {"+", "-", "*", "/"};
        unordered_set<string> st(begin(v), end(v));
        for(int i = 0; i < n; i++) {
            string cur = tokens[i];
            if(st.count(cur)) {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                cout << a << " " << b << endl;
                if(cur == "+") {
                    s.push(a + b);
                }
                else if(cur == "-") {
                    s.push(b - a);
                }
                else if(cur == "*") {
                    s.push(a * b);
                }
                else s.push(b / a);
            }
            else {
                s.push(stoi(cur));
            }
        }
        if(st.empty()) return -1;
        return s.top();
    }
};