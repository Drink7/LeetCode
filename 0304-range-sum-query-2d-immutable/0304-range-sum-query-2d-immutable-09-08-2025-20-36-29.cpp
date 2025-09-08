class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        for (auto const& row : matrix) {
            prefixSumMatrix.push_back(row);
        }

        // prefixSum
        for (auto & row : prefixSumMatrix) {
            for (int i = 1; i < row.size(); i++) {
                row[i] += row[i - 1];
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        if (col1  > 0) {
            for (int i = row1; i <= row2; i++) {
                sum += prefixSumMatrix[i][col2] - prefixSumMatrix[i][col1 - 1];
            }
        } else {
            for (int i = row1; i <= row2; i++) {
                sum += prefixSumMatrix[i][col2];
            }
        }
        return sum;
    }

private:
    vector<vector<int>> prefixSumMatrix;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */