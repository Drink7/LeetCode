class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // similar to quick sort (or sort color, 3 way partitioning)
        // TC: O(n)
        // SC: O(n)
        // Brute Force
        vector<int> smaller, bigger, result;
        int pivotCnt = 0;
        for (auto const& num : nums) {
            if (num < pivot) {
                smaller.push_back(num);
            } else if (num == pivot) {
                pivotCnt++;
            } else {
                bigger.push_back(num);
            }
        }

        // store to result
        for (auto const& num : smaller) {
            result.push_back(num);
        }

        for (int i = 0; i < pivotCnt; i++) {
            result.push_back(pivot);
        }

        for (auto const& num : bigger) {
            result.push_back(num);
        }

        return result;
    }
};