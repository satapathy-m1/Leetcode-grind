class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        auto lambda = [&](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        };
        sort(begin(trips), end(trips), lambda);
        int currCap = capacity;
        unordered_map<int, int> mpp;
        for(auto trip : trips) {
            int numPassengers = trip[0];
            int from = trip[1];
            int to = trip[2];
            for (auto it = mpp.begin(); it != mpp.end(); ) {
                if (it->first <= from) {
                    currCap += it->second;
                    it = mpp.erase(it);
                } else {
                    ++it;
                }
            }
            if(currCap < numPassengers) return false;
            currCap -= numPassengers;
            mpp[to] += numPassengers;
        }
        return true;
    }
};