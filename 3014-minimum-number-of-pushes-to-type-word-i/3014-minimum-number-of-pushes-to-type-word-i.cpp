class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int push = 0;
        for(int i = 0; i < n; i++) {
            push += i / 8 + 1;
        }
        return push;
    }
};