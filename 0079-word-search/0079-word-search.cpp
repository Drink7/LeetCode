class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // DFS
        // TC: O(m * n * 4 ^ L)
        // SC: O(L)
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int row, int col, int start) {
        if (start == word.size()) {
            return true;
        }

        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() ||
            board[row][col] == '#' || board[row][col] != word[start]) {
            return false;
        }

        char tmp = board[row][col];
        board[row][col] = '#';
        int dRow[4] = {-1, 0, 1, 0};
        int dCol[4] = {0, -1, 0, 1};
        bool isExist = false;
        for (int i = 0; i < 4; i++) {
            isExist |= dfs(board, word, row + dRow[i], col + dCol[i], start + 1);
        }
        board[row][col] = tmp;
        return isExist;
    }
};