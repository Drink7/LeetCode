class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Two pointer
        // Sort array first
        // Fix one element then do two pointer to sum the one element before and check we
        // can get zero or not
        // TC: O(n^2)
        // SC: O(1)
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;
        for (int i = 0; i < n; i++) {
            // ignore duplicate element
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }

            int first = nums[i];
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int internalSum = nums[left] + nums[right];
                if (first + internalSum == 0) {
                    result.push_back({first, nums[left], nums[right]});
                    left++;
                    right--;
                    // ignore duplicate element
                    while (left < right && nums[left - 1] == nums[left]) {
                        left++;
                    }

                    // ignore duplicate element
                    while (left < right && nums[right + 1] == nums[right]) {
                        right--;
                    }
                } else if (first + internalSum > 0) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return result;
    }
};