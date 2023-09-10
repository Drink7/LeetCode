class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // first find the row value which is closet (smaller) to the target
        // then keep the same row, find the value in [0, col - 1] range
        // TC: O(logm + logn)
        // SC: O(1)
        int minRow = findRow(matrix, target);
        if (minRow == -1) {
            return false;
        }
    
        int left = 0;
        int right = matrix[0].size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[minRow][mid] == target) {
                return true;
            } else if (matrix[minRow][mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }

    int findRow(vector<vector<int>>& matrix, int& target) {
        int row = matrix.size();
        int left = 0;
        int right = row - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid][0] <= target) {
                if (mid == right || matrix[mid + 1][0] > target) {
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