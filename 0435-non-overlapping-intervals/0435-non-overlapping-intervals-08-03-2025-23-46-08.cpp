class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort by end time
        // tracking end time
        // if interval start time <= end time, cnt++ (need to remove)
        // TC: O(nlogn)
        // SC: O(1)
        sort(intervals.begin(), intervals.end(), [](auto const& a, auto const& b) {
            return a[1] < b[1];
        });

        int endTime = intervals[0][1];
        int cnt = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (endTime > intervals[i][0]) {
                cnt++;
            } else {
                endTime = max(endTime, intervals[i][1]);
            }
        }
        return cnt;
    }
};