class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        /*
        // brute force
        // check every non '.'
        // TC: O(9 * 9 * 9 * 3)
        // SC: O(1)
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (!isValid(board, i, j)) {
                    return false;
                }
            }
        }
        return true;
        */

        // More elegant
        // TC: O(9 * 9)
        // SC: O(9 * 9 * 3)
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool section[9][9] = {false};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                // if not '.'
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    if (row[i][num]) {
                        return false;
                    }
                    row[i][num] = true;

                    if (col[j][num]) {
                        return false;
                    }
                    col[j][num] = true;

                    int subRow = i / 3;
                    int subCol = j / 3;
                    int subIdx = subRow + subCol * 3;
                    if (section[subIdx][num]) {
                        return false;
                    }
                    section[subIdx][num] = true;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int col) {
        char c = board[row][col];
        if (c == '.') {
            return true;
        }


        // check row
        for (int i = 0; i < 9; i++) {
            if (i == col) continue;
            if (board[row][i] == c) return false;
        }

        // check col
        for (int i = 0; i < 9; i++) {
            if (i == row) continue;
            if (board[i][col] == c) return false;
        }

        // check 9*9
        int small_row = row / 3;
        int small_col = col / 3;
        for (int i = small_row * 3; i < small_row * 3 + 3; i++) {
            for (int j = small_col * 3; j < small_col * 3 + 3; j++) {
                if (i == row && j == col) continue;
                if (board[i][j] == c) {
                    return false;
                }
            }    
        }
        return true;
    }
};