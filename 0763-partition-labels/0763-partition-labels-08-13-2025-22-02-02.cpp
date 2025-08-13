class Solution {
public:
    vector<int> partitionLabels(string s) {
        // use hash map to sort
        // trasfer to intervaals
        // TC: O(nlogn)
        // SC: O(n)
        unordered_map<char, vector<int>> charMap;
        vector<int> result;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            charMap[s[i]].push_back(i);
        }

        vector<vector<int>> intervals;
        vector<vector<int>> mergedIntervals;
        for (auto const& p : charMap) {
            intervals.push_back({p.second[0], p.second.back()});
        }

        sort(intervals.begin(), intervals.end());

        mergedIntervals.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= mergedIntervals.back()[1]) {
                mergedIntervals.back()[1] = max(mergedIntervals.back()[1], intervals[i][1]);
            } else {
                mergedIntervals.push_back(intervals[i]);
            }
        }

        for (auto const& interval : mergedIntervals) {
            result.push_back(interval[1] - interval[0] + 1);
        }
        return result;
    }
};