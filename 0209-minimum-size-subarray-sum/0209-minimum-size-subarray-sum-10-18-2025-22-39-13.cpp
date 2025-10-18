class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // sliding window
        // right keep moving
        // if sum >= target, keep moving left untirl sum < target, move right
        // TC: O(n)
        // SC: O(n)
        int left = 0, right = 0;
        int n = nums.size();
        int result = n + 1, sum = 0;
        while (right < n) {
            sum += nums[right];
            while (sum >= target) {
                result = min(result, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return result == n + 1 ? 0 : result;
    }
};