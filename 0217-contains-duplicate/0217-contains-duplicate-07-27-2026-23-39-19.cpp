class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // use set to check duplicate (existed?)
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