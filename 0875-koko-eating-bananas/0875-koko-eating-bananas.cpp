class Solution {
private:
    bool isPossible(int cap, vector<int>& piles, int h) {
        int time = 0;
        for(int pile : piles) {
            time += ceil((double)pile / (double)cap);
            if(time > h) return false;
        }
        return time <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(begin(piles), end(piles));
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isPossible(mid, piles, h)) {
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};