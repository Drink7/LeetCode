class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // use bfs to fill with color
        // TC: O(m * n)
        // SC: O(m * n)
        int m = image.size();
        int n = image[0].size();
        queue<pair<int, int>> bfsQ;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int dRow[4] = {-1, 0, 1, 0};
        int dCol[4] = {0, -1, 0, 1};

        bfsQ.push({sr, sc});
        while (!bfsQ.empty()) {
            auto [r, c] = bfsQ.front();
            bfsQ.pop();

            for (int i = 0; i < 4; i++) {
                int newRow = r + dRow[i];
                int newCol = c + dCol[i];

                if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n ||
                    visited[newRow][newCol] || image[newRow][newCol] != image[r][c]) {
                    continue;
                }
                visited[newRow][newCol] = true;
                bfsQ.push({newRow, newCol});
            }

            image[r][c] = color;
        }
        return image;
    }
};