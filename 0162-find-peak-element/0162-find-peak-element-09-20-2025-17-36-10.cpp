class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // binary search find left first, then find right
        // TC: O(logn)
        // SC: O(logn)
        return peakHelper(nums, 0, nums.size() - 1);
    }

    int peakHelper(vector<int>& nums, int left, int right) {
        if (left > right) {
            return -1;
        }

        int mid = left + (right - left) / 2;
        if (mid == 0 && mid == nums.size() - 1) {
            return mid;
        } else {
            if (mid == 0) {
                if (nums[mid + 1] < nums[mid]) {
                    return mid;
                } else {
                    return peakHelper(nums, mid + 1, right);
                }
            } else if (mid == nums.size() - 1) {
                if (nums[mid - 1] < nums[mid]) {
                    return mid;
                } else {
                    return peakHelper(nums, left, mid - 1);
                }
            } else {
                if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
                    return mid;
                } else {
                    int leftPart = peakHelper(nums, left, mid - 1);
                    if (leftPart != -1) {
                        return leftPart;
                    } else {
                        return peakHelper(nums, mid + 1, right);
                    }
                }
            }
        }
    }
};