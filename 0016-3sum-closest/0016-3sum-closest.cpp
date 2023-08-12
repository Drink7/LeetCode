class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Two pointer, skip repeat
        // First sort array, then calculate each abs(sum - target) to find the minimum
        // TC: O(n^2)
        // SC: O(1)
        if (nums.size() < 3) {
            return 0;
        }

        sort(nums.begin(), nums.end());
        int n = nums.size();
        // avoid using INT_MAX here
        int minSum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n; i++) {
            // skip repeat
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            int first = nums[i];
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int sum = first + nums[left] + nums[right];
                if (abs(target - minSum) > abs(target - sum)) {
                    minSum = sum;
                }
                if (sum == target) {
                    return target;
                } else if (sum > target) {
                    right--;
                    // skip repeat
                    while (left < right && nums[right + 1] == nums[right]) {
                        right--;
                    }
                } else {
                    left++;
                    // skip repeat
                    while (left < right && nums[left -1] == nums[left]) {
                        left++;
                    }
                }
            }
        }
        return minSum;
    }
};