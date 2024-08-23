class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // set
        // TC: O(n)
        // SC: O(n)
        unordered_set<int> numSet;
        for (auto const& num : nums) {
            if (numSet.count(num) > 0) {
                return true;
            }
            numSet.insert(num);
        }
        return false;
    }
};