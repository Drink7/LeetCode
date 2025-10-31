class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int cnt = 0;
        int maxVal = -1;
        while (left < right) {
            if (nums[left] + nums[right] < k) {
                maxVal = max(maxVal, nums[left] + nums[right]);
                left++;
            } else {
                right--;
            }
        }
        return maxVal;
    }
};