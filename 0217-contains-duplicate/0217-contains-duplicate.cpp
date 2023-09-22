class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // hash set
        // TC: O(n)
        // SC: O(n)
        unordered_set<int> dict;
        for (auto const& num : nums) {
            if (dict.count(num)) {
                return true;
            }
            dict.insert(num);
        }
        return false;
    }
};