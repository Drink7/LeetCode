class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // traverse outer
        // bfs or dfs, only go bigger than itself
        // visited = 2, go through both pac and atl
        // TC: O(m * n)
        // SC: O(m * n)
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacVisited(m, vector<bool>(n, false));
        vector<vector<bool>> atlVisited(m, vector<bool>(n, false));
        vector<vector<int>> result;

        // go top & down
        for (int i = 0; i < n; i++) {
            dfs(heights, pacVisited, 0, i, -1);
            dfs(heights, atlVisited, m - 1, i, -1);
        }

        // go right & left
        for (int i = 0; i < m; i++) {
            dfs(heights, pacVisited, i, 0, -1);
            dfs(heights, atlVisited, i, n - 1, -1);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacVisited[i][j] && atlVisited[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int row, int col, int prev) {
        if (row < 0 || row >= heights.size() || col < 0 || col >= heights[0].size() || visited[row][col] || prev > heights[row][col]) {
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