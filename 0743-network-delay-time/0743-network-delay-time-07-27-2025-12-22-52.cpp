class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Dijkstra + minHeap
        // TC: O(E + VlogV + ElogV)
        // SC: O(V + E)
        vector<vector<pair<int, int>>> graph(n + 1);
        vector<int> dist(n + 1, INT_MAX);

        // build graph
        for (auto const& edge : times) {
            graph[edge[0]].push_back({edge[1], edge[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});
        dist[k] = 0;
        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();
            int curWeight = p.first;
            int curNode = p.second;
            for (int i = 0; i < graph[curNode].size(); i++) {
                auto [nextNode, nextWeight] = graph[curNode][i];
                if (curWeight + nextWeight < dist[nextNode]) {
                    dist[nextNode] = curWeight + nextWeight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        // find max
        int result = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            }
            result = max(result, dist[i]);
        }
        return result;
    }
};