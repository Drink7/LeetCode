class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // dfs
        // TC: O(m * n)
        // SC: O(1)
        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    dfs(grid, i, j, area);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }

    void dfs(vector<vector<int>>& grid, int row, int col, int& area) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0) {
            return;
        }

        area++;
        grid[row][col] = 0;
        for (int i = 0; i < 4; i++) {
            dfs(grid, row + dRow[i], col + dCol[i], area);
        }

    }
private:
    int dRow[4] = {-1, 0, 1, 0};
    int dCol[4] = {0, -1, 0, 1};
};