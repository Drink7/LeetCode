class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // remove duplicate element and return the unique element numbers
        // TC: O(n)
        // SC: O(1)
        int index = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};