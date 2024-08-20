class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // two pointer
        // compare left & right pointer square
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        vector<int> result(n, 0);
        int index = n - 1;
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int leftNum = nums[left] * nums[left];
            int rightNum = nums[right] * nums[right];
            if (leftNum > rightNum) {
                result[index] = leftNum;
                left++;
            } else {
                result[index] = rightNum;
                right--;
            }
            index--;
        }
        return result;
    }
};