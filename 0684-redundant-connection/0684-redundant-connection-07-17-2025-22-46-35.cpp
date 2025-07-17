class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // union find
        // find the last edges
        // TC: (m)
        // SC: (m)
        // find m
        unordered_set<int> nodeSet;
        for (auto const& edge : edges) {
            nodeSet.insert(edge[0]);
            nodeSet.insert(edge[1]);
        }

        int n = nodeSet.size();
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
            rank.push_back(1);
        }

        int edgeX = -1;
        int edgeY = -1;
        for (auto const& edge : edges) {
            if (unionHelper(edge[0] - 1, edge[1] - 1)) {
                edgeX = edge[0];
                edgeY = edge[1];
            }
        }
        return {edgeX, edgeY};
    }

    bool unionHelper(int x, int y) {
        int rootX = findHelper(x);
        int rootY = findHelper(y);
        if (rootX == rootY) {
            return true;
        }

        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootY] > rank[rootX]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return false;
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