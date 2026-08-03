class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // brute force
        // check every non '.'
        // TC: O(9 * 9 * 9 * 9 * 9)
        // SC: O(1)
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (!isValid(board, i, j)) {
                    return false;
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