class NumMatrix {
public:
    vector<vector<int>> preSum;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        preSum.resize(m, vector<int>(n));
        preSum[0][0] = matrix[0][0];

        for(int j = 1; j < n; j++) preSum[0][j] = preSum[0][j - 1] + matrix[0][j];
        for(int i = 1; i < m; i++) preSum[i][0] = preSum[i - 1][0] + matrix[i][0];

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                preSum[i][j] = matrix[i][j] + preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int result = preSum[row2][col2];

        if(row1 > 0) result -= preSum[row1 - 1][col2];
        if(col1 > 0) result -= preSum[row2][col1 - 1];
        if(row1 > 0 && col1 > 0) result += preSum[row1 - 1][col1 - 1];

        return result;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */