class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // recursive traverse
        // TC: O(m * n)
        // SC: O(1)
        vector<int> result;
        int dir = 0; // 0: right, 1: down, 2: left, 3: up
        traverse(matrix, dir, result, 0, 0);
        return result;
    }

    void traverse(vector<vector<int>>& matrix, int dir, vector<int>& result, int row, int col) {
        int m = matrix.size();
        int n = matrix[0].size();

        result.push_back(matrix[row][col]);
        matrix[row][col] = -200;

        if (result.size() == m * n) {
            return;
        }

        int newRow = row + dRow[dir];
        int newCol = col + dCol[dir];
        while (isDirNeedChange(matrix, newRow, newCol)) {
            dir = (dir + 1) % 4;
            newRow = row + dRow[dir];
            newCol = col + dCol[dir];
        }

        traverse(matrix, dir, result, newRow, newCol);
    }

    bool isDirNeedChange(vector<vector<int>>& matrix, int row, int col) {
        if (row < 0 || row >= matrix.size() || col < 0 || col >= matrix[0].size() || matrix[row][col] == -200) {
            return true;
        } else {
            return false;
        }
    }

private:
    int dRow[4] = {0, 1, 0, -1};
    int dCol[4] = {1, 0, -1, 0};
};