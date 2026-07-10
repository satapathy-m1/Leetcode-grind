class SeatManager {
    priority_queue<int, vector<int>, greater<int>> pq;
    int cnt;
public:
    SeatManager(int n) {
        cnt = 0;
    }
    
    int reserve() {
        if(pq.empty()) {
            return ++cnt;
        }
        else {
            int val = pq.top();
            pq.pop();
            return val;
        }
    }
    
    void unreserve(int seatNumber) {
        if(seatNumber == cnt) {
            --cnt;
        }
        else {
            pq.push(seatNumber);
        }
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */