class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        /*
        // DFS with 4 directions
        // TC: O(m * n)
        // SC: O(m * n)
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
        */
        // union find
        // TC: O(m * n)
        // SC: O(m * n)
        int m = grid.size();
        int n = grid[0].size();
        parent.resize(m * n);
        rank.resize(m * n);

        for (int i = 0; i < m * n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        int lands = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    lands++;
                    // check actual lands after union find
                    // find up
                    if (i > 0 && grid[i - 1][j] == '1') {
                        unionHelper(i * n + j, (i - 1) * n + j, lands);
                    }
                    // find left
                    if (j > 0 && grid[i][j - 1] == '1') {
                        unionHelper(i * n + j, i * n + (j - 1), lands);
                    }
                }
            }
        }
        return lands;
    }

    void unionHelper(int x, int y, int& lands) {
        int rootX = findHelper(x);
        int rootY = findHelper(y);
        if (rootX == rootY) {
            return;
        }

        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        lands--;
    }

    int findHelper(int x) {
        if (parent[x] != x) {
            parent[x] = findHelper(parent[x]);
        }
        return parent[x];
    }

    /*
    void dfs(vector<vector<char>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '0') {
            return;
        }
        grid[row][col] = '0';
        for (int i = 0; i < 4; i++) {
            dfs(grid, row + dRow[i], col + dCol[i]);
        }
    }
    */

private:
    //int dRow[4] = {-1, 0, 1, 0};
    //int dCol[4] = {0, -1, 0, 1};
    vector<int> parent;
    vector<int> rank;
};