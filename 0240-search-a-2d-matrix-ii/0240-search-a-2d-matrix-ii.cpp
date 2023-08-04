class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Binary Search way
        // TC: O(mlogn)
        // SC: O(1)
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] <= target) {
                int left = 0;
                int right = n - 1;
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
            } else {
                break;
            }
        }
        return false;
    }
};