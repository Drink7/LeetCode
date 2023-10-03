class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
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

    }
};