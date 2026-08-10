class MinStack {
private:
    stack<pair<long long, long long>> st;
    long long mini = LLONG_MAX;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()) {
            mini = 1LL*value;
            st.push({value, mini});
        }
        else {
            mini = min(mini, 1LL*value);
            st.push({value, mini});
        }
    }
    
    void pop() {
        if(st.empty()) return;
        st.pop();
        if(!st.empty()) mini = st.top().second;
        else mini = LLONG_MAX;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        if(st.empty()) {
            throw runtime_error("St. empty");
            return -1;
        }
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */