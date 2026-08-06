class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 1-indexed
        // exactly one solution, may not use the same element twice
        // already sorted in non-decreasing order
        // Two pointer
        // TC: O(n)
        // SC: O(1)
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return {left + 1, right + 1};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {-1, -1};
    }
};