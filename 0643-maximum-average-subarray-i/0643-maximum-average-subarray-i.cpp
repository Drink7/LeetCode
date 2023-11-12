class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // sliding window with fixed window size k
        // TC: O(n)
        // SC: O(1)
        int n = nums.size();
        int left = 0;
        int right = 0;
        int result = INT_MIN;
        int count = 0;
        while (right < n) {
            count += nums[right];
            if (right >= k - 1) {
                result = max(result, count);

                // move to next
                count = count - nums[left];
                left++;
            }
            right++;
        }
        return (double) result / k;
    }
};