class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 9 square
        // TC: (9 * 9 * 9 * (9 * 9))
        // SC: O(1)
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    bool checkBoard = checker(board, i, j);
                    if (!checkBoard) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool checker(vector<vector<char>>& board, int row, int col) {
        // check row
        int cur = board[row][col];
        for (int i = 0; i < 9; i++) {
            if (i == row) {
                continue;
            } else {
                if (board[i][col] == cur) {
                    return false;
                }
            }
        }

        // check col
        for (int i = 0; i < 9; i++) {
            if (i == col) {
                continue;
            } else {
                if (board[row][i] == cur) {
                    return false;
                }
            }
        }

        // check squre
        int subRow = row / 3;
        int subCol = col / 3;
        for (int i = subRow * 3; i < subRow * 3 + 3; i++) {
            for (int j = subCol * 3; j < subCol * 3 + 3; j++) {
                if (i == row && j == col) {
                    continue;
                } else {
                    if (board[i][j] == cur) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};