class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // check new interval can insert
        // three parts
        // TC: O(n)
        // SC: O(1)
        vector<vector<int>> result;
        int i = 0;
        for (; i < intervals.size(); i++) {
            if (intervals[i][1] < newInterval[0]) {
                result.push_back(intervals[i]);
            } else {
                break;
            }
        }

        // start to merge
        for (; i < intervals.size(); i++) {
            if (intervals[i][0] > newInterval[1]) {
                break;
            } else {
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }
        }

        result.push_back(newInterval);

        // fill remain
        for (; i < intervals.size(); i++) {
            result.push_back(intervals[i]);
        }
        return result;
    }
};