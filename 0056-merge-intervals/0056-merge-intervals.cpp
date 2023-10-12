class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort intervals by start
        // insert the first interval
        // check if the incoming interval need to be merged or not
        // TC: O(nlogn)
        // SC: O(1)
        sort(intervals.begin(), intervals.end(), [](vector<int>& i1, vector<int>& i2) {
            return i1[0] < i2[0];
        });

        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= result.back()[1]) {
                result.back()[1] = max(intervals[i][1], result.back()[1]);
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};