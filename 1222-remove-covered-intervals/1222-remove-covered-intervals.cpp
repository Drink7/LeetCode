class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        /*
        // Sort intervals by increasing of startTime and decreasing of endTime
        // TC: O(nlogn)
        // SC: O(1)
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            if (a[0] == b[0]) {
                return a[1] > b[1];
            } else {
                return a[0] < b[0];
            }
        });
        int n = intervals.size();
        int cnt = 0;
        vector<int> prevInterval = intervals[0];
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= prevInterval[0] && intervals[i][1] <= prevInterval[1]) {
                prevInterval[0] = intervals[i][0];
                cnt++;
            } else {
                prevInterval[1] = max(prevInterval[1], intervals[i][1]);
            }
        }
        return n - cnt;
        */

        // Solution 2
        // We count on remaining interval
        // TC: O(nlogn)
        // SC: O(1)
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            if (a[0] == b[0]) {
                return a[1] > b[1];
            } else {
                return a[0] < b[0];
            }
        });

        int prev = 0;
        int cnt = 0;
        for (auto const& interval : intervals) {
            if (interval[1] <= prev) {
                continue;
            } else {
                prev = interval[1];
                cnt++;
            }
        }
        return cnt;
    }
};