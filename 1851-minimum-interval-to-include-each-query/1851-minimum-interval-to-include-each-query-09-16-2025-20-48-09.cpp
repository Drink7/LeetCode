class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // TC: O((m + n)logn)
        // SC: O(m + n)
        sort(intervals.begin(), intervals.end()); // O(m log m)
        
        // use value, index
        vector<pair<int, int>> sortedQueue;
        for (int i = 0; i < queries.size(); i++) {
            sortedQueue.push_back({queries[i], i});
        }

        sort(sortedQueue.begin(), sortedQueue.end()); // O(n log n)

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        int i = 0; // interval pointer
        vector<int> res(queries.size(), -1);

        for (auto& [query, idx] : sortedQueue) {
            while (i < intervals.size() && intervals[i][0] <= query) {
                int start = intervals[i][0];
                int end = intervals[i][1];
                int len = end - start + 1;
                minHeap.push({len, end});
                i++;
            }

            while (!minHeap.empty() && minHeap.top().second < query) {
                minHeap.pop();
            }

            if (!minHeap.empty()) {
                res[idx] = minHeap.top().first;
            }
        }
        return res;
    }
};