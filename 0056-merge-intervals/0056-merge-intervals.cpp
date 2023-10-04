class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort interval start
        // insert 1st interval
        // check remaining interval, incoming interval start < last interval end, need to merge
        // else insert
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            vector<int> interval = intervals[i];
            // merge
            if (result.back()[1] >= interval[0]) {
                result.back()[1] = max(result.back()[1], interval[1]);
            } else {
                result.push_back(interval);
            }
        }
        return result;
    }
};