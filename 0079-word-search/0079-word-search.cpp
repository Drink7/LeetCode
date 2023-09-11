class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // DFS
        // TC: O(m * n)
        // SC: O(1)
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    bool isExist = dfs(board, word, i, j, 0);
                    if (isExist) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int row, int col, int curIndex) {
        if (curIndex == word.size()) {
            return true;
        }

        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()
            || board[row][col] != word[curIndex]) {
            return false;
        }

        char tmp = board[row][col];
        board[row][col] = '#';
        bool isExisted = false;
        for (int i = 0; i < 4; i++) {
            isExisted |= dfs(board, word, row + dRow[i], col + dCol[i], curIndex + 1);
        }
        board[row][col] = tmp;
        return isExisted;
    }
private:
    int dRow[4] = {0, 1, 0, -1};
    int dCol[4] = {1, 0, -1, 0};
};