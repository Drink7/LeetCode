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
        /*
        // Assign the nums from the array numsCopy
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        vector<int> numsCopy = nums;
        for (int i = 0; i < n; i++) {
            nums[(i + k) % n] = numsCopy[i];
        }
        */
        // Refer to https://leetcode.com/problems/rotate-array/solutions/1730142/java-c-python-a-very-very-well-detailed-explanation/
        // Divide into two part by n-k, k
        // Reverse n-k part and k part
        // Rotate n-k part and k part
        // TC: O(n)
        // SC: (1)
        int n = nums.size();
        int rotateK = k % n;
        // Reverse n-k part
        // Reverse is [first, last)]
        reverse(nums.begin(), nums.begin() + n - rotateK);
        // Reverse k part
        reverse(nums.begin() + n - rotateK, nums.end());
        // Then rotate
        int right = 0;
        int left = n - 1;
        while (right < left) {
            swap(nums[right], nums[left]);
            right++;
            left--;
        }
    }
};