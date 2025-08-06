class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // visited = -101
        // right - 0, down - 1, left - 2, up - 3
        // TC: O(m * n)
        // SC: O(1)
        int m = matrix.size();
        int n = matrix[0].size();
        int direction = 0;
        vector<int> result;
        int totalElement = m * n;
        int visited = 0;

        // start from 0, 0
        int row = 0;
        int col = -1;
        while (visited < totalElement) {
            if (changeDirection(matrix, row, col, direction)) {
                direction = (direction + 1) % 4;
            }

            row += dRow[direction];
            col += dCol[direction];

            visited++;
            result.push_back(matrix[row][col]);
            matrix[row][col] = -101;
        }
        return result;
    }

    bool changeDirection(vector<vector<int>>& matrix, int row, int col, int direction) {
        row += dRow[direction];
        col += dCol[direction];

        if (row < 0 || row >= matrix.size() || col < 0 || col >= matrix[0].size() ||
            matrix[row][col] == -101) {
            return true;
        }
        return false;
    }

private:
    int dRow[4] = {0, 1, 0, -1};
    int dCol[4] = {1, 0, -1, 0};
};