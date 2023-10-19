class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /*
        // hash set
        // TC: O(n)
        // SC: O(n)
        unordered_set<int> numSet;
        for (int i = 0; i < nums.size(); i++) {
            if (numSet.count(nums[i])) {
                return true;
            }
            numSet.insert(nums[i]);
        }
        return false;
        */
        // sort
        // TC: O(nlogn)
        // SC: O(1)
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }
        return false;
    }
};