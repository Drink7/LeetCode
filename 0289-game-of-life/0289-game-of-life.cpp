class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
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