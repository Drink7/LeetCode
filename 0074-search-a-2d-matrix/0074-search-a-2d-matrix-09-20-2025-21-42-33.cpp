class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Find row then find col
        // TC: O(logm + logn)
        // SC: O(1)
        int left = 0;
        int right = matrix.size() - 1;
        int row = findRow(matrix, left, right, target);
        if (row == -1) {
            return false;
        } else {
            left = 0;
            right = matrix[0].size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (matrix[row][mid] == target) {
                    return true;
                } else if (matrix[row][mid] > target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return false;
        }
    }

    int findRow(vector<vector<int>>& matrix, int l, int r, int target) {
        int left = l;
        int right = r;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // find the last smaller or equal to target
            if (matrix[mid][0] <= target) {
                if (mid == matrix.size() - 1 || matrix[mid + 1][0] > target) {
                    return mid;
                } else {
                    left = mid + 1;
                }
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};