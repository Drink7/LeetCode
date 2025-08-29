class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // k closet -> maxHeap <distance, index>
        // TC: O(nlogk)
        // SC: O(k)
        priority_queue<pair<int,int>> maxHeap;
        vector<vector<int>> result;
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            
            maxHeap.push({x * x + y * y, i});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        while (maxHeap.size() > 0) {
            auto [dist, index] = maxHeap.top();
            maxHeap.pop();
            result.push_back(points[index]);
        }
        return result;
    }
};