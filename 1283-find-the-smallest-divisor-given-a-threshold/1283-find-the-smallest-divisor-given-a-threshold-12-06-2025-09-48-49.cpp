class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        // koko eat banana
        // binar search the answer, from 1 to max(nums)
        // find the first divisor
        // TC: O(logn)
        // SC: O(1)
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            // find the first mide, its sumResult is the first <= threshold
            if (sumResult(mid, nums) > threshold) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    int sumResult(int divisor, vector<int>& nums) {
        int sum = 0;
        for (auto const& num : nums) {
            sum += (num + divisor - 1) / divisor;
        }
        return sum;
    }
};