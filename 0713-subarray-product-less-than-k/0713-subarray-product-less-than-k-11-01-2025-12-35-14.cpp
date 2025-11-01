class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // sliding window
        // if subarray product meet, the count will increase right - left + 1
        // 1 1 2, k 4
        // [1], [1], [1,1]
        // TC: O(n)
        // SC: O(1)
        int left = 0, right = 0;
        long long ans = 1;
        int cnt = 0;
        int n = nums.size();
        while (right < n) {
            ans = ans * nums[right];
            while (left <= right && ans >= k) {
                ans = ans / nums[left];
                left++;
            }
            cnt += (right - left + 1);
            right++;
        }
        return cnt;
    }
};