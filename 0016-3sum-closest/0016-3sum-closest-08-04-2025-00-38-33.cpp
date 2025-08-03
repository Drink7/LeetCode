class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // sort first
        // same 3 sum process but use abs to calculate closet
        // TC: O(n^2)
        // SC: O(1)
        sort(nums.begin(), nums.end());
        int minSum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size(); i++) {
            if (i >= 1 && nums[i] == nums[i - 1]) {
                continue;
            }

            int num = nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = num + nums[left] + nums[right];
                if (abs(minSum - target) > abs(sum - target)) {
                    minSum = sum;
                }

                if (sum > target) {
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    return sum;
                }
            }
        }
        return minSum;
    }
};