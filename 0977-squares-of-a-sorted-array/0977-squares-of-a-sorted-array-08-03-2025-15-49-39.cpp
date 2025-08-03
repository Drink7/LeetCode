class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // two pointer
        // add bigger one to result
        // final reverse
        // TC: O(n)
        // SC: O(1)
        int left = 0, right = nums.size() - 1;
        vector<int> result;
        while (left <= right) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];
            if (leftSquare > rightSquare) {
                result.push_back(leftSquare);
                left++;
            } else {
                result.push_back(rightSquare);
                right--;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};