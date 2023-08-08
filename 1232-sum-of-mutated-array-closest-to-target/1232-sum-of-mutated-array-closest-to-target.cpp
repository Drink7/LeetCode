class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        // Binary search between 0 to max(arr)
        // find the last less or equal to target
        // TC: O(nlogn)
        // SC: O(1)
        int left = 0;
        int right = -1;
        for (auto const& num : arr) {
            if (num > right) {
                right = num;
            }
        }

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midSum = calculateSum(arr, mid);

            if (midSum == target) {
                return mid;
            } else if(midSum < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // at this point, the solution is either low or low - 1;
        if (abs(calculateSum(arr, left) - target) < abs(calculateSum(arr, left - 1) - target)) {
            return left;
        } else {
            return left - 1;
        }
    }

    int calculateSum(vector<int>& arr, int mid) {
        int midSum = 0;
        for (auto const& num : arr) {
            if (num > mid) {
                midSum += mid;
            } else {
                midSum += num;
            }
        }
        return midSum;
    }
};