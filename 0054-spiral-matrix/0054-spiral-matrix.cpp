class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // dir: right, down, left, up
        // TC: O(m * n)
        // SC: O(1)
        vector<int> result;
        int m = matrix.size();
        int n = matrix[0].size();
        int dir = 0; // 0, 1, 2, 3
        int curRow = 0;
        int curCol = 0;
        int visited = 0;
        while (visited < m * n) {
            int element = matrix[curRow][curCol];
            result.push_back(element);
            matrix[curRow][curCol] = -101;

            int nextRow = curRow + dRow[dir];
            int nextCol = curCol + dCol[dir];
            if (nextRow < 0 || nextRow >= m ||
                nextCol < 0 || nextCol >= n ||
                matrix[nextRow][nextCol] == -101) {
                dir = (dir + 1) % 4;
            }

            curRow = curRow + dRow[dir];
            curCol = curCol + dCol[dir];
            visited++;
        }
        return result;
    }
private:
    int dRow[4] = {0, 1, 0, -1};
    int dCol[4] = {1, 0, -1, 0};
};