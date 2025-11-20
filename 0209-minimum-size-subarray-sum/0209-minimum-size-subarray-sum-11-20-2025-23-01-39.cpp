class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // subarray -> sliding window
        // right keep going until sum >= target
        // record length
        // move left until sum < target
        // TC: O(n)
        // SC: O(1)
        int sum = 0;
        int minLen = nums.size() + 1;
        int left = 0, right = 0;
        int n = nums.size();
        while(right < n) {
            sum += nums[right];
            while (sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return minLen == nums.size() + 1 ? 0 : minLen;
    }
};