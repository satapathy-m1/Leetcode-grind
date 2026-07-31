class LRUCache {
private:
    list<int> dll;
    unordered_map<int, pair<int, list<int> :: iterator>> mpp;
    int cap;
    int currSize;
public:
    LRUCache(int capacity) {
        this -> cap = capacity;
        currSize = 0;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()) return -1;
        auto [val, add] = mpp[key];
        dll.erase(add);
        dll.push_front(key);
        mpp[key] = {val, dll.begin()};
        return val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()) {
            auto [val, add] = mpp[key];
            dll.erase(add);
            dll.push_front(key);
            mpp[key] = {value, dll.begin()};
        }
        else if(currSize == cap) {
            int lruKey = dll.back();
            mpp.erase(lruKey);
            dll.pop_back();
            dll.push_front(key);
            mpp[key] = {value, dll.begin()};
        }
        else {
            dll.push_front(key);
            mpp[key] = {value, dll.begin()};
            currSize++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */