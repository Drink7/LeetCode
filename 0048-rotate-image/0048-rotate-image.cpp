class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Reverse then swap
        // TC: O(m * n)
        // SC: O(1)
        int n = matrix.size();

        // reverse
        reverse(matrix.begin(), matrix.end());

        // swap symmetry
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};