class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // Traverse
        // TC: O(n^2)
        // SC; O(n)
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++) {
            result.push_back(vector<int>(i + 1, 1));
        }

        // calculate pascal's triangle
        for (int i = 2; i < numRows; i++) {
            for (int j = 1; j < result[i].size() - 1; j++) {
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
            }
        }
        return result;
    }
};