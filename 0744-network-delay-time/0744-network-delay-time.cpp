class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // dijkstra + minHeap to find the max time
        // TC: O(E)
        // SC: O(E)
        unordered_map<int, vector<pair<int, int>>> graph;
        vector<int> delayTimes(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // build list
        for (auto const& time : times) {
            int src = time[0];
            int dst = time[1];
            int delay = time[2];
            graph[src].push_back({dst, delay});
        }

        pq.push({0, k});
        delayTimes[k] = 0;

        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();
            int curWeight = p.first;
            int curNode = p.second;
            for (int i = 0; i < graph[curNode].size(); i++) {
                int nextWeight = graph[curNode][i].second;
                int nextNode = graph[curNode][i].first;
                
                if (nextWeight + curWeight< delayTimes[nextNode]) {
                    delayTimes[nextNode] = nextWeight + curWeight;
                    pq.push({delayTimes[nextNode], nextNode});
                }
            }
        }
        
        // find maximum delay
        int result = 0;
        for (int i = 1; i <= n; i++) {
            if (delayTimes[i] > result) {
                result = delayTimes[i] ;
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};