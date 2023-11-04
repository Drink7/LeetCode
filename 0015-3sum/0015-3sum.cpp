class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // first sort
        // duplicate prevention
        // TC: O(nlogn + n^2)
        // SC: O(1)
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // duplicate prevention
            if (i == 0 || nums[i] != nums[i - 1]) {
                int left = i + 1;
                int right = n - 1;
                while (left < right) {
                    if (nums[i] + nums[left] + nums[right] == 0) {
                        result.push_back({nums[i], nums[left], nums[right]});

                        // duplicate prevention
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left - 1]) {
                            left++;
                        }

                        while (left < right && nums[right] == nums[right + 1]) {
                            right--;
                        }
                    } else if (nums[i] + nums[left] + nums[right] > 0) {
                        right--;
                    } else {
                        left++;
                    }
                }
            }
        }
        return result;
    }
};