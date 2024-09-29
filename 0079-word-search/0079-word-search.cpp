class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // dfs
        // TC: O(m * n * 4^L)
        // SC: O(L)
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, word, i, j, 0);
            }
        }
        return isExist;
    }

    void dfs(vector<vector<char>>& board, string& word, int row, int col, int index) {
        if (index == word.size()) {
            isExist = true;
            return;
        }

        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() ||
            board[row][col] == '*' || board[row][col] != word[index]) {
            return;
        }

        char tmp = board[row][col];
        board[row][col] = '*';
        for (int i = 0; i < 4; i++) {
            dfs(board, word, row + dRow[i], col + dCol[i], index + 1);
        }
        board[row][col] = tmp;
    }
private:
    bool isExist = false;
    int dRow[4] = {-1, 0, 1, 0};
    int dCol[4] = {0, -1, 0, 1};
};