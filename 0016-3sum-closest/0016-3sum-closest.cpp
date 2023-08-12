class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Two pointer, skip repeat
        // First sort array, then calculate each abs(sum - target) to find the minimum
        // TC: O(n^2)
        // SC: O(1)
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int minSum = INT_MAX;
        int minDiff = INT_MAX;
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
                if (minDiff > abs(sum - target)) {
                    minDiff = abs(sum - target);
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