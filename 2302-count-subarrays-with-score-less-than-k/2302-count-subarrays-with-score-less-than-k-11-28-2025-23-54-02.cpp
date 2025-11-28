class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        // sliding window
        // sum += nums[right]
        // if sum * (right - left + 1) < k
        // -> count += right - left + 1
        // nums[right] be the end and nums[left] be the start subarray count
        // = right - left + 1
        // else
        // move left, left -= nums[left]
        // TC: O(n)
        // SC: O(1) 
        int left = 0, right = 0, n = nums.size();
        long long cnt = 0;
        long long sum = 0;
        while (right < n) {
            sum += nums[right];
            while (sum * (right - left + 1) >= k) {
                // move left
                sum -= nums[left];
                left++;
            }
            // count
            cnt += right - left + 1;
            right++;
        }
        return cnt;
    }
};