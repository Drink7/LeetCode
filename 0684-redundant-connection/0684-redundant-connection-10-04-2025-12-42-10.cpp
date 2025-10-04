class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // traverse all egdes union find
        // until answer
        // TC: O(E + V)
        // SC: O(V)
        int n = edges.size();
        parent.resize(n, 0);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (auto const& edge: edges) {
            if (!unionHelper(edge[0] - 1, edge[1] - 1)) {
                return edge;
            }
        }
        return {}; // impossible
    }

    bool unionHelper(int x, int y) {
        int rootX = findHelper(x);
        int rootY = findHelper(y);
        if (rootX == rootY) {
            return false;
        }

        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if(rank[rootX] < rank[rootY]) {
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