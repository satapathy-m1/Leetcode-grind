class Solution {
public:
int N;
    class DSU {
        public:
        vector<int> rankArr, parent;
        DSU(int n) {
            rankArr.resize(n, 1);
            parent.resize(n);
            for(int i = 0; i < n; i++) parent[i] = i;
        }
        int find(int x) {
            if(parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }
        void unionFunc(int x, int y) {
            int parx = find(x);
            int pary = find(y);
            if(parx == pary) return;
            if(rankArr[parx] < rankArr[pary]) {
                parent[parx] = pary;
            }
            else if(rankArr[pary] < rankArr[parx]) {
                parent[pary] = parx;
            }
            else {
                parent[pary] = parx;
                rankArr[parx]++;
            }
        }
    };

    int kruskal(vector<vector<int>>& edges, int skipEdge, int addEdge) {
        DSU ds(N);
        int mstWt = 0;
        if(addEdge != -1) {
            ds.unionFunc(edges[addEdge][0], edges[addEdge][1]);
            mstWt += edges[addEdge][2];
        }

        for(int i = 0; i < edges.size(); i++) {
            if(skipEdge == i) continue;
            if(ds.find(edges[i][0]) != ds.find(edges[i][1])) {
                ds.unionFunc(edges[i][0], edges[i][1]);
                mstWt += edges[i][2];
            }
        }
        for(int i = 0; i < N; i++) {
            if(ds.find(i) != ds.find(0)) {
                return INT_MAX;
            }
        }
        return mstWt;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        N = n;
        for(int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }
        auto lambda = [&](vector<int>& vec1, vector<int>& vec2){
            return vec1[2] < vec2[2];
        };
        sort(begin(edges), end(edges), lambda);

        int MST_WEIGHT = kruskal(edges, -1, -1);

        vector<int> pcEdges,cEdges;

        for(int i = 0; i < edges.size(); i++) {
            if(kruskal(edges, i, -1) > MST_WEIGHT) {
                cEdges.push_back(edges[i][3]);
            }
            else if(kruskal(edges, -1, i) == MST_WEIGHT) {
                pcEdges.push_back(edges[i][3]);
            }
        }
        return {cEdges, pcEdges};
    }
};