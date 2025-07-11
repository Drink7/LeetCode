class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // Use Union find (2d union find, use total islands as count, when union, count--)
        // TC: O(mn)
        // SC: O(mn)
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m * n; i++) {
            parent.push_back(i);
            rank.push_back(1);
        }

        // union-find
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    island++;
                    // union top
                    if (i - 1 >= 0 && grid[i - 1][j] == '1') {
                        unionHelper(i * n + j, (i - 1)  * n + j);
                    }

                    // union left
                    if (j - 1 >= 0 && grid[i][j - 1] == '1') {
                        unionHelper(i * n + j, i * n + (j - 1));
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