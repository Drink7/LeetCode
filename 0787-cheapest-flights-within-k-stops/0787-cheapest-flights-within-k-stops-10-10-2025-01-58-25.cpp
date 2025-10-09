class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // BFS + K steps
        // relaxation
        // TC: O(E + V)
        // SC: O(E + V)
        unordered_map<int, vector<pair<int, int>>> adjList;
        queue<pair<int, int>> q;
        vector<int> price(n, INT_MAX);

        // build graph
        for (auto const& flight : flights) {
            adjList[flight[0]].push_back({flight[1], flight[2]});
        }

        q.push({src, 0}); // stop, cost

        while (q.size() > 0 && k >= 0) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                auto [stop, cost] = q.front();
                q.pop();

                for (auto const& [nextStop, nextCost] : adjList[stop]) {
                    // relaxation
                    if (price[nextStop] > cost + nextCost) {
                        price[nextStop] = cost + nextCost;
                        q.push({nextStop, price[nextStop]});
                    }
                }
            }
            k--;
        }
        return price[dst] == INT_MAX ? -1 : price[dst];
    }
};