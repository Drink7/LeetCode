class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Copy a larger space (numsCopy) which width is nums + (nums.size() - k)
        // and assign the nums from the array numsCopy, starting by nums.size() - (numsCopy).end();
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        int actualK = k % n;
        vector<int> numsCopy(nums.begin(), nums.end());
        // copy nums.size() - k element to numsCopy
        for (int i = 0; i < n - actualK; i++) {
            numsCopy.push_back(nums[i]);
        }

        // assign the nums
        nums.assign(numsCopy.begin() + n - actualK, numsCopy.end());
    }
};