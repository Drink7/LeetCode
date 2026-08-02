class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // sort
        // i, j, k find 3 elemtns
        // fix i, j, k two pointer 
        // find 3 sum - target smallest
        // TC: O(nlogn + n^2) -> O(n^2)
        // SC: O(1)
        int closetSum = nums[0] + nums[1] + nums[2];
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int threeSum = nums[i] + nums[left] + nums[right];
                if (abs(threeSum - target) < abs(closetSum - target)) {
                    closetSum = threeSum;
                }

                if (threeSum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return closetSum;
    }
};