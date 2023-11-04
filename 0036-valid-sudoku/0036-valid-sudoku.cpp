class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // TC: O(9*9 + 3*3*3*3)
        // SC: O(1)
        // check row
        int rowArr[10] = {0};
        int colArr[10] = {0};
        int subArr[10] = {0};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                // row check
                if (board[i][j] != '.') {
                    if (rowArr[board[i][j] - '0'] == 1) {
                        return false;
                    } else {
                        rowArr[board[i][j] - '0'] = 1;
                    }
                }

                // col check
                if (board[j][i] != '.') {
                    if (colArr[board[j][i] - '0'] == 1) {
                        return false;
                    } else {
                        colArr[board[j][i] - '0'] = 1;
                    }
                }
            }
            
            // reset
            for (int j = 0; j < 10; j++) {
                rowArr[j] = 0;
                colArr[j] = 0;
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int sub_row = i * 3; sub_row < i * 3 + 3; sub_row++) {
                    for (int sub_col = j * 3; sub_col < j * 3 + 3; sub_col++) {
                        if (board[sub_row][sub_col] != '.') {
                            if (subArr[board[sub_row][sub_col] - '0'] == 1) {
                                return false;
                            } else {
                                subArr[board[sub_row][sub_col] - '0'] = 1;
                            }
                        }
                    }
                }
                // reset
                for (int k = 0; k < 10; k++) {
                    subArr[k] = 0;
                }
            }
        }
        return true;
    }
};