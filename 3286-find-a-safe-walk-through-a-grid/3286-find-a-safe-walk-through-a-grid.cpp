using namespace std;

class Solution {
public:
    vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int r = grid.size(), c = grid[0].size();
        deque<pair<int, int>> q;
        vector<vector<int>> minDmg(r, vector<int>(c, INT_MAX));
        
        minDmg[0][0] = grid[0][0];
        q.push_front({0, 0});
        
        while (!q.empty()) {
            auto [rIdx, cIdx] = q.front();
            q.pop_front();
            
            if (rIdx == r - 1 && cIdx == c - 1) {
                return health - minDmg[rIdx][cIdx] > 0;
            }
            
            for (auto [dr, dc] : moves) {
                int nR = rIdx + dr, nC = cIdx + dc;
                
                if (nR >= 0 && nR < r && nC >= 0 && nC < c) {
                    int newDmg = minDmg[rIdx][cIdx] + grid[nR][nC];
                    
                    if (newDmg < minDmg[nR][nC]) {
                        minDmg[nR][nC] = newDmg;
                        
                        if (grid[nR][nC] == 1) {
                            q.push_back({nR, nC});
                        } else {
                            q.push_front({nR, nC});
                        }
                    }
                }
            }
        }
        
        return false;
    }
};