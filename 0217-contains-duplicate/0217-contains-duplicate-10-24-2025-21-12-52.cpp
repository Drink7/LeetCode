class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /*
        // sort
        // TC: O(n)
        // SC: O(1)
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                return true;
            }
        }
        return false;
        */

        // set
        // TC: O(n)
        // SC: O(n)
        unordered_set<int> dict;
        for (auto const& num : nums) {
            if (dict.count(num) > 0) {
                return true;
            }
            dict.insert(num);
        }
        return false;
    }
};