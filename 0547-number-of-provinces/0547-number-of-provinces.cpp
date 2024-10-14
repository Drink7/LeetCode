class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // union find
        // TC: O(m * n), m nodes with n edges
        // SC: O(m)
        int m = isConnected.size();
        int n = isConnected[0].size();
        int result = m;
        parent.resize(m, 0);
        rank.resize(m, 0);
        for (int i = 0; i < m; i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        // traverse
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    unionHelper(i, j, result);
                }
            }
        }
        return result;
    }

    void unionHelper(int x, int y, int& result) {
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
        result--;
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
};