class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // same concept of 3 sum
        // sort
        // int i = 0, int j = i + 1, int left = j + 1, int right = nums.size() - 1
        // nums[a] + nums[b] + nums[c] + nums[d] == target
        // > target, move right
        // < target, move left
        // TC: O(n^3)
        // SC: O(1)
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i - 1] != nums[i]) {
                for (int j = i + 1; j < nums.size(); j++) {
                    if (j == i + 1 || nums[j - 1] != nums[j]) {
                        int left = j + 1;
                        int right = nums.size() - 1;
                        while (left < right) {
                            long long sum = (long long) nums[i] + nums[j] + nums[left] + nums[right];
                            if (sum == target) {
                                result.push_back({nums[i], nums[j], nums[left], nums[right]});
                                left++;
                                while (left < right && nums[left - 1] == nums[left]) {
                                    left++;
                                }
                                right--;
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
            }
        }
        return result;
    }
};