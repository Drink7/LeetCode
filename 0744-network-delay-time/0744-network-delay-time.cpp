class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Dijkstra's, minHeap
        // TC: O(E logV)
        // SC: O(E + V)
        // store (next node, weight)
        vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>());
        vector<int> distance(n + 1, INT_MAX);

        // (weight, next node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // build adjency
        for (auto const& edge : times) {
            graph[edge[0]].push_back({edge[1], edge[2]});
        }

        // start from k
        pq.push({0, k});
        distance[k] = 0;

        while (pq.size() > 0) {
            pair<int, int> p = pq.top();
            pq.pop();
            int curWeight = p.first;
            int curNode = p.second;
            for (int i = 0; i < graph[curNode].size(); i++) {
                int nextNode = graph[curNode][i].first;
                int nextWeight = graph[curNode][i].second;
                if (curWeight + nextWeight < distance[nextNode]) {
                    distance[nextNode] = curWeight + nextWeight;
                    pq.push({distance[nextNode], nextNode});
                }
            }
        }

        int result = 0;
        for (int i = 1; i < n + 1; i++) {
            if (distance[i] > result) {
                result = distance[i];
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};