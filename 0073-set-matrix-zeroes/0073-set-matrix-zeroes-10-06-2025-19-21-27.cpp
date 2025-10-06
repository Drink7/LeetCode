class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // make row = 0, col = 0 as memory
        // if row = 1 ~ matrix.size() == 0
        // if col = 1 ~ matrix[0].size() == 0
        // matrix[0][col] = 0
        // matrix[row][0] = 0
        // TC: O(m * n)
        // SC: O(1)

        int m = matrix.size();
        int n = matrix[0].size();

        // check [0][0] - [i][0]
        // check [0][0] - [0][j]
        bool allRowZero = false;
        bool allColZero = false;

        for (int i = 0; i < n; i++) {
            if (matrix[0][i] == 0) {
                allColZero = true;
            }
        }

        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                allRowZero = true;
            }
        }

        // check internal
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // set matrix zeros
        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int i = 1; i < n; i++) {
            if (matrix[0][i] == 0) {
                for (int j = 1; j < m; j++) {
                    matrix[j][i] = 0;
                }
            }
        }

        if (allColZero) {
            for (int i = 0; i < n; i++) {
                matrix[0][i] = 0;
            }
        }

        if (allRowZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};