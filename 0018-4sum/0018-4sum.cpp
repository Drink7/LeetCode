class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // sort first
        // Same concept in 3Sum but would be O(n^3) here, TLE?
        // TC: O(n^3)
        // SC: O(1)
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }

            long long int remain3Sum = target - nums[i];

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j - 1] == nums[j]) {
                    continue;
                }
                
                long long int remain2Sum = remain3Sum - nums[j];
                int left = j + 1;
                int right = n - 1;
                while (left < right) {
                    long long int twoSum = nums[left] + nums[right];
                    if (remain2Sum == twoSum) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        // skip repeat
                        while (left < right && nums[left - 1] == nums[left]) {
                            left++;
                        }
                        // skip repeat
                        while (left < right && nums[right + 1] == nums[right]) {
                            right--;
                        }
                    } else if (remain2Sum < twoSum) {
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