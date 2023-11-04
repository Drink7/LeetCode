class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort the nums first
        // fix the first element, then use two pointer in the remain array
        // note the repeated cases
        // TC: O(n^2)
        // SC: O(1)
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= 1 && nums[i] == nums[i - 1]) {
                continue;
            }

            int num = nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = num + nums[left] + nums[right];
                if (sum > 0) {
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    result.push_back({num, nums[left], nums[right]});
                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
            }
        }
        return result;
    }
};