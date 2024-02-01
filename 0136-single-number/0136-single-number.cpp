class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // XOR
        // TC: O(n)
        // SC: O(1)
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            result ^= nums[i];
        }
        return result;
    }
};