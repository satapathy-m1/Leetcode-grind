class Solution {    
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& q) {
        int n = s.length();
        long long modVal = 1000000007;
        
        vector<long long> preSum(n + 1, 0);
        vector<long long> preVal(n + 1, 0);
        vector<int> preCnt(n + 1, 0);
        vector<long long> pwr(n + 1, 1);

        for (int i = 0; i < n; ++i) {
            pwr[i + 1] = (pwr[i] * 10) % modVal;
            int digit = s[i] - '0';
            
            preSum[i + 1] = preSum[i] + digit;
            
            if (digit != 0) {
                preVal[i + 1] = (preVal[i] * 10 + digit) % modVal;
                preCnt[i + 1] = preCnt[i] + 1;
            } else {
                preVal[i + 1] = preVal[i];
                preCnt[i + 1] = preCnt[i];
            }
        }

        vector<int> res;
        res.reserve(q.size());
        
        for (const auto& iter : q) {
            int left = iter[0];
            int right = iter[1];

            long long sumStr = preSum[right + 1] - preSum[left];
            int cntZero = preCnt[right + 1] - preCnt[left];

            long long subVal = (preVal[left] * pwr[cntZero]) % modVal;
            long long valStr = (preVal[right + 1] - subVal + modVal) % modVal;

            res.push_back((valStr * (sumStr % modVal)) % modVal);
        }
        
        return res;
    }
};