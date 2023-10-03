class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        /*
        // use row / col sets to determine the ro / col need to be zero or not
        // TC: O(m * n)
        // SC: O(m + n)
        unordered_set<int> rowSet, colSet;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rowSet.insert(i);
                    colSet.insert(j);
                }
            }
        }

        // row set
        for (auto const& row : rowSet) {
            for (int i = 0; i < n; i++) {
                matrix[row][i] = 0;
            }
        }
        
        // col set
        for (auto const& col : colSet) {
            for (int i = 0; i < m; i++) {
                matrix[i][col] = 0;
            }
        }
        */

        // Best
        // TC: O(m * n)
        // SC: O(1)
        bool isZeroRow = false;
        bool isZeroCol = false;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                isZeroRow = true;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (matrix[0][i] == 0) {
                isZeroCol = true;
                break;
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // handle
        if (isZeroRow) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }

        if (isZeroCol) {
            for (int i = 0; i < n; i++) {
                matrix[0][i] = 0;
            }
        }
    }
};