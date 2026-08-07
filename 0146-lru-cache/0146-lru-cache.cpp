class LRUCache {
private:
    int n;
    int currSize;
    unordered_map<int, pair<list<int>::iterator, int>> mpp;
    list<int> dll;
public:
    LRUCache(int capacity) {
        n = capacity;
        currSize = 0;
    }
    
    int get(int key) {
        if(!mpp.count(key)) return -1;
        auto [add, val] = mpp[key];
        dll.erase(add);
        dll.push_front(key);
        mpp[key] = {dll.begin(), val};
        return val;
    }
    
    void put(int key, int value) {
        if(mpp.count(key)) {
            auto [add, val] = mpp[key];
            dll.erase(add);
            dll.push_front(key);
            mpp[key] = {dll.begin(), value};
            return;
        }
        if(currSize == n) {
            int keyToDel = dll.back();
            dll.pop_back();
            mpp.erase(keyToDel);
            currSize--;
        }
        dll.push_front(key);
        mpp[key] = {dll.begin(), value};
        currSize++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */