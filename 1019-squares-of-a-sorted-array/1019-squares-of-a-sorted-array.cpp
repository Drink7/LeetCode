class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        /*
        // Brute force
        // square each element then sort
        // TC: O(n + nlogn)
        // SC: O(1)
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] * nums[i];
        }

        sort(nums.begin(), nums.end());
        return nums;
        */

        // Two pointer, compare the left pointer element square and right pointer element square
        // choose the larger, and then move the larger one pointer
        // we would reverse the array in the end
        // TC: O(n)
        // SC: O(n)
        vector<int> result;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];
            if (leftSquare < rightSquare) {
                result.push_back(rightSquare);
                right--;
            } else {
                result.push_back(leftSquare);
                left++;
            }
        }

        // reverse the vector
        reverse(result.begin(), result.end());
        return result;
    }
};