class Solution {
public:
    void sortColors(vector<int>& nums) {
        // dutch national flags problem
        // TC: O(n)
        // SC: O(1)
        int left = 0;
        int right = nums.size() - 1;
        int cur = 0;
        // 2 0 1
        // 1 0 2
        // 1 0 2
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