class Solution {
public:
    void sortColors(vector<int>& nums) {
        // two pointer
        // TC: O(n)
        // SC: O(1)
        int left = 0;
        int right = nums.size() - 1;
        int cur = left;
        while (cur <= right) {
            if (nums[cur] == 2) {
                swap(nums[cur], nums[right]);
                right--;
            } else if (nums[cur] == 1) {
                cur++;
            } else {
                swap(nums[cur], nums[left]);
                left++;
                cur++;
            }
        }
    }
};