class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        /*
        // TC: O(n)
        // SC: O(1)
        int arrLength = arr.size();
        int index = 0;
        for (int i = 0; i < arrLength; i++) {
            if (arr[i] - i - 1 >= k) {
                return k + i;
            }
        }
        return k + arrLength;
        */
        // Binary search
        // Find first missing number
        // TC: O(logn)
        // SC: O(1)
        int low = 0;
        int high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - mid - 1;
            if (missing >= k) {
                if (mid == 0 || arr[mid - 1] - (mid - 1) - 1 < k) {
                    return k + mid;
                } else {
                    high = mid - 1;
                }
            } else {
                low = mid + 1;
            }
        }
        return k + arr.size();
    }
};