class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*
        // Copy a larger space (numsCopy) which width is nums + (nums.size() - k)
        // and assign the nums from the array numsCopy, starting by nums.size() - (numsCopy).end();
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        int rotateK = k % n;
        vector<int> numsCopy(nums.begin(), nums.end());
        // copy nums.size() - k element to numsCopy
        for (int i = 0; i < n - rotateK; i++) {
            numsCopy.push_back(nums[i]);
        }

        // Assign the nums
        nums.assign(numsCopy.begin() + n - rotateK, numsCopy.end());
        */
        // Assign the nums from the array numsCopy
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        vector<int> numsCopy = nums;
        for (int i = 0; i < n; i++) {
            nums[(i + k) % n] = numsCopy[i];
        }
    }
};