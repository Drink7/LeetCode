class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // sort
        // we can count number of pairs = upper
        // count number of pairs = lower - 1
        // then subtract
        // TC: O(nlogn)
        // SC: O(1)
        sort(nums.begin(), nums.end());
        return countFairPair(nums, upper) - countFairPair(nums, lower - 1);
    }

    long long countFairPair(vector<int>& nums, int target) {
        long long result = 0;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            if (nums[left] + nums[right] > target) {
                right--;
            } else {
                result += (right - left);
                left++;
            }
        }
        return result;
    }
};