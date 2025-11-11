class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // binary search
        // for row, we need to find the first smaller or equal than mid
        // (the first > x) - 1
        // TC: O(log m * log n)
        // SC: O(1)
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = m;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (matrix[mid][0] <= target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        // search on the low row
        int row = low - 1;

        if (row < 0) return false;

        low = 0;
        high = n;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (matrix[row][mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        if (low < n && matrix[row][low] == target) {
            return true;
        } else {
            return false;
        }
    }
};