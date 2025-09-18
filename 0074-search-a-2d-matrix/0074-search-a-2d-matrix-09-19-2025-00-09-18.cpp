class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // binary search row and col
        // row -> find the last <= target
        // TC: O(logm * log n)
        // SC: O(1)
        int low = 0;
        int high = matrix.size() - 1;
        int row = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[mid][0] <= target) {
                if (mid == matrix.size() - 1 || matrix[mid + 1][0] > target) {
                    row = mid;
                    break;
                } else {
                    low = mid + 1;
                }
            } else {
                high = mid - 1;
            }
        }

        // binary search row
        low = 0;
        high = matrix[0].size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
};