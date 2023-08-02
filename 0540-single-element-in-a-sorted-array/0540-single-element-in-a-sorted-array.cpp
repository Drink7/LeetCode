class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // logn -> binary search or divide and conquer
        // the nums must be odd
        // when binary search find the mid, we check the value mid - 1, mid + 1
        // if mid != mid + 1 && mid != mid - 1, return mid
        // check mid - 1, mid + 1, which side is equal to mid
        // the side equal to mid which number is odd, choose the other side
        // the side equal to mid which number is even, choose it
        // TC: O(logn)
        // SC: O(1)
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid == 0 || mid == nums.size() - 1) {
                return nums[mid];
            } else if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            } else {
                if (nums[mid - 1] == nums[mid]) {
                    if ((mid - left) % 2 == 0) {
                        // add additional minus one for skip the mid - 1 value
                        right = mid - 1 - 1;
                    } else {
                        left = mid + 1;
                    }
                } else {
                    if ((right - mid) % 2 == 0) {
                        // add additional plus one for skip the mid + 1 value
                        left = mid + 1 + 1;
                    } else {
                        right = mid - 1;
                    }
                }
            }
        }
        return -1;
    }
};