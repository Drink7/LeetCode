class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // no more space
        // TC: O(n)
        // SC: O(1)
        // move all non-zero to front
        // index = 0, zero_index = 0;
        // swap when value != zero, and zero_index++;
        int index = 0, zero_index = 0;
        int n = nums.size();
        while (index < n) {
            if (nums[index] != 0) {
                swap(nums[index], nums[zero_index]);
                zero_index++;
            }
            index++;
        }
    }
};