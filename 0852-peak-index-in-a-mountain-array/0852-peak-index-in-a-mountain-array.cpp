class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        /*
        // binary search to find peak
        // TC: O(logn)
        // SC: O(1)
        int low = 0;
        int high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid == 0 || mid == arr.size() - 1) {
                return mid;
            } else {
                if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
                    return mid;
                } else {
                    if (arr[mid - 1] > arr[mid]) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
        }
        return -1;
        */

        // More elegant
        // since arr[0] and arr[arr.size() - 1] must not be peak
        // (0 < i < arr.length - 1)
        int low = 1;
        int high = arr.size() - 2;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
                return mid;
            } else if (arr[mid] > arr[mid - 1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
};