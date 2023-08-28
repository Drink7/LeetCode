class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // Use DFS to traverse all 1's
        // when we have visit 1, change the 1 to 0, so we don't need the visited grid
        // TC: O(mn)
        // SC: O(mn) // recursive depth
        // DFS
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    // start dfs
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '0') {
            return;
        }

        grid[row][col] = '0';
        for (int i = 0; i < 4; i++) {
            dfs(grid, row + dRow[i], col + dCol[i]);
        }
    }
private:
    int dRow[4] = {0, 1, 0, -1};
    int dCol[4] = {1, 0, -1, 0};
};