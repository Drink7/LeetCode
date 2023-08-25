class Solution {
public:
    void sortColors(vector<int>& nums) {
        // use two pointer with current pointer
        // TC: O(n)
        // SC: O(1)
        int left = 0;
        int right = nums.size() - 1;
        int cur = left;
        while (cur <= right) {
            if (nums[cur] == 2) {
                swap(nums[cur], nums[right]);
                right--;
            } else if (nums[cur] == 0) {
                swap(nums[cur], nums[left]);
                left++;
                cur++;
            } else {
                cur++;
            }
        }
    }
};