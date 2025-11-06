class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // color problem
        // red: 1. green: -1, unknown: 0
        // if neighbor == sel, must not be pipartite
        // TC: O(V + E)
        // SC: O(V)
        int n = graph.size();
        vector<int> color(n, 0);

        queue<int> q;
        // find a edge first
        for (int i = 0; i < n; i++) {
            if (color[i] != 0) continue;
    
            color[i] = 1;
            q.push(i);

            while (q.size() > 0) {
                int node = q.front();
                q.pop();

                // traverse neighbor
                for (auto& neigh : graph[node]) {
                    if (color[neigh] == color[node]) {
                        return false;
                    } else if (color[neigh] == 0) {
                        color[neigh] = -color[node];
                        q.push(neigh);
                    }
                }
            }
        }
        return true;
    }
};