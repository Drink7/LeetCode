class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Two pointer?
        // The pointer would point to the distic number position
        // TC: O(n)
        // SC: O(1)
        int pointer = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[pointer] = nums[i];
                pointer++;
            }
        }
        return pointer;
    }
};