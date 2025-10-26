class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort, then ignore duplicate
        // use two pointer to find nums[i] + nums[j] + nums[k] = 0
        // TC: O(n^2)
        // SC: O(1)
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                int left = i + 1;
                int right = n - 1;
                int remain = -nums[i];
                while (left < right) {
                    if (nums[left] + nums[right] > remain) {
                        right--;
                    } else if (nums[left] + nums[right] < remain) {
                        left++;
                    } else {
                        result.push_back({nums[i], nums[left], nums[right]});

                        left++;
                        while (left < right && nums[left] == nums[left - 1]) {
                            left++;
                        }

                        right--;
                        while (left < right && nums[right] == nums[right + 1]) {
                            right--;
                        }
                    }
                }
            }
        }
        return result;
    }
};