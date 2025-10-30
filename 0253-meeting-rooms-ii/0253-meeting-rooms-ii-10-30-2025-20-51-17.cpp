class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        /*
        vector<pair<int, int>> rooms;
        for (int i = 0; i < intervals.size(); i++) {
            rooms.push_back({intervals[i][0], +1});
            rooms.push_back({intervals[i][1], -1});
        }
        
        sort (rooms.begin(), rooms.end());

        int result = 0;
        int active = 0;
        for (auto const& room : rooms) {
            active += room.second;
            result = max(result, active);
        }
        return result;
        */

        // prioirty_queue min Heap
        // store the romm end time
        sort (intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto const& interval : intervals) {
            if (!minHeap.empty() && minHeap.top() <= interval[0]) {
                minHeap.pop();
            }
            minHeap.push(interval[1]);
        }
        return minHeap.size();

    }
};