class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // tree can not be connected
        // use DSU to find if it is connected
        // also check the n == 1
        // TC: O(E + V)
        // SC: O(V)
        rank.resize(n, 0);
        parent.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // start DSU
        int cnt = n;
        for (auto const& edge : edges) {
            if (!unionHelper(edge[0], edge[1], cnt)) {
                return false;
            }
        }

        return cnt == 1? true : false;
    }

    bool unionHelper(int x, int y, int& cnt) {
        int rootX = findHelper(x);
        int rootY = findHelper(y);

        if (rootX == rootY) {
            return false;
        }

        cnt--;

        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
     }

    int findHelper(int x) {
        if (parent[x] != x) {
            parent[x] = findHelper(parent[x]);
        }
        return parent[x];
    }
private:
    vector<int> rank;
    vector<int> parent;
};