class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Use two pointer and check the sum
        // if the sum is bigger than target, move right
        // if the sum is smaller than target, move left
        // TC: O(n)
        // SC: O(1)

        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return {left + 1, right + 1};
            } else if (sum > target) {
                right--;
            } else {
                left++;
            }
        }
        // impossible
        return {-1, -1};
    }
};