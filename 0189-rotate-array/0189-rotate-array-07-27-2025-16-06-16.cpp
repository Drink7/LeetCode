class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*
        // Brute Force (TLE)
        // TC: O(kn)
        // SC: O(1)
        int n = nums.size();
        k = k % n;
        for (int i = 0; i < k; i++) {
            int num = nums.back();
            nums.pop_back();
            nums.insert(nums.begin(), num);
        }
        */
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        int index = 0;
        k = k % n;
        vector<int> copyNums(n);
        for (int i = 0; i < n; i++) {
            if (i < k) {
                copyNums[i] = nums[n - k + i];
            } else {
                copyNums[i] = nums[index++];
            }
        }
        nums = copyNums;
    }
};