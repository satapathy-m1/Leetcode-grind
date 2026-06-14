class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people), end(people));
        int i = 0, j = people.size() - 1;
        int boats = 0;
        while(i <= j) {
            if(people[i] + people[j] <= limit) {
                i++;
            }
            boats += 1;
            j--;
        }
        return boats;
    }
};