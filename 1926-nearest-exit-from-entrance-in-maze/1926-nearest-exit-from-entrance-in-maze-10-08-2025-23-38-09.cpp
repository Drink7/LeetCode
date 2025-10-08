class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        // shortest path -> BFS
        // visited -> +
        // end condition -> next col == 0 || next row == 0, and not wall
        // TC: O(m * n)
        // SC: O(1)
        int m = maze.size();
        int n = maze[0].size();
        int dRow[4] = {-1, 0, 1, 0};
        int dCol[4] = {0, -1, 0, 1};
        int steps = 0;
        queue<pair<int, int>> q; // pos
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '-';

        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                auto [row, col] = q.front();
                q.pop();

                // end, entrance can not be exit
                if (maze[row][col] != '-' && (row == 0 || col == 0 || row == m - 1 || col == n - 1)) {
                    return steps;
                }

                // go up / left / dow / right
                for (int j = 0; j < 4; j++) {
                    int newRow = row + dRow[j];
                    int newCol = col + dCol[j];

                    if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || maze[newRow][newCol] == '+' || maze[newRow][newCol] == '-') {
                        continue;
                    }
                    q.push({newRow, newCol});
                    maze[newRow][newCol] = '+';
                }
            }
            steps++;
        }
        return -1;
    }
};