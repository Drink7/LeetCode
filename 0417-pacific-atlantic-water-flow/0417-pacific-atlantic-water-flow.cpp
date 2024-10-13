class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // TC: O(m * n)
        // SC: O(m * n)
        // start pacific ocean first, then atlantic ocean next
        // if next value >= prev, available
        // if next value < prev, can not go through
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));
        vector<vector<int>> result;

        // start top, down
        for (int i = 0; i < n; i++) {
            dfs(heights, pac, 0, i, -1);
            dfs(heights, atl, m - 1, i, -1);
        }

        // start left, right
        for (int i = 0; i < m; i++) {
            dfs(heights, pac, i, 0, -1);
            dfs(heights, atl, i, n - 1, -1);
        }

        // check intersection
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && atl[i][j]) {
                    result.push_back({i, j});
                }
            }    
        }
        return result;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int row, int col, int prev) {
        if (row < 0 || row >= heights.size() || col < 0 || col >= heights[0].size()
            || visited[row][col] || heights[row][col] < prev) {
            return;
        }

        visited[row][col] = true;

        for (int i = 0; i < 4; i++) {
            dfs(heights, visited, row + dRow[i], col + dCol[i], heights[row][col]);
        }
    }

private:
    int dRow[4] = {-1, 0, 1, 0};
    int dCol[4] = {0, -1, 0, 1};
};