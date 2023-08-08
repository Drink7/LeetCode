class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        // Binary search between 0 to max(arr)
        // find the last less or equal to target
        // TC: O(nlogn)
        // SC: O(1)
        int left = 0;
        int right = -1;
        int maxVal = -1;
        for (auto const& num : arr) {
            if (num > right) {
                right = num;
            }
        }

        maxVal = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midSum = calculateSum(arr, mid);

            if (midSum <= target) {
                if (mid == maxVal || calculateSum(arr, mid + 1) > target) {
                    if (mid == maxVal) {
                        return mid;
                    }

                    if (abs(midSum - target) <= abs(calculateSum(arr, mid + 1) - target)) {
                        return mid;
                    } else {
                        return mid + 1;
                    }
                } else {
                    left = mid + 1;
                }
            } else {
                right = mid - 1;
            }
        }
        return -1;
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