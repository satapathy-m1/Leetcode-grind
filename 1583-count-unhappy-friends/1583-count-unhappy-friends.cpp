class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int cnt = 0;

        for (auto pair : pairs) {
            int x = pair[0], y = pair[1];
            auto x_pref = preferences[x];

            int y_idx = 0;
            while (x_pref[y_idx] != y)
                y_idx++;

            for (int i = 0; i < y_idx; i++) {
                int u = x_pref[i];
                int u_partner = -1;
                for (auto p : pairs) {
                    if (p[0] == u) {
                        u_partner = p[1];
                        break;
                    }
                    if (p[1] == u) {
                        u_partner = p[0];
                        break;
                    }
                }
                int x_idx = 0;
                int partner_idx = 0;

                while (preferences[u][x_idx] != x)
                    x_idx++;

                while (preferences[u][partner_idx] != u_partner)
                    partner_idx++;
                if (x_idx < partner_idx) {
                    cnt++;
                    break;
                }
            }

            auto y_pref = preferences[y];

            int x_idx = 0;
            while (y_pref[x_idx] != x)
                x_idx++;

            for (int i = 0; i < x_idx; i++) {
                int u = y_pref[i];

                int u_partner = -1;
                for (auto p : pairs) {
                    if (p[0] == u) {
                        u_partner = p[1];
                        break;
                    }
                    if (p[1] == u) {
                        u_partner = p[0];
                        break;
                    }
                }

                int y_pos = 0;
                int partner_pos = 0;

                while (preferences[u][y_pos] != y)
                    y_pos++;

                while (preferences[u][partner_pos] != u_partner)
                    partner_pos++;

                if (y_pos < partner_pos) {
                    cnt++;
                    break;
                }
            }
        }

        return cnt;
    }
};