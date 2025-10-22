class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // sweep line
        // make interval start, +1 and interval end , -1
        // sort and traverse, check if the active maximum
        // TC: O(nlogn)
        // SC: O(n)
        vector<pair<int, int>> sortedIntervals;
        for (auto const& interval : intervals) {
            sortedIntervals.push_back({interval[0], +1});
            sortedIntervals.push_back({interval[1], -1});
        }

        sort(sortedIntervals.begin(), sortedIntervals.end());

        int rooms = 0;
        int active = 0;
        for (auto const& [point, count] : sortedIntervals) {
            active += count;
            rooms = max(rooms, active);
        }
        return rooms;
    }
};