class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /*
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
        */

        // TC: O(nlogn)
        // SC: O(1)
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) return true;
        }
        return false;
    }
};