class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // Go through board
        // use isValid function to check valid
        // backtracking
        // TC: O(n^n*9)
        // SC: O(n^n)
        solver(board);
    }

    bool solver(vector<vector<char>>& board) {       
        int n = board.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    for (int k = 1; k <= 9; k++) {
                        char cur = k + '0';
                        if (!isValid(board, i, j, cur)) {
                            continue;
                        }
                        board[i][j] = cur;
                        if(solver(board)) {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char cur) {
        int n = board.size();
        int groupRowStart = (row / 3) * 3;
        int groupColStart = (col / 3) * 3;

        // check row, fix col
        for (int i = 0; i < n; i++) {
            if (board[i][col] == cur) {
                return false;
            }
        }

        // check col, fix roe
        for (int i = 0; i < n; i++) {
            if (board[row][i] == cur) {
                return false;
            }
        }

        // check group
        for (int i = groupRowStart; i < groupRowStart + 3; i++) {
            for (int j = groupColStart; j < groupColStart + 3; j++) {
                if (board[i][j] == cur) {
                    return false;
                }
            }
        }
        // all pass, true
        return true;
    }
};