class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // hashset
        unordered_set<int> intSet;
        for (auto const& num : nums) {
            if (intSet.count(num)) {
                return true;
            } else {
                intSet.insert(num);
            }
        }
        return false;
    }
};