class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        // Refer to https://www.youtube.com/watch?v=YUF3_eBdzsk 
        // Refer to https://www.cnblogs.com/grandyang/p/5933787.html
        // TC: (mlogn), m is the nums.size, n is the max element in nums
        // SC: O(1)
        // left = max(nums)
        // right = sum(nums)
        int left = INT_MIN;
        int right = 0;
        int result = 0;
        for (auto const& num : nums) {
            if (num > left) {
                left = num;
            }
            right += num;
        }

        // Start Binary Search
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canSplit(nums, mid, k)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }

    bool canSplit(vector<int>& nums, int mid, int k) {
        int cnt = 1;
        int subSum = 0;
        for (auto const& num : nums) {
            if (subSum + num > mid) {
                subSum = num;
                cnt++;
            } else {
                subSum += num;
            }
        }
        return cnt <= k;
    }
};