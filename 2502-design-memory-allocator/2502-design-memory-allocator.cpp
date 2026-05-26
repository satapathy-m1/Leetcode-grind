class Allocator {
public:
    vector<int> vec;
    int n;
    Allocator(int n) {
        this -> n = n;
        vec.resize(n, -1);
    }
    
    int allocate(int size, int mID) {
        int idx = -1;
        for(int i = 0; i < n; i++) {
            if(vec[i] == -1) {
                int j = i + 1;
                int cnt = 1;
                while(j < n) {
                    if(vec[j] == -1) cnt++;
                    else break;
                    j++;
                }
                if(cnt >= size) {
                    idx = i;
                    break;
                }
            }
        }
        if(idx == -1 || idx + size > n) return -1;
        
        for(int i = idx; i < idx + size; i++) {
            vec[i] = mID;
        }
        return idx;
    }
    
    int freeMemory(int mID) {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(vec[i] == mID) {
                vec[i] = -1;
                cnt++;
            }
        }

        return cnt;
    }
    
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */