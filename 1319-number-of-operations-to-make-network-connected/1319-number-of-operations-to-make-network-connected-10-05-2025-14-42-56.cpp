class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // connections.size < n - 1, impossible
        // # union duplicate numbers
        // # not connected numbers
        // union duplicate numbers < not connected numbers, impossible
        // not connected numbers is the answer

        // TC: O(E + V)
        // SC: O(V)
        parent.resize(n, 0);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // union
        int cablesDup = 0;
        for (auto const& edge : connections) {
            if (unionHelper(edge[0], edge[1])) {
                n--;
            } else {
                cablesDup++;
            }
        }

        // need n - 1 cables
        if (cablesDup >= n - 1) {
            return n - 1;
        } else {
            return -1;
        }
    }

    bool unionHelper(int x, int y) {
        int rootX = findHelper(x);
        int rootY = findHelper(y);
        if (rootX == rootY) {
            return false;
        }

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
    vector<int> parent;
    vector<int> rank;
};