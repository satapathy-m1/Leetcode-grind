class MinStack {
public:
    long long mini = LLONG_MAX;
    stack<long long> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) {
            mini = val;
            st.push(val);
        }
        else {
            if(val >= mini) st.push(val);
            else {
                st.push(2LL * val - mini);
                mini = val;
            }
        }
    }
    
    void pop() {
        if(st.top() >= mini) {
            st.pop();
            return;
        }
        mini = 2LL * mini - st.top();
        st.pop();
    }
    
    int top() {
        if(st.top() >= mini) return st.top();
        return mini;
    }
    
    int getMin() {
        if(st.empty()){
            throw runtime_error("St. empty");
            return -1;
        }
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */