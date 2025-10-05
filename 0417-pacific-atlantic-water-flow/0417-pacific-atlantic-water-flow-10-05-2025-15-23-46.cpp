class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // dfs go from edges, only go if next grid higher than current
        // we use two vector<vector<bool>> pac, vector<vector<bool>> atl
        // check overlap
        // TC: O(m * n)
        // SC: O(m * n)
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));
        vector<vector<int>> result;

        for (int i = 0; i < m; i++) {
            dfs(heights, pac, i, 0, -1);
            dfs(heights, atl, i, n - 1, -1);
        }

        for (int i = 0; i < n; i++) {
            dfs(heights, pac, 0, i, -1);
            dfs(heights, atl, m - 1, i, -1);
        }

        // overlap
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && atl[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& board, int row, int col, int prev) {
        if (row < 0 || row >= heights.size() || col < 0 || col >= heights[0].size() || board[row][col] || prev > heights[row][col]) {
            return;
        }

        board[row][col] = true;

        for (int i = 0; i < 4; i++) {
            dfs(heights, board, row + dRow[i], col + dCol[i], heights[row][col]);
        }
    }
private:
    int dRow[4] = {-1, 0, 1, 0};
    int dCol[4] = {0, -1, 0, 1};
};