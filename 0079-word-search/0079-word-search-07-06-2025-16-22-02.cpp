class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // dfs walk up down left right
        // if exist,stop explore
        // TC: O(m * n * k), k is word size
        // SC: O(1)
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    explorer(board, word, i, j, 0);
                }

                if (isExist) {
                    return true;
                }
            }
        }
        return false;
    }

    void explorer(vector<vector<char>>& board, string word, int row, int col, int start) {
        if (row < 0 ||
            col < 0 ||
            row >= board.size() ||
            col >= board[0].size() ||
            board[row][col] == '-' ||
            board[row][col] != word[start]) {
            return;
        }

        if (start == word.size() - 1) {
            isExist = true;
            return;
        }

        char tmp = board[row][col];
        board[row][col] = '-';

        for (int i = 0; i < 4; i++) {
            explorer(board, word, row + dx[i], col + dy[i], start + 1);
        }

        board[row][col] = tmp;
    }
private:
    bool isExist = false;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
};