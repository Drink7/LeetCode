class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        /*
        // TC: O(n^2)
        // SC: O(1)
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i + 1] > nums[i]) {
                for (int j = n - 1; j > i; j--) {
                    if (nums[j] > nums[i]) {
                        swap(nums[i], nums[j]);
                        reverse(nums.begin() + i + 1, nums.end());
                        return;
                    }
                }
            }
        }
        reverse(nums.begin(), nums.end());
        */

        // More elegant
        int n = nums.size();
        int i = n - 2;
        int j = n - 1;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};