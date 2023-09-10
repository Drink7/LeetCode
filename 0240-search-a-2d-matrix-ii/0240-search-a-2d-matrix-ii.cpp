class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
        // search the target by row
        // each row would use binary search
        // TC: O(m * log n)
        // SC: O(1)
        int row = matrix.size();
        int col = matrix[0].size();
        for (int i = 0; i < row; i++) {
            int left = 0;
            int right = col - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (matrix[i][mid] == target) {
                    return true;
                } else if (matrix[i][mid] > target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return false;
        */

        // checking top-right
        // if target > top-right
        // no need to check the top row, row = row - 1
        // if target < top-right
        // no need to check the last col, col = col - 1
        // TC: O(m * n)
        // SC: O(1)
        int row = matrix.size();
        int col = matrix[0].size();
        int curRow = 0;
        int curCol = col - 1;
        while (curRow < row && curCol >= 0) {
            if (matrix[curRow][curCol] == target) {
                return true;
            } else if (matrix[curRow][curCol] < target) {
                curRow++;
            } else {
                curCol--;
            }
        }
        return false;
    }
};