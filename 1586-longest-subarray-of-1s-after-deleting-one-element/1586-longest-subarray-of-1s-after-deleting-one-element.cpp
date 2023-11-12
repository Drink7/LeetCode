class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // similar to Max Consecutive Ones III
        // but k = 1
        // TC: O(n)
        // SC: O(1)
        int n = nums.size();
        int left = 0;
        int right = 0;
        int result = 0;
        int oneCnt = 0;
        while (right < n) {
            if (nums[right] == 1) {
                oneCnt++;
            }

            while ((right - left + 1) - oneCnt > 1) {
                if (nums[left] == 1) {
                    oneCnt--;
                }
                left++;
            }

            result = max(result, right - left + 1 - 1);
            right++;
        }

        return (result == n) ? n - 1 : result;
    }
};