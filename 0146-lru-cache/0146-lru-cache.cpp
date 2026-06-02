class LRUCache {
public:
    int size;
    list<pair<int, int>> dll;

    unordered_map<int, list<pair<int, int>> :: iterator> mpp;
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        auto keyToFind = mpp.find(key);
        if(keyToFind == mpp.end()) return -1;
        auto it = keyToFind -> second;
        dll.splice(dll.begin(), dll, it);
        return it -> second;
    }
    
    void put(int key, int value) {
        auto it = mpp.find(key);

        if (it != mpp.end()) {
            dll.erase(it->second);
        }
        if(size == dll.size()) {
            int keyToRemove = dll.back().first;
            dll.pop_back();
            mpp.erase(keyToRemove);
        }
        dll.push_front({key, value});
        mpp[key] = dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */