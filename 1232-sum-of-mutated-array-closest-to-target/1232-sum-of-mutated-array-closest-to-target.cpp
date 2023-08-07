class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        // Binary search between 0 to max(arr)
        // find the last less or equal to target
        // TC: O(nlogn)
        // SC: O(1)
        int left = 0;
        int maxVal = -1;
        int right = -1;
        for (auto const& num : arr) {
            if (num > maxVal) {
                maxVal = num;
            }
        }

        right = maxVal;

        int lessSum = -1;
        int lessNumber = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midSum = calculateSum(arr, mid);

            if (midSum <= target) {
                if (mid == maxVal || calculateSum(arr, mid + 1) > target) {
                    lessSum = midSum;
                    lessNumber = mid;
                    break;
                } else {
                    left = mid + 1;
                }
            } else {
                right = mid - 1;
            }
        }

        int greaterSum = -1;
        int greaterNumber = -1;
        left = 0;
        right = maxVal;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midSum = calculateSum(arr, mid);

            if (midSum >= target) {
                if (mid == 1 || calculateSum(arr, mid - 1) < target) {
                    greaterSum = midSum;
                    greaterNumber = mid;
                    break;
                } else {
                    right = mid - 1;
                }
            } else {
                left = mid + 1;
            }
        }

        cout << "lessSum: " << lessSum << ", greaterSum: " << greaterSum << endl;
        cout << "lessNumber: " << lessNumber << ", greaterNumber: " << greaterNumber << endl;
        if (abs(lessSum - target) > abs(greaterSum - target)) {
            return greaterNumber;
        } else {
            return lessNumber;
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