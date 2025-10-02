class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // multi-source BFS for edges
        // TC: O(m * n)
        // SC: O(m + n)
        int dRow[4] = {-1, 0, 1, 0};
        int dCol[4] = {0, -1, 0, 1};
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') {
                q.push({0, i});
                board[0][i] = 'A';
            }

            if (board[m - 1][i] == 'O') {
                q.push({m - 1, i});
                board[m - 1][i] = 'A';
            }
        }

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
                board[i][0] = 'A';
            }

            if (board[i][n - 1] == 'O') {
                q.push({i, n - 1});
                board[i][n - 1] = 'A';
            }
        }

        while(q.size() > 0) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                auto [row, col] = q.front();
                q.pop();

                for (int j = 0; j < 4; j++) {
                    int newRow = row + dRow[j];
                    int newCol = col + dCol[j];
                    if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || board[newRow][newCol] != 'O') {
                        continue;
                    }
                    board[newRow][newCol] = 'A';
                    q.push({newRow, newCol});
                }
            }
        }

        // refresh

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};