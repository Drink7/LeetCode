class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // Two pointer
        // TC: O(n)
        // SC: O(1)
        int n = nums.size();
        int index = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != val) {
                swap(nums[i], nums[index]);
                index++;
            }
        }
        return index;
    }
};