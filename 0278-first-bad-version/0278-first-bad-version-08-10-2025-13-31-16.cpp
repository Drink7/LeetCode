// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // first bad version
        // TC: O(logn)
        // SC: O(1)
        int left = 1;
        int right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid) == false) {
                left = mid + 1;
            } else {
                if (mid == 1 || isBadVersion(mid - 1) == false) {
                    return mid;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1; // impossible
    }
};