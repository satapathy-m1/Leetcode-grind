class MedianFinder {
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<>> mini;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(maxi.empty()) {
            maxi.push(num);
            return;
        }
        if(maxi.top() >= num) {
            maxi.push(num);
            if(maxi.size() > mini.size() + 1) {
                mini.push(maxi.top());
                maxi.pop();
            }
        }
        else {
            mini.push(num);
            if(mini.size() > maxi.size()) {
                maxi.push(mini.top());
                mini.pop();
            }
        }
    }
    
    double findMedian() {
        if(maxi.size() == mini.size()) {
            return (double)(maxi.top() + mini.top()) / 2;
        }
        else return (double)(maxi.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */