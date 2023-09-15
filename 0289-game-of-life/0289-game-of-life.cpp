class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        /*
        // copy a board and calculate the next state using the copy board
        // TC: O(mn)
        // SC: O(mn)
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> copyBoard(m, vector<int>(n, 0));

        // copy
        for (int i = 0; i < m; i++) {
            copyBoard[i] = board[i];
        }

        // calculate
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                lifeHelper(i, j, copyBoard, board);
            }
        }
        */
        // if the grid is live, the grid would need to +2
        // else, do nothing
        // when judging around, we need to % 2
        // after all done, we traverse the board again and /2 each grid
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                check(i, j, board);
            }
        }

        // next
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = board[i][j] / 2;
            }
        }
    }

    void check(int row, int col, vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        int liveCnt = 0;

        for (int i = 0; i < 8; i++) {
            int newRow = row + dRow[i];
            int newCol = col + dCol[i];
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && board[newRow][newCol] % 2 == 1) {
                liveCnt++;
            }
        }

        if (board[row][col] == 1) {
            if (liveCnt == 2 || liveCnt == 3) {
                board[row][col] += 2;
            } 
        } else {
            // Rule 4
            if (liveCnt == 3) {
                board[row][col] += 2;
            }
        }
    }

    void lifeHelper(int row, int col, vector<vector<int>>& board, vector<vector<int>>& result) {
        int m = board.size();
        int n = board[0].size();
        int liveCnt = 0;

        for (int i = 0; i < 8; i++) {
            int newRow = row + dRow[i];
            int newCol = col + dCol[i];
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && board[newRow][newCol] == 1) {
                liveCnt++;
            }
        }

        if (board[row][col] == 1) {
            if (liveCnt < 2) {
                result[row][col] = 0;
            } else if (liveCnt == 2 || liveCnt == 3) {
                result[row][col] = 1;
            } else {
                result[row][col] = 0;
            }
        } else {
            // Rule 4
            if (liveCnt == 3) {
                // reborn
                result[row][col] = 1;
            }
        }
    }

private:
    int dRow[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dCol[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
};