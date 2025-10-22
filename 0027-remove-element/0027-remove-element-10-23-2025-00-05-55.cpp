class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // index record where we put the num != val
        // TC: O(n)
        // SC: O(1)
        int id = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                swap(nums[i], nums[id]);
                id++;
            }
        }
        return id;
    }
};