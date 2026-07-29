class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /*
        // insertion sort
        // 0 1 0 3 12
        // 1 0 3 12 12
        // 1 0 3 12 0
        // 1 3 12 12 0
        // 1 3 12 0 0
        // TC: O(n^2)
        // SC: O(1)
        int n = nums.size();
        int zeroIdx = n - 1;
        // assume last part are zeros
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                if (nums[j] == 0) {
                    while (j < i) {
                        nums[j] = nums[j + 1];
                        j++;
                    }
                    nums[zeroIdx--] = 0;
                }
            }
        }
        */

        int zeroId = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[zeroId++]);
            }
        }
    }
};