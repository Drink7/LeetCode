class Solution {
public:
    int maximumCount(vector<int>& nums) {
        // non-decreasing order -> binary search?
        // find first > 0 -> upper_bound
        // find last < 0 -> lower_bound - 1
        // TC: O(logn)
        // SC: O(1)
        int n = nums.size();
        int left = 0;
        int right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= 0) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        int posNum = (left >= n) ? -1 : n - left;

        left = 0;
        right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < 0) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        int negNum = (left - 1 < 0) ? -1 : left;
        return max(posNum, negNum);

        /*
        int negCnt = 0;
        int posCnt = 0;
        for (auto const& num : nums) {
            if (num < 0) {
                negCnt++;
            } else if (num > 0) {
                posCnt++;
            }
        }
        return max(posCnt, negCnt);
        */

    }
};