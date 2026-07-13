class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        vector<int> ans;
        for (int len = 2; len <= 9; len++) {
            for (int start = 1; start + len - 1 <= 9; start++) {
                int num = 0;
                int digit = start;
                for (int k = 0; k < len; k++)
                    num = num * 10 + digit++;

                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }
        return ans;
    }
};