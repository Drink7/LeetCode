class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // sort first
        // use same concept of two sum
        // careful of overflow
        // TC: O(n^3)
        // SC: O(1)
        if (nums.size() < 4) {
            return {};
        }
    
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            long remain1 = target - nums[i];

            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                long remain2 = remain1 - nums[j];
                vector<vector<int>> twoSumList = twoSum(nums, j + 1, nums.size() - 1, remain2);
                for (vector<int> v : twoSumList) {
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    result.push_back(v);
                }
            }
        }
        return result;
    }

    vector<vector<int>> twoSum(vector<int>& nums, int left, int right, long long target) {
        vector<vector<int>> result;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                result.push_back({nums[left], nums[right]});
                left++;
                right--;

                // skip repeat
                while (left < right && nums[left] == nums[left - 1]) {
                    left++;
                }

                // skip repeat
                while (left < right && nums[right] == nums[right + 1]) {
                    right--;
                }
            } else if (sum > target) {
                right--;
            } else {
                left++;
            }
        }
        return result;
    }
};