class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Two pointer?
        // Set zero pointer and forward pointer
        // TC: O(n)
        // SC: O(1)
        int pointer = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[pointer], nums[i]);
                pointer++;
            }
        }
    }
};