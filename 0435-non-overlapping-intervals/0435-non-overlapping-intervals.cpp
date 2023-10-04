class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort ascending by interval start
        // make sure end is sort ascending too
        // TC: O(nlogn)
        // SC: O(1)
        int count = 0;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });

        // start from index 1
        int intervalEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervalEnd) {
                intervalEnd = min(intervalEnd, intervals[i][1]);
                count++;
            } else {
                intervalEnd = intervals[i][1];
            }
        }
        return count;
    }
};