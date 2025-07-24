class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // Dijkstra + min Heap, V points, E edges
        // TC: O(V^2 + V + E)
        // SC: O(E)
        int n = points.size();
        vector<bool> visited(n, false);

        // dist, next index
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int edgeUsed = 0;
        int result = 0;

        pq.push({0, 0}); // cost, index

        while (edgeUsed < n) {
            auto [cost, index] = pq.top();
            pq.pop();

            if (visited[index]) continue;

            visited[index] = true;
            result += cost;
            edgeUsed++;

            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    int dist = abs(points[i][0] - points[index][0]) + abs(points[i][1] - points[index][1]);
                    pq.push({dist, i});
                }
            }
        }
        return result;
    }
};