class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // BFS
        // TC: O(m*n)
        // SC: O(m*n)
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        queue<pair<int, int>> bfsQueue;
        bfsQueue.push({sr, sc});
        while (bfsQueue.size() > 0) {
            int curSize = bfsQueue.size();
            for (int i = 0; i < curSize; i++) {
                pair<int, int> grid = bfsQueue.front();
                int row = grid.first;
                int col = grid.second;
                bfsQueue.pop();
                for (int j = 0; j < 4; j++) {
                    int newRow = row + dRow[j];
                    int newCol = col + dCol[j];
                    if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || visited[newRow][newCol] || image[row][col] != image[newRow][newCol]) {
                        continue;
                    }
                    bfsQueue.push({newRow, newCol});
                }
                visited[row][col] = true;
                image[row][col] = color;
            }
        }
        return image;
    }
private:
    int dRow[4] = {1, 0, -1, 0};
    int dCol[4] = {0, 1, 0, -1};
};