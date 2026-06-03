class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;
        for(int i : asteroids) {
            if(i > 0) {
                st.push(i);
            }
            else {
                while(!st.empty()&& st.top() > 0 && abs(i) > st.top()) st.pop();
                bool destroyed = false;
                if(!st.empty() && abs(i) == st.top()) {
                    st.pop();
                    destroyed = true;
                }
                if(!destroyed && (st.empty() || st.top() < 0)) st.push(i);
            }
        }
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};