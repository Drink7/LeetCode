class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Use XOR (a^a = 0)
        // TC: O(n)
        // SC: O(1)
        int a = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            a = a ^ nums[i];
        }
        return a;
    }
};