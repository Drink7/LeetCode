class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // two pointer
        // Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.
        // then Find the largest index l greater than k such that a[k] < a[l].
        // Swap the value of a[k] with that of a[l].
        // Reverse the sequence from a[k + 1] up to and including the final element a[n].
        // TC: O(n)
        // SC: O(1)
        int n = nums.size();
        int index = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            // it is the last permutation, just reverse
            reverse(nums.begin(), nums.end());
            return;
        }

        int minIndex = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > nums[index]) {
                minIndex = i;
                break;
            }
        }

        // find index ~ n, the abs val minimum
        swap(nums[index], nums[minIndex]);

        reverse(nums.begin() + index + 1, nums.end());
    }
};