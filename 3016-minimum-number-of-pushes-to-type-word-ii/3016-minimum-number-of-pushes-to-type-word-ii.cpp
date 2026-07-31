class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> freq(26, 0);
        for(char c : word) freq[c - 'a']++;
        sort(begin(freq), end(freq));
        int cnt = 0;
        int pushes = 0;
        for(int i = 25; i >= 0; i--) {
            if(freq[i] == 0) break;
            pushes += ((cnt / 8) + 1) * freq[i];
            cnt++;
        }
        return pushes;
    }
};