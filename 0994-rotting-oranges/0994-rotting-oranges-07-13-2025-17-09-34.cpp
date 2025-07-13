class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Suggest use BFS
        // TC: O(m*n)
        // SC: O(m*n)
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        int time = 0;
        queue<pair<int, int>> rottenQueue;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    rottenQueue.push({i, j});
                }
            }
        }

        // start bfs
        while (rottenQueue.size() > 0 && fresh > 0) {
            int curSize = rottenQueue.size();
            for (int i = 0; i < curSize; i++) {
                pair<int, int> rotten = rottenQueue.front();
                rottenQueue.pop();
                for (int i = 0; i < 4; i++) {
                    int newRow = rotten.first + dRow[i];
                    int newCol = rotten.second + dCol[i];
                    if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || grid[newRow][newCol] != 1) {
                        continue;
                    }
                    grid[newRow][newCol] = 2;
                    rottenQueue.push({newRow, newCol});
                    fresh--;
                }
            }
            time++;
        }

        if (fresh == 0) {
            return time;
        } else {
            return -1;
        }
    }

private:
    int dRow[4] = {1, 0, -1, 0};
    int dCol[4] = {0, 1, 0, -1};
};