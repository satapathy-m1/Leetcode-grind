class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> lastUsed(26, -1);
        vector<int> freq(26, 0);
        priority_queue<pair<int, char>> pq;
        for(char c : tasks) {
            freq[c - 'A']++;
        }
        for(int i = 0; i < 26; i++) {
            if(freq[i] != 0) {
                pq.push({freq[i], i + 'A'});
            }
        }
        int time = 0;
        while(!pq.empty()) {
            priority_queue<pair<int, char>> tpq;
            while(!pq.empty() && (lastUsed[pq.top().second - 'A'] != -1 && lastUsed[pq.top().second - 'A'] + n >= time)) {
                tpq.push(pq.top());
                pq.pop();
            }
            if(pq.empty()) {
                while(!tpq.empty()) {
                    pq.push(tpq.top());
                    tpq.pop();
                }
                time++;
            }
            else {
                auto [freq, c] = pq.top();
                pq.pop();
                freq -= 1;
                if(freq == 0) {lastUsed[c - 'A'] = time;}
                else {
                    pq.push({freq, c});
                    lastUsed[c - 'A'] = time;
                }
                while(!tpq.empty()) {
                    pq.push(tpq.top());
                    tpq.pop();
                }
                time++;
            }
        }
        return time;
    }
};