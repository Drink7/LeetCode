class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort the interval with the start
        // check each interval
        // compare the result.back()
        // if back() end >= incoming interval start -> merge
        // max(back() end, incoming end)
        // next interval
        // TC: O(nlogn)
        // SC: O(1)
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (result.back()[1] >= intervals[i][0]) {
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};