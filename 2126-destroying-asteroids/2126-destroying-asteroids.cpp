class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(begin(asteroids), end(asteroids));
        long long m = 1ll*mass;
        for(int i : asteroids) {
            if(i > m) return false;
            m += i;
        }
        return true;
    }
};