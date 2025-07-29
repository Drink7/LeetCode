class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // merge intervals
        // sort
        // TC: O(n)
        // SC: O(1)
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        for (auto const& interval : intervals) {
            if (!result.empty() && interval[0] <= result.back()[1]) {
                result.back()[1] = max(result.back()[1], interval[1]);
            } else {
                result.push_back(interval);
            }
        }
        return result;
    }
};