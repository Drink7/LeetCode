class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // use bfs to fill with color
        // TC: O(m * n)
        // SC: O(m * n)
        int m = image.size();
        int n = image[0].size();

        queue<pair<int, int>> q;
        int dRow[4] = {-1, 0, 1, 0};
        int dCol[4] = {0, -1, 0, 1};

        q.push({sr, sc});
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            int rcColor = image[r][c];

            for (int i = 0; i < 4; i++) {
                int newRow = r + dRow[i];
                int newCol = c + dCol[i];

                if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || image[newRow][newCol] == -1) {
                    continue;
                } else {
                    if (image[newRow][newCol] == rcColor) {
                        q.push({newRow, newCol});
                    }
                }
            }

            image[r][c] = -1;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (image[i][j] == -1) {
                    image[i][j] = color;
                }
            }
        }

        return image;
    }
};