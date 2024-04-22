class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        // two pointer
        // TC: O(n^2)
        // SC: O(1)
        int n = nums.size();
        int left = 0;        
        int result = 0;
        while (left < n) {
            int right = left;
            while (right < n) {
                if (abs(nums[left] - nums[right]) <= min(nums[left], nums[right])) {
                    result = max(result, nums[left] ^ nums[right]);
                }
                right++;
            }
            left++;
        }
        return result;
    }
};