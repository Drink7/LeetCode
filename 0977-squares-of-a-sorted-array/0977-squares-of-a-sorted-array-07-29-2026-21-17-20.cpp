class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // two pointer and insert the bigger one to array
        // reverse the array
        // TC: O(n)
        // SC: O(1)
        vector<int> result;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];
            if (leftSquare >= rightSquare) {
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