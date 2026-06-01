class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> nge(n, n);
        for(int i = n - 1; i >= 0; i--) {
            if(st.empty()) {
                st.push(i);
                continue;
            }
            else {
                while(!st.empty() && temperatures[i] >= temperatures[st.top()]) st.pop();
                if(!st.empty()) nge[i] = st.top();
                st.push(i);
            }
        }
        for(int i = 0; i < n; i++) {
            if(nge[i] == n) nge[i] = 0;
            else {
                nge[i] = nge[i] - i;
            }
        }
        return nge;
    }
};