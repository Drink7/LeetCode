class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // right - left + 1 - oneCnt <= k
        // TC: O(n)
        // SC: O(1)
        int n = nums.size();
        int left = 0;
        int right = 0;
        int oneCnt = 0;
        int result = 0;
        while (right < n) {
            if (nums[right] == 1) {
                oneCnt++;
            }

            while ((right - left + 1) - oneCnt > k) {
                if (nums[left] == 1) {
                    oneCnt--;
                }
                left++;
            }
            result = max(result, (right - left + 1));
            right++;
        }
        return result;
    }
};