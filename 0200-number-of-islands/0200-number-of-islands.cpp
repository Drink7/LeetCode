class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // union find
        // TC: O(n)
        // SC: O(n)
        int m = grid.size();
        int n = grid[0].size();
        parent.resize(m * n);
        rank.resize(m * n);
        for (int i = 0; i < m * n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    island++;
                    if (i > 0 && grid[i - 1][j] == '1') {
                        unionHelper((i - 1) * n + j, i * n + j);
                    }

                    if (j > 0 && grid[i][j - 1] == '1') {
                        unionHelper(i * n + j - 1, i * n + j);
                    }
                }
            }
        }
        return island;
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
        island--;
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
    int island = 0;
};