class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // XOR -> x XOR x == 0
        // TC: O(n)
        // SC: O(1)
        int num = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            num ^= nums[i];
        }
        return num;
    }
};