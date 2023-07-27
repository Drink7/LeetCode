class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        /*
        // Sort first
        // TLE
        // TC: O(m * n + mlogm)
        // SC: O(1)
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            return a[0] < b[0];
        });

        vector<int> result;
        for (auto const& query : queries) {
            int smallest = INT_MAX;
            for (auto const& interval : intervals) {
                if (interval[0] <= query && query <= interval[1]) {
                    smallest = min(smallest, interval[1] - interval[0] + 1);
                }
            }
            if (smallest == INT_MAX) {
                smallest = -1;
            }
            result.push_back(smallest);
        }
        return result;
        */
        
        // Sort intervals , sort queries with index
        // MinHeap store (interval size, right value)
        // TC: O(mlogm + nlogn)
        // SC: O(m + n)
        vector<int> sortedQueries = queries;
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> pq;

        // (query, size of interval)
        unordered_map<int, int> dict;
        sort(intervals.begin(), intervals.end());
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> result;
        int i = 0;

        // iterate sortedQueries
        for (int j = 0; j < sortedQueries.size(); j++) {
            int query = sortedQueries[j];
            
            while (i < intervals.size() && intervals[i][0] <= query) {
                int left = intervals[i][0];
                int right = intervals[i][1];
                pq.push({right - left + 1, right});
                i++;
            }
            
            while (!pq.empty() && pq.top().second < query) {
                pq.pop();
            }
            
            if (!pq.empty()) {
                dict[query] = pq.top().first;
            } else {
                dict[query] = -1;
            }
        }
        
        for (int j = 0; j < queries.size(); j++) {
            result.push_back(dict[queries[j]]);
        }
        return result;
    }
};