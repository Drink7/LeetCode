class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // sort first
        // same 3 sum process but use abs to calculate closet
        // TC: O(n^2)
        // SC: O(1)
        sort(nums.begin(), nums.end());
        int result = INT_MAX;
        int minDiff = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= 1 && nums[i] == nums[i - 1]) {
                continue;
            }

            int num = nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = num + nums[left] + nums[right];
                if (sum > target) {
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    return sum;
                }
                
                int diff = abs(sum - target);
                if (minDiff > diff) {
                    minDiff = diff;
                    result = sum;
                }
            }
        }
        return result;
    }
};