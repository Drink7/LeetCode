class Solution {
/*
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
*/
public:
    int numIslands(vector<vector<char>>& grid) {
        // Use Union find (2d union find, use total islands as count, when union, count--)
        // TC: O(mn)
        // SC: O(mn)
        int m = grid.size();
        int n = grid[0].size();
        parent.resize(m*n);
        rank.resize(m*n);
        for (int i = 0; i < m*n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    lands++;
                    // check top
                    if (i - 1 >= 0 && grid[i - 1][j] == '1') {
                        unionHelper((i - 1) * n + j, i * n + j);
                    }

                    // check left
                    if (j - 1 >= 0 && grid[i][j - 1] == '1') {
                        unionHelper(i * n + j - 1, i * n + j);
                    }
                }
            }
        }
        return lands;
    }

    void unionHelper(int x, int y) {
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
private:
    vector<int> parent;
    vector<int> rank;
    int lands = 0;
};