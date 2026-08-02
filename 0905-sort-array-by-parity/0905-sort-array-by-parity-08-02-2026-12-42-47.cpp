class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        // similar to Move zeros
        // TC: O(n)
        // SC: O(1)
        int evenIndex = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                // even, need to exchange
                swap(nums[i], nums[evenIndex++]);
            }
        }
        return nums;
    }
};