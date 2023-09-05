class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        /*
        // Brute Force
        // TC: O(logn)
        // SC: O(n)
        vector<int> result;
        for (auto const& num : nums) {
            result.push_back(num * num);
        }

        sort(result.begin(), result.end());
        return result;
        */

        // Two pointer
        // TC: O(n)
        // SC: O(n)
        vector<int> result;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int leftNum = nums[left] * nums[left];
            int rightNum = nums[right] * nums[right];
            if (leftNum > rightNum) {
                result.push_back(leftNum);
                left++;
            } else {
                result.push_back(rightNum);
                right--;
            }
        }

        // reverse
        reverse(result.begin(), result.end());
        return result;
    }
};