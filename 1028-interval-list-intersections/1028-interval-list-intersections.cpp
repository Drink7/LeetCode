class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        /*
        // Concept:
        // Use the two sorted order and disjoint intervals
        // Check if 1st start > 2nd start or not
        // Then calculate the overlapp with overlapp start = max(1st start, 2nd start) and overlapp end = min(1st end, 2nd end);
        // TC: O(m * n), m is firstList size and n is secondList
        // SC: O(1)
        int m = firstList.size();
        int n = secondList.size();
        vector<vector<int>> result;
        if (m == 0 && n == 0) {
            return result;
        }

        if (m < n) {
            return intervalIntersection(secondList, firstList);
        }

        vector<int> prevInterval = firstList[0];
        int index1 = 1;
        int index2 = 0;
        while (index1 < m && index2 < n) {
            // check if 1st start > 2nd start or not
            if (firstList[index1][0] < secondList[index2][0]) {
                if (prevInterval[1] >= firstList[index1][0]) {
                    int overlappStart = max(prevInterval[0], firstList[index1][0]);
                    int overlappEnd = min(prevInterval[1], firstList[index1][1]);
                    result.push_back({overlappStart, overlappEnd});
                }
                prevInterval = firstList[index1];
                index1++;
            } else {
                if (prevInterval[1] >= secondList[index2][0]) {
                    int overlappStart = max(prevInterval[0], secondList[index2][0]);
                    int overlappEnd = min(prevInterval[1], secondList[index2][1]);
                    result.push_back({overlappStart, overlappEnd});
                }
                prevInterval = secondList[index2];
                index2++;
            }
        }

        // Calculate the last interval
        if (index1 < m) {
            if (prevInterval[1] >= firstList[index1][0]) {
                int overlappStart = max(prevInterval[0], firstList[index1][0]);
                int overlappEnd = min(prevInterval[1], firstList[index1][1]);
                result.push_back({overlappStart, overlappEnd});
            }
        } else {
            if (prevInterval[1] >= secondList[index2][0]) {
                int overlappStart = max(prevInterval[0], secondList[index2][0]);
                int overlappEnd = min(prevInterval[1], secondList[index2][1]);
                result.push_back({overlappStart, overlappEnd});
            }
        }
        return result;
        */

        // More Elegant Code
        // TC: O(m * n), m is firstList size and n is secondList
        // SC: O(1)
        vector<vector<int>> result;
        int m = firstList.size();
        int n = secondList.size();
        int list1 = 0;
        int list2 = 0;
        while (list1 < m && list2 < n) {
            int overlappStart = max(firstList[list1][0], secondList[list2][0]);
            int overlappEnd = min(firstList[list1][1], secondList[list2][1]);
            if (overlappStart <= overlappEnd) {
                result.push_back({overlappStart, overlappEnd});
            }

            if (overlappEnd == firstList[list1][1]) {
                list1++;
            } else {
                list2++;
            }
        }
        return result;
    }
};