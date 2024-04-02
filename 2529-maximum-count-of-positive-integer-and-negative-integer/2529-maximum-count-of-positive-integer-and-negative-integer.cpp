class Solution {
public:
    int maximumCount(vector<int>& nums) {
        // use binary search to find positive numbers and negative numbers
        // two logn find
        // TC: O(logn)
        // SC: O(1)
        int negCnt = 0;
        int posCnt = 0;

        int low = 0;
        int high = nums.size() - 1;
        // find negative, find the last negative element
        // Note that 0 is neither positive nor negative.
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < 0) {
                if (mid == nums.size() - 1 || nums[mid + 1] >= 0) {
                    negCnt = mid + 1;
                    break;
                } else {
                    low = mid + 1;
                }
            } else {
                high = mid - 1;
            }
        }

        // find positive, find the first positive element
        // Note that 0 is neither positive nor negative.
        low = 0;
        high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > 0) {
                if (mid == 0 || nums[mid - 1] <= 0) {
                    posCnt = nums.size() - mid;
                    break;
                } else {
                    high = mid - 1;
                }
            } else {
                low = mid + 1;
            }
        }
        return max(negCnt, posCnt);
    }
};