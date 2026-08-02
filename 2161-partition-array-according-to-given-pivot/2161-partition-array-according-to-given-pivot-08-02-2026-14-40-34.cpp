class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        /*
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
        */
        /*
        // use a pivot index to record, pivot index means the last number <= pivot
        // traverse array, if num[i] <= pivot, swap num[i] and num[pivotIndex], pivotIndex++
        // relative order must keep -> this solution is failed
        // TC: O(n)
        // SC: O(1)
        int pivotIndex = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= pivot) {
                swap(nums[i], nums[pivotIndex++]);
            }
        }
        return nums;
        */

        // new a same size answer array
        // one-pass traverse
        // use left and right to store relative answer result
        // TC: O(n)
        // SC: O(1)
        int n = nums.size();
        vector<int> result(n, pivot);
        int left = 0, right = n - 1;
        for (int i = 0, j = n - 1; i < n; i++, j--) {
            if (nums[i] < pivot) {
                result[left++] = nums[i];
            }

            if (nums[j] > pivot) {
                result[right--] = nums[j];
            }
        }
        return result;
    }
};