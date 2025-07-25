class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // src, dst find minimum with k
        // Build adjlist graph
        // BFS
        // if k stop still not dst, -1
        // else return cost
        // TC: O(ElogE)
        // SC: O()
        // store (next node, weight)
        unordered_map<int, vector<pair<int, int>>> graph;
        vector<int> dist(n, INT_MAX);
        queue<pair<int, int>> q; // (to, cost)

        for (auto const& flight : flights) {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }

        // dist, index
        int edge = 0;
        q.push({src, 0});
        dist[src] = 0;
        while (edge <= k && q.size() > 0) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                auto [cur, cost] = q.front();
                q.pop();

                if (graph.count(cur) > 0) {
                    for (auto const& p : graph[cur]) {
                        // relaxation
                        int next = p.first;
                        int nextCost = p.second;
                        if (cost + nextCost < dist[next]) {
                            dist[next] = cost + nextCost;
                            q.push({next, dist[next]});
                        }
                    }
                }
            }
            edge++;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};