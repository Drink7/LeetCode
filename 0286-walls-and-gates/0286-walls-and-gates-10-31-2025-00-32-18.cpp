class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        // start from all gates (nearest)
        // bfs, with visited concept, if visited, fill with -1
        // TC: O(m * n)
        // SC: O(1)
        int dRow[4] = {-1, 0, 1, 0};
        int dCol[4] = {0, -1, 0, 1};
        queue<pair<int, int>> q; // row, col
        
        int m = rooms.size();
        int n = rooms[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        // multiple start point bfs
        while (q.size() > 0) {
            int qSize = q.size();

            for (int i = 0; i < qSize; i++) {
                auto [row, col] = q.front();
                q.pop();

                // go four directions
                for (int j = 0; j < 4; j++) {
                    int newRow = row + dRow[j];
                    int newCol = col + dCol[j];
                    if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || rooms[newRow][newCol] != INT_MAX) {
                        continue;
                    }

                    rooms[newRow][newCol] = rooms[row][col] + 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }
};