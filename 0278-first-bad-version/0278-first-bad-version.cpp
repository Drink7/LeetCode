// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // all the versions after a bad version are also bad
        // Find the first element that is bad version
        // TC: O(logn)
        // SC: O(1)
        int left = 1;
        int right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            bool isVersionBad = isBadVersion(mid);
            if (!isVersionBad) {
                left = mid + 1;
            } else {
                if (mid == 1 || !isBadVersion(mid - 1)) {
                    return mid;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};