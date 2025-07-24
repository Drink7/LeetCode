class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // bfs
        // each step find the minimum
        // if the minimum > our time, update our time
        // else keep going
        // TC: O(n * n)
        // SC: O(1)
        int n = grid.size();
        queue<pair<int, int>> q;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({{grid[0][0], 0, 0}});
        grid[0][0] = -1;

        while (!minHeap.empty()) {
            vector<int> minPath = minHeap.top();
            minHeap.pop();

            int time = minPath[0];
            int row = minPath[1];
            int col = minPath[2];

            if (row == n - 1 && col == n - 1) {
                return time;
            }

            // check for next cell
            for (int i = 0; i < 4; i++) {
                int newRow = row + dRow[i];
                int newCol = col + dCol[i];

                if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= n || grid[newRow][newCol] == -1) {
                    continue;
                }

                minHeap.push({max(time, grid[newRow][newCol]), newRow, newCol});
                grid[newRow][newCol] = -1;
            }
        }
        return -1; // impossible
    }
private:
    int dRow[4] = {-1, 0, 1, 0};
    int dCol[4] = {0, -1, 0, 1};
};