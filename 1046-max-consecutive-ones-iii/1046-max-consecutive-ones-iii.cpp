class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // Similar to 424.  Longest Repeating Character Replacement
        // TC: O(n)
        // SC: O(1)
        vector<int> count(2, 0);
        int n = nums.size();
        int left = 0;
        int right = 0;
        int result = 0;
        while (right < n) {
            count[nums[right]]++;

            // check if we can flip k or not
            // if we can not, move left pointer
            while (right - left + 1 > count[1] + k) {
                count[nums[left]]--;
                left++;
            }
            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }
};