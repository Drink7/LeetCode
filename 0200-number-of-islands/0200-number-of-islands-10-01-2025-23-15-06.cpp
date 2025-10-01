class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // check DFS count
        // TC: O(m * n)
        // SC: O(1)
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
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
    int dRow[4] = {-1, 0, 1, 0};
    int dCol[4] = {0, -1, 0, 1};
};