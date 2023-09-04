class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Brute Force
        // TC: O(n)
        // SC: O(n)
        vector<int> copyNums;
        copyNums.assign(nums.begin(), nums.end());
        int n = copyNums.size();
        int actualK = k % n;
        for (int i = 0; i < n; i++) {
            int newIndex = (i + actualK) % n;
            copyNums[newIndex] = nums[i];
        }

        for (int i = 0; i < n; i++) {
            nums[i] = copyNums[i];
        }
    }
};