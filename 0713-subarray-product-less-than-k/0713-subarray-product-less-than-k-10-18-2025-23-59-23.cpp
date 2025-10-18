class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // subarray -> sliding window
        // right keep going
        // if sum >= k, left++, until sum < k
        // result cnt = right - left + 1 // 以 right 為結尾的 subarray 數量 the number which subarray is end with nums[right]
        // TC: O(n)
        // SC: O(1)

        int left = 0, right = 0;
        int n = nums.size();
        int result = 0;
        int sum = 1;
        while (right < n) {
            sum = sum * nums[right];
            while (left <= right && sum >= k) {
                sum = sum / nums[left];
                left++;
            }
            result += (right - left + 1); // the subarray number which is end with nums[right]
            right++;
        }
        return result;
    }
};