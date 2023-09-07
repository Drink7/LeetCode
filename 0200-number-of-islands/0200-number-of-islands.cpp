class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // use union find
        // traverse each grid, check the top and left side
        // if top and left side is 1 too, union them
        // TC: O(m * n)
        // SC: O(1)
        int m = grid.size();
        int n = grid[0].size();
        parent.resize(m * n);
        rank.resize(m * n);

        // init
        for (int i = 0; i < m * n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    lands++;

                    // union
                    if (i - 1 >= 0 && grid[i - 1][j] == '1') {
                        unionHelper(i * n + j, (i - 1) * n + j);
                    }

                    if (j - 1 >= 0 && grid[i][j - 1] == '1') {
                        unionHelper(i * n + j, i * n + j - 1);
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