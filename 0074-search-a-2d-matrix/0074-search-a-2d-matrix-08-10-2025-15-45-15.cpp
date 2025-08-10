class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
        // find row => find last <= target
        // find col, fixed row, row[first] row[end] simple binary search
        // TC: O(log m * log n)
        // SC: O(1)
        int m = matrix.size();
        int n = matrix[0].size();

        // find row
        int left = 0;
        int right = matrix.size() - 1;
        int fixedRow = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid][0] == target) {
                return true;
            } else {
                if (matrix[mid][0] <= target) {
                    if (mid == matrix.size() - 1 || matrix[mid + 1][0] > target) {
                        fixedRow = mid;
                        break;
                    } else {
                        left = mid + 1;
                    }
                } else {
                    right = mid - 1;
                }
            }
        }

        // find col

        left = 0;
        right = matrix[0].size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[fixedRow][mid] == target) {
                return true;
            } else if (matrix[fixedRow][mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
        */
        int row = 0;
        int col = matrix[0].size() - 1;
        while (row < matrix.size() && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                row++;
            } else {
                col--;
            }
        }
        return false;
    }
};