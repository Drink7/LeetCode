class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // two pointer
        // TC: O(n^2)
        // SC: O(1)

        // sort first
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i == 0 || nums[i - 1] != nums[i]) {
                int target = 0 - nums[i];
                int left = i + 1;
                int right = n - 1;
                while (left < right) {
                    int sum = nums[left] + nums[right];
                    if (sum == target) {
                        result.push_back({nums[i], nums[left], nums[right]});
                        
                        left++;
                        right--;
                        
                        // skip left
                        while (left < right && nums[left - 1] == nums[left]) {
                            left++;
                        }

                        // skip right
                        while (left < right && nums[right + 1] == nums[right]) {
                            right--;
                        }
                    } else if (sum > target) {
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