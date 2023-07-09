class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // insertion sort
        // TC: O(n^2)
        // SC: O(n)
        int zeroStart = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                int j = i - 1;
                int val = nums[i];
                for (; j >= zeroStart; j--) {
                    nums[j + 1] = nums[j];
                }
                nums[j + 1] = val;
                zeroStart++;
            }
        }
    }
};