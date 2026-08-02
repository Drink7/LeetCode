class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Dutch National Flag Algorithm
        // TC: O(n)
        // SC: O(1)
        // 2, 0, 2, 1, 1, 0
        // 0, 0, 2, 1, 1, 2
        // 0, 0, 2, 1, 1, 2
        // 0, 0, 1, 1, 2, 2
        // index
        // zero_index and two_index
        int n = nums.size();
        int index = 0, zero_index = 0, two_index = n - 1;
        while (index <= two_index) {
            if (nums[index] == 2) {
                swap(nums[index], nums[two_index]);
                two_index--;
            } else if (nums[index] == 0) {
                swap(nums[index], nums[zero_index]);
                zero_index++;
                index++;
            } else {
                index++;
            }
        }
    }
};