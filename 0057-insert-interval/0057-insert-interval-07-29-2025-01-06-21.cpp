class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        /*
        // intervals is in ascending order
        // TC: O(nlogn)
        // SC: O(1)
        vector<vector<int>> result;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        for (auto const& interval : intervals) {
            if (result.size() > 0 && result.back()[1] >= interval[0]) {
                result.back()[1] = max(result.back()[1], interval[1]);
            } else {
                result.push_back(interval);
            }
        }
        return result;
        */
        // handle before newInterval and after newInterval
        int n = intervals.size();
        vector<vector<int>> result;
        int index = 0;
        for (index = 0; index < n; index++) {
            if (intervals[index][1] < newInterval[0]) {
                result.push_back(intervals[index]);
            } else {
                break;
            }
        }

        // insert newInterval
        for (; index < n; index++) {
            if (intervals[index][0] > newInterval[1]) {
                break;
            } else {
                newInterval[0] = min(intervals[index][0], newInterval[0]);
                newInterval[1] = max(intervals[index][1], newInterval[1]);
            }
        }
        result.push_back(newInterval);

        for (; index < n; index++) {
            result.push_back(intervals[index]);
        }
        return result;
    }
};