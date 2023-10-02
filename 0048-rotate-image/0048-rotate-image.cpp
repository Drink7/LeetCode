class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Reverse then swap
        // TC: O(m * n)
        // SC: O(1)
        int m = matrix.size();
        int n = matrix[0].size();

        // reverse
        for (int i = 0; i < m; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }

        // swap diagnol
        int diagnol = n;
        for (int i = 0; i < n - 1; i++) {
            diagnol = diagnol - 1;
            for (int j = 0; j < diagnol; j++) {
                swap(matrix[i][j], matrix[m - j - 1][n - i - 1]);
            }
        }
    }
};