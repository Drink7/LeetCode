class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        // find a rectangle
        // The input is generated such that there is at least one 1 in grid.
        // row find 1
        // col find 1
        // two pointers
        // TC: O(m * n)
        // SC: O(m + n)
        int m = grid.size();
        int n = grid[0].size();
        vector<bool> row(m, false);
        vector<bool> col(n, false);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        // find height
        int left_row = 0;
        int right_row = m - 1;
        while (row[left_row] != true) {
            left_row++;
        }

        while (row[right_row] != true) {
            right_row--;
        }

        // find width
        int left_col = 0;
        int right_col = n - 1;
        while (col[left_col] != true) {
            left_col++;
        }

        while (col[right_col] != true) {
            right_col--;
        }

        return (right_row - left_row + 1) * (right_col - left_col + 1);
    }
};