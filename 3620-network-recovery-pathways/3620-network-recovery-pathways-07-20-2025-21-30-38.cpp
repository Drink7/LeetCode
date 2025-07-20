class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> graph(n);
        int minCost = INT_MAX, maxCost = INT_MIN;

        // 建圖 + 記錄最小最大邊權
        for (auto& e : edges) {
            int u = e[0], v = e[1], cost = e[2];
            graph[u].push_back({v, cost});
            minCost = min(minCost, cost);
            maxCost = max(maxCost, cost);
        }

        int left = minCost, right = maxCost, answer = -1;

        // Binary Search on "minimum edge cost" threshold
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canReach(graph, online, k, mid)) {
                answer = mid;         // 有效，儲存並試試更大的
                left = mid + 1;
            } else {
                right = mid - 1;      // 無法走通，降低門檻
            }
        }

        return answer;
    }

private:
    bool canReach(vector<vector<pair<int, int>>>& graph, vector<bool>& online, long long k, int threshold) {
        int n = graph.size();
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        dist[0] = 0;
        pq.emplace(0, 0);

        while (!pq.empty()) {
            auto [costSoFar, node] = pq.top();
            pq.pop();

            if (node == n - 1) return true;

            for (auto& [nei, cost] : graph[node]) {
                if (!online[nei] || cost < threshold) continue;

                long long newCost = costSoFar + cost;
                if (newCost <= k && newCost < dist[nei]) {
                    dist[nei] = newCost;
                    pq.emplace(newCost, nei);
                }
            }
        }

        return false;
    }
};
