class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // incoming interval[1] < newInterval[0]
        // keep insert
        // start to merge
        // max(incoming[1], newInterval[1]
        // until newInterval[1] < incoming[0]
        // keep insert
        // TC: O(n)
        // SC: O(1)
        vector<vector<int>> result;

        int index = 0;
        for (; index < intervals.size(); index++) {
            if (intervals[index][1] < newInterval[0]) {
                result.push_back(intervals[index]);
            } else {
                break;
            }
        }

        // merge newIntervals with intervals[index]
        for (; index < intervals.size(); index++) {
            if (newInterval[1] < intervals[index][0]) {
                break;
            } else {
                newInterval[0] = min(newInterval[0], intervals[index][0]);
                newInterval[1] = max(newInterval[1], intervals[index][1]);
            }
        }

        result.push_back(newInterval);

        // insert remain intervals
        for (; index < intervals.size(); index++) {
            result.push_back(intervals[index]);
        }
        return result;
    }
};