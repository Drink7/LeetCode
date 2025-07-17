class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // Union Find, if union continue, then return the egde
        // index start from 1 not 0
        // TC: O(n)
        // SC: O(n)
        int n = edges.size();
        parent.resize(n + 1);
        rank.resize(n + 1);

        // init
        for (int i = 0; i < n + 1; i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        for (auto const& edge : edges) {
            // same root but add again, cause cycle
            if (findFunction(edge[0]) == findFunction(edge[1])) {
                return edge;
            }
            unionFunction(edge[0], edge[1]);
        }
        return {};
    }


    void unionFunction(int vertex1, int vertex2) {
        int root1 = findFunction(vertex1);
        int root2 = findFunction(vertex2);
        if (root1 == root2) {
            return;
        }

        if (rank[root1] > rank[root2]) {
            parent[root2] = root1;
        } else if (rank[root2] > rank[root1]) {
            parent[root1] = root2;
        } else {
            parent[root1] = root2;
            rank[root2]++;
        }
    }

    int findFunction(int i) {
        if (parent[i] != i) {
            parent[i] = findFunction(parent[i]);
        }
        return parent[i];
    }

private:
    vector<int> parent;
    vector<int> rank;
};