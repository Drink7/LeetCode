class Solution {
public:
    void sortColors(vector<int>& nums) {
        // head, tail pointer
        // 2, 0, 2, 1, 1, 1
        // 1, 0, 2, 1, 1, 2
        // ^           ^
        // 2, 0, 1
        // 1, 0, 2
        // 0, 1, 2
        // two pointers, if head >= tail, break
        // when 2 switch to tail, tail index--
        // when head == 0, head indx ++, or continue swapping
        // TC: O(n)
        // SC: O(n)
        int index = 0;
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while (index <= right) {
            if (nums[index] == 2) {
                swap(nums[index] , nums[right]);
                right--;
            } else if (nums[index] == 0) {
                swap(nums[index] , nums[left]);
                index++;
                left++;
            } else {
                index++;
            }
        }
    }
};