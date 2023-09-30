class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // XOR two num
        // TC: O(n)
        // SC: O(1)
        int result = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            result = result ^ i ^ nums[i];
        }
        return result;
    }
};