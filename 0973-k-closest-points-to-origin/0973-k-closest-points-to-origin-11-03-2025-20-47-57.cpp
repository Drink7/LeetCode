class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // minHeap with pair, double, index
        // store the index
        // TC: O(nlogk)
        // SC: O(k)
        priority_queue<pair<double, int>> maxHeap;

        for (int i = 0; i < points.size(); i++) {
            double dist = sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]);
            maxHeap.push({dist, i});

            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        // store to result
        vector<vector<int>> result;
        while (maxHeap.size() > 0) {
            result.push_back(points[maxHeap.top().second]);
            maxHeap.pop();
        }
        return result;
    }
};