class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // TC: O(n^3)
        // SC: O(1)
        // The same method as 3sum
        // sort, and find answer, also skip dupilcate
        // notice big number
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < n - 3; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                for (int j = i + 1; j < n - 2; j++) {
                    if (j == i + 1 || nums[j] != nums[j - 1]) {
                        int left = j + 1;
                        int right = n - 1;
                        while (left < right) {
                            long sum = (long) nums[i] + (long) nums[j] + (long) nums[left] + (long) nums[right];
                            if (sum == target) {
                                result.push_back({nums[i], nums[j], nums[left], nums[right]});

                                // skip duplicate
                                left++;
                                right--;
                                while (left < right && nums[left] == nums[left - 1]) {
                                    left++;
                                }
                                while (left < right && nums[right] == nums[right + 1]) {
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
            }
        }
        return result;
    }
};