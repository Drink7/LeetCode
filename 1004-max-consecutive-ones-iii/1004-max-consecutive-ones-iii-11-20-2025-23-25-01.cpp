class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // sliding windows
        // if nums[right] == 0, flip++
        // while flip > k, move left
        // if nums[left] == 0, flip--
        // len = max(right - left + 1, len)
        // TC: O(n)
        // SC: O(1)
        int flip = 0;
        int left = 0, right = 0;
        int n = nums.size();
        int result = 0;
        while (right < n) {
            if (nums[right] == 0) {
                flip++;
            }
            while (flip > k) {
                if (nums[left] == 0) {
                    flip--;
                }
                left++;
            }
            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }
};