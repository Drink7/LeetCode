class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // dfs outer cycle
        // TC: O(m * n)
        // SC: O(1)
        int m = board.size();
        int n = board[0].size();
        // top, down
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') {
                dfs(board, 0, i);
            }

            if (board[m - 1][i] == 'O') {
                dfs(board, m - 1, i);
            }
        }

        // left, right
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }

            if (board[i][n - 1] == 'O') {
                dfs(board, i, n - 1);
            }
        }

        // transfer O to X
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

        // transfer # to O
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int row, int col) {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() ||
            board[row][col] == 'X' || board[row][col] == '#') {
            return;
        }

        board[row][col] = '#';

        for (int i = 0; i < 4; i++) {
            dfs(board, row + dRow[i], col + dCol[i]);
        }
    }
private:
    int dRow[4] = {-1, 0, 1, 0};
    int dCol[4] = {0, -1, 0, 1};
};