class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        // brute-force
        // TC: O(2^12)
        // check row i has cell = 1 or not
        // if not, covered
        // else, check is for each cell = 1, which col j is selected
        // col -> choose, not choose
        unordered_set<int> colSet;
        int maxVal = 0;
        helper(matrix, numSelect, 0, colSet, maxVal);
        return maxVal;
    }

    void helper(vector<vector<int>>& matrix, int numSelect, int col, unordered_set<int>& colSet, int& maxVal) {
        if (col >= matrix[0].size()) {
            if (colSet.size() == numSelect) {
                int num = 0;
                for (int i = 0; i < matrix.size(); i++) {
                    bool isCovered = true;
                    for (int j = 0; j < matrix[0].size(); j++) {
                        if (matrix[i][j] == 1 && colSet.count(j) < 1) {
                            isCovered = false;
                            break;
                        }
                    }

                    if (isCovered) {
                        num++;
                    }
                }
                maxVal = max(maxVal, num);
            }
            return;
        }

        // not choose
        helper(matrix, numSelect, col + 1, colSet, maxVal);

        // choose
        colSet.insert(col);
        helper(matrix, numSelect, col + 1, colSet, maxVal);
        colSet.erase(col);
    }
};