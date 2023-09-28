class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // DFS
        // TC: O(m*n)
        // SC: O(1)
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() ||
            col < 0 || col >= grid[0].size() ||
            grid[row][col] != '1') {
                return;
            }
        
        grid[row][col] = '0';
        int dRow[4] = {-1, 0, 1, 0};
        int dCol[4] = {0, -1, 0, 1};
        for (int i = 0; i < 4; i++) {
            dfs(grid, row + dRow[i], col + dCol[i]);
        }
    }
};