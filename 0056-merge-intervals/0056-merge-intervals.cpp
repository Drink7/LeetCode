class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sort the interval by their start first
        // merge the interval, if can not merge, insert it to the result list
        // TC: O(nlogn)
        // SC: O(1)
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });

        // start to merge
        // we first insert the first interval
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= result.back()[1]) {
                // merge interval
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};