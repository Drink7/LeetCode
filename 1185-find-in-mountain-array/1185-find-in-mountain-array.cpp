/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // Can not do O(n) traverse, use O(logn)?
        // We might assume mountainArr at least 3 elements
        // there would be no same value in same side
        // 1. Find peak
        // 2. Search the left part
        // 3. If not find, search the right part
        // TC: O(logn)
        // SC: O(1)
        int mountainIndex = findMountainIndex(mountainArr);

        // search left part
        int findIndex = findTarget(0, mountainIndex, target, mountainArr);
        if (findIndex != -1) {
            return findIndex;
        } else {
            return findTarget(mountainIndex + 1, mountainArr.length() - 1, target, mountainArr);
        }
    }

    int findMountainIndex(MountainArray &mountainArr) {
        int left = 0;
        int right = mountainArr.length() - 1;
        while (left <= right) {
            if (left == right) {
                return left;
            } else {
                int mid = left + (right - left) / 2;
                int midElement = mountainArr.get(mid);
                int rightElement = mountainArr.get(mid + 1);
                if (midElement > rightElement) {
                    int leftElement = mountainArr.get(mid - 1);
                    if (leftElement < midElement) {
                        return mid;
                    } else {
                        right = mid - 1;
                    }
                } else {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }

    int findTarget(int start, int end, int target, MountainArray &mountainArr) {
        int left = start;
        int right = end;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midElement = mountainArr.get(mid);
            if (midElement == target) {
                return mid;
            } else if (midElement > target) {
                if (start == 0) {
                    // left part
                    right = mid - 1;
                } else {
                    // right part
                    left = mid + 1;
                }
            } else {
                if (start == 0) {
                    // left part
                    left = mid + 1;
                } else {
                    // right part
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};