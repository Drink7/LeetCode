class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        /*
        // pick smallest each time
        // sort first
        // traverse
        // TC: O(n^2)
        // SC: O(1)
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                count++;
                int sub = nums[i];
                for (int j = i; j < n; j++) {
                    nums[j] -= sub;
                }
            }
        }
        return count;
        */

        // More elegant
        // Set
        // TC: O(n)
        // SC: O(n)
        unordered_set<int> elements;
        for (auto const& num : nums) {
            if (num != 0) {
                elements.insert(num);
            }
        }
        return elements.size();
    }
};