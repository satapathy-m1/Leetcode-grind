class Solution {
private:
    int f(int day, vector<int>& bloomDay, int m, int k) {
        int curK = 0;
        int noOfFlowers = 0;
        for(int d : bloomDay) {
            if(d <= day) {
                curK++;
            }
            else curK = 0;
            if(curK == k) {
                noOfFlowers++;
                curK = 0;
            }
            if(noOfFlowers == m) return true;  
        }
        return noOfFlowers >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(m > n/k) return -1;
        int low = 1, high = *max_element(begin(bloomDay), end(bloomDay));
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(f(mid, bloomDay, m, k)) {
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};