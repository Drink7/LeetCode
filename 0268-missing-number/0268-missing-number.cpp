class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // XOR number itself would be zero
        // 0 0 0
        // 1 0 1
        // 0 1 1
        // 1 1 0
        // TC: O(n)
        // SC: O(1)
        int n = nums.size();
        int result = n;
        for (int i = 0; i < nums.size(); i++) {
            result = (result ^ i ^ nums[i]);
        }
        return result;
    }
};