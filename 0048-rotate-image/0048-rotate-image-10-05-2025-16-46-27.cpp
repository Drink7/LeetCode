class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose then reverse
        // TC: O(m * n)
        // SC: O(m * n)
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse each row
        for (auto& row : matrix) {
            reverse(row.begin(), row.end());
        }
    }
};