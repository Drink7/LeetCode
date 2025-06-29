class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // max heap to keep distance and index
        // closet means distance need to be smallest
        // map to store distance and points (Don't use map)
        // TC: O(n + nlogk)
        // SC: O(n)
        priority_queue<pair<int, int>> pq;
        vector<vector<int>> result;

        // keep k closet points
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            int distance = x * x + y * y;
            pq.push({distance, i});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        // get result
        while (pq.size() > 0) {
            pair<int, int> top = pq.top();
            pq.pop();
            result.push_back(points[top.second]);
        }
        return result;
    }
};