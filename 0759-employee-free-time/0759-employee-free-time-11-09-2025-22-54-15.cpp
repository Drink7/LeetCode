/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        // sweep line, sort start with increasing, but +1, -1 in decreasing
        // for ensure overlapping will not be count
        // [1, 2] [2, 4] -> [2, 2] is not free time
        // TC: O(nlogn)
        // SC: O(n)
        vector<pair<int, int>> totalTime;
        vector<Interval> result;
        int n = schedule.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < schedule[i].size(); j++) {
                totalTime.push_back({schedule[i][j].start, +1});
                totalTime.push_back({schedule[i][j].end, -1});
            }
        }

        // sort
        sort(totalTime.begin(), totalTime.end(), [](auto const& pair1, auto const& pair2){
            if (pair1.first == pair2.first) {
                return pair1.second > pair2.second;
            } else {
                return pair1.first < pair2.first;
            }
        });

        int active = 0;
        int freeStart = -1;
        for (auto const& time : totalTime) {
            active += time.second;
            if (active == 0) { // free time start
                freeStart = time.first;
            } else if (active != 0 && freeStart != -1) {
                result.push_back(Interval(freeStart, time.first));
                freeStart = -1;
            }
        }
        return result;
    }
};