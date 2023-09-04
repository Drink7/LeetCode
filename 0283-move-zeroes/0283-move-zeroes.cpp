class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // two pointer and traverse the nums array
        // TC: O(n)
        // SC: O(1)
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[index]);
                index++;
            }
        }
    }
};