class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // two pointer
        // TC: O(n)
        // SC: O(1)
        int uniqueId = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (uniqueId < 2 || nums[i] > nums[uniqueId - 2]) {
                nums[uniqueId++] = nums[i];
            }
        }
        return uniqueId;
    }
};