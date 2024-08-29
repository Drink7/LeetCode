class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // two pointer
        // TC: O(n^2)
        // SC: O(1)
        vector<vector<int>> result;
        int n = nums.size();

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                int target = -nums[i];
                int j = i + 1;
                int k = n - 1;
                while (j < k) {
                    int sum = nums[j] + nums[k];
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[k]});

                        // avoid duplicate
                        j++;
                        k--;

                        while (j < k && nums[j] == nums[j - 1]) {
                            j++;
                        }

                        while (j < k && nums[k] == nums[k + 1]) {
                            k--;
                        }
                    } else if (sum > target) {
                        k--;
                    } else {
                        j++;
                    }
                }
            }
        }
        return result;
    }
};