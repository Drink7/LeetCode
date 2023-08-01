class Solution {
public:
    int mySqrt(int x) {
        // find the last smaller than or equal to x
        // TC: O(logn)
        // SC: O(1)
        long left = 0;
        long right = x;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            long multiply = mid * mid;
            if (multiply <= x) {
                if (mid == x || (mid + 1) * (mid + 1) > x) {
                    return mid;
                } else {
                    left = mid + 1;
                }
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};