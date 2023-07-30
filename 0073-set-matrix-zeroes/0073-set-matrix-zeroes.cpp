class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Store the row and col
        // Check if the row or col need to be set to zero
        // TC: O(mn)
        // SC: O(m + n)
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> rowSet(m, false);
        vector<bool> colSet(n, false);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rowSet[i] = true;
                    colSet[j] = true;
                }
            }
        }

        // set zeros
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rowSet[i] || colSet[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};