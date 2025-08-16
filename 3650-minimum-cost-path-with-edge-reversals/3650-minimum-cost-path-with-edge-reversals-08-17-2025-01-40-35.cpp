class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> adjList;
        vector<int> dist(n, INT_MAX);

        // Dijkstra
        for (auto const& edge : edges) {
            int src = edge[0];
            int dst = edge[1];
            int cost = edge[2];

            // normal
            adjList[src].push_back({dst, cost});
            
            //reverse
            adjList[dst].push_back({src, cost * 2});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // cost, index
        pq.push({0, 0});
        dist[0] = 0;

        while (pq.size() > 0) {
            auto [curCost, curStop] = pq.top();
            pq.pop();

            if (curCost > dist[curStop]) {
                continue;
            }

            // check neigh
            for (auto& [nextStop, nextCost] : adjList[curStop]) {
                if (dist[nextStop] > curCost + nextCost) {
                    dist[nextStop] = curCost + nextCost;
                    pq.push({dist[nextStop], nextStop});
                }
            }
        }

        return dist[n - 1] == INT_MAX ? -1 : dist[n - 1];
    }
};