class FrontMiddleBackQueue {
private:
    void balance(deque<int>& dq1, deque<int>& d2) {
        if(dq1.size() < dq2.size()) {
            int val = dq2.front();
            dq2.pop_front();
            dq1.push_back(val);
        }
    }
public:
deque<int> dq1, dq2;
    FrontMiddleBackQueue() {
        dq1.clear();
        dq2.clear();
    }
    
    void pushFront(int val) {
        dq1.push_front(val);
        if(dq1.size() > dq2.size() + 1) {
            int d = dq1.back();
            dq1.pop_back();
            dq2.push_front(d);
        }
    }
    
    void pushMiddle(int val) {
        if(dq1.size() == dq2.size() + 1) {
            int d = dq1.back();
            dq1.pop_back();
            dq2.push_front(d);
        }
        dq1.push_back(val);
    }
    
    void pushBack(int val) {
        if(dq1.empty()) dq1.push_back(val);
        else {
            dq2.push_back(val);
            balance(dq1, dq2);
        }
    }
    
    int popFront() {
        if(dq1.empty()) return -1;
        int d = dq1.front();
        dq1.pop_front();
        balance(dq1, dq2);
        return d;
    }
    
    int popMiddle() {
        if(dq1.empty()) return -1;
        int d = dq1.back();
        dq1.pop_back();
        balance(dq1, dq2);
        return d;
    }
    
    int popBack() {
        if(dq1.empty()) return -1;
        if(dq2.empty()) {
            int val = dq1.back();
            dq1.pop_back();
            return val;
        }
        else {
            int val = dq2.back();
            dq2.pop_back();
            if(dq1.size() > dq2.size() + 1) {
                int d = dq1.back();
                dq1.pop_back();
                dq2.push_front(d);
            }
            return val;
        }
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */