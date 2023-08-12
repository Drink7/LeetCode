class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        /*
        // Sort first
        // Same concept in 3Sum but would be O(n^3) here
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
        */

        // More general, N-Sum (Base on two sum)
        sort(nums.begin(), nums.end());
        return NSum(nums, 0, nums.size() - 1, target, 4);
    }
    vector<vector<int>> NSum(vector<int>& nums, int left, int right, long long int target, int n) {
        vector<vector<int>> results;
        if (right - left + 1 < n || (long long int) nums[left] * n > target || (long long int)nums[right] * n < target) {
            return results;
        }
        if (n == 2) {
            return twoSum(nums, left, right, target);
        } else {
            for (int i = left; i < right; i++) {
                if (i > left && nums[i - 1] == nums[i]) {
                    continue;
                }
                int element = nums[i];
                vector<vector<int>> resultFromNSum = NSum(nums, i + 1, right, target - element, n - 1);
                for (vector<int> v : resultFromNSum) {
                    v.push_back(element);
                    results.push_back(v);
                }
            }
        }
        return results;
    }
    
    vector<vector<int>> twoSum(vector<int>& nums, int left, int right, long long int target) {
        vector<vector<int>> result;
        
        while (left < right) {
            long long int sum = nums[left] + nums[right];
            if (sum == target) {
                result.push_back({nums[left], nums[right]});
                left++;
                right--;

                // skip repeat
                while (left < right && nums[left - 1] == nums[left]) {
                    left++;
                }

                while (left < right && nums[right + 1] == nums[right]) {
                    right--;
                }
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return result;
    }
};