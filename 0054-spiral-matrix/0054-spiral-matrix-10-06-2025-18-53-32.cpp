class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // use top / right / down / left
        // if top > down, break
        // if left > right, break
        // TC: O(m * n)
        // SC: O(m * n)
        int top = 0;
        int down = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        vector<int> result;

        while (top <= down && left <= right) {
            // top
            for (int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }
            top++;

            // right
            for (int i = top; i <= down; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;

            if (top > down || left > right) {
                break;
            }

            // down
            for (int i = right; i >= left; i--) {
                result.push_back(matrix[down][i]);
            }
            down--;

            // left
            for (int i = down; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
        return result;
    }
};