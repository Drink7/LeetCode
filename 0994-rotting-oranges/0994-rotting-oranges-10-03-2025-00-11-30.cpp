class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // start from rotten
        // multi-source BFS
        // check fresh count, if there is any fresh, -1
        // else return minimum
        // TC: O(m * n)
        // SC: O(1)
        int fresh = 0;
        int m = grid.size();
        int n = grid[0].size();
        int dRow[4] = {-1, 0, 1, 0};
        int dCol[4] = {0, -1, 0, 1};
        queue<pair<int, int>> q;

        // check fresh and rotten
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int steps = 0;
        while (fresh > 0 && q.size() > 0) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                auto [row, col] = q.front();
                q.pop();

                for (int j = 0; j < 4; j++) {
                    int newRow = row + dRow[j];
                    int newCol = col + dCol[j];
                    if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || grid[newRow][newCol] != 1) {
                        continue;
                    }
                    q.push({newRow, newCol});
                    grid[newRow][newCol] = 2;
                    fresh--;
                }
            }
            steps++;
        }

        if (fresh == 0) {
            return steps;
        } else {
            return -1;
        }
    }
};