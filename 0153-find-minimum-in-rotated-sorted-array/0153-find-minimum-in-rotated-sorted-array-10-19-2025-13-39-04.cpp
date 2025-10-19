class Solution {
public:
    int findMin(vector<int>& nums) {
        // nums[n - 1] is minimum or > than minimum
        // compare
        // if mid > last
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[nums.size() - 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};