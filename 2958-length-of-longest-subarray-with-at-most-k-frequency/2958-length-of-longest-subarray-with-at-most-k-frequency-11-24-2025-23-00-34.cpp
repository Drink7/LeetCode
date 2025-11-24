class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        // longest good subarray -> sliding window
        // use unordered_map to store freq
        // if freq[nums[right]] > k, move left
        // 
        unordered_map<int, int> freq;
        int left = 0, right = 0;
        int n = nums.size();
        int result = 0;
        while (right < n) {
            freq[nums[right]]++;
            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }
            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }
};