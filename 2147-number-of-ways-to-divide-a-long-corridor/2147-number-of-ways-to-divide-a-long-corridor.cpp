class Solution {
public:

    int numberOfWays(string corridor) {
        vector<int> pos;
        int idx = 0;
        for(char c : corridor) {
            if(c == 'S') pos.push_back(idx);
            idx++;
        }
        int n = pos.size();
        if(n == 0 || n%2 == 1) return 0;
        
        long long ans = 1;
        long long m = 1e9+7;
        for(int i = 2; i < n; i+=2) {
            ans = ((ans%m) * ((pos[i] - pos[i - 1])%m))%m;
        }
        return (int)((ans%m)%m)%m;
    }
};