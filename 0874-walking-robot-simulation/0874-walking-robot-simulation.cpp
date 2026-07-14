class Solution {
private:
    char dirHelper(char currDir, int command) {
        if(command == -1) {
            if(currDir == 'N') return 'E';
            else if(currDir == 'E') return 'S';
            else if(currDir == 'S') return 'W';
            else return 'N';
        }
        else {
            if(currDir == 'N') return 'W';
            else if(currDir == 'E') return 'N';
            else if(currDir == 'S') return 'E';
            else return 'S';
        }
        return '#';
    }
    vector<int> f(int curX, int curY, set<pair<int, int>>& st, int posCol, int posRow, int cap) {
        int ansX = curX, ansY = curY;
        if(posCol == 0) {
            while(cap > 0) {
                ansX += (posRow)*(1);
                if(st.count({ansX, ansY})) {
                    return {ansX - (posRow*1), ansY};
                }
                cap--;
            }
            return {ansX, ansY};
        }

        else if(posRow == 0) {
            while(cap > 0) {
                ansY += (posCol*1);
                if(st.count({ansX, ansY})) {
                    return {ansX, ansY - (posCol*1)};
                }
                cap--;
            }
            return {ansX, ansY};
        }
        return {0, 0};
    }
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> st;
        for(auto o : obstacles) {
            st.insert({o[0], o[1]});
        }
        char currDir = 'N';
        int curX = 0, curY = 0;
        int maxi = 0;
        for(int command : commands) {
            if(command == -1 || command == -2) {
                currDir = dirHelper(currDir, command);
            }
            else {
                int posCol = 0, posRow = 0;
                if(currDir == 'N') {
                    posCol = 1;
                    posRow = 0;
                }
                else if(currDir == 'E') {
                    posCol = 0;
                    posRow = 1;
                }
                else if(currDir == 'S') {
                    posCol = -1;
                    posRow = 0;
                }
                else {
                    posCol = 0;
                    posRow = -1;
                }
                vector<int> newCord = f(curX, curY, st, posCol, posRow, command);
                int dist = newCord[0] * newCord[0] + newCord[1] * newCord[1];
                maxi = max(maxi, dist);
                curX = newCord[0];
                curY = newCord[1];
            }
        }
        return maxi;
    }
};