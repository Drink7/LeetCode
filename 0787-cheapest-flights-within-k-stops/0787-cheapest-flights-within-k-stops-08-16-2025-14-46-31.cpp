class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // single source, weight graph, find shortest path
        // at most k steps
        unordered_map<int, vector<pair<int, int>>> adjList; // src, dst, cost
        queue<pair<int, int>> q; // stop, cost
        
        vector<int> dist(n, 10000000); // min dist from src
        // build graph
        for (auto const& flight : flights) {
            adjList[flight[0]].push_back({flight[1], flight[2]});
        }

        // start from src
        dist[src] = 0;
        q.push({0, src});

        // at most k stop, which means we at most can go k + 1 steps
        while (q.size() > 0 && k >= 0) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                auto [curCost, curStop] = q.front();
                q.pop();

                for (auto& [neighStop, neighCost] : adjList[curStop]) {
                    // relaxation
                    if (dist[neighStop] > curCost + neighCost) {
                        dist[neighStop] = curCost + neighCost;
                        q.push({dist[neighStop], neighStop});
                    }
                }
            }
            k--;
        }
        
        if (dist[dst] == 10000000) {
            return -1;
        } else {
            return dist[dst];
        }
    }
};