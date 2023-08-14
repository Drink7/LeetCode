class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // Two pointer?
        // Pointer point to first val appears
        // Swap the pointer val when the next one is not equal to val
        // TC: O(n)
        // SC: O(1)
        int pointer = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                swap(nums[pointer], nums[i]);
                pointer++;
            }
        }
        return pointer;
    }
};