class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // use the board row[9][9] represent ith row has fill number or not, it is a 2D boolean vector
        // use the board col[9][9] represent ith row has fill number or not, it is a 2D boolean vector
        // use the submatrix[9][9] for the submatrix
        // TC: O(9 * 9)
        // SC: O(9 * 9)
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> subMat(9, vector<bool>(9, false));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (isdigit(board[i][j])) {
                    int num = board[i][j] - '1';
                    int subMatIndex = (i / 3) * 3 + j / 3;
                    if (row[i][num] || col[j][num] || subMat[subMatIndex][num]) {
                        return false;
                    }
                    row[i][num] = true;
                    col[j][num] = true;
                    subMat[subMatIndex][num] = true;
                }
            }
        }

        return true;
    }
};