class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /*
        // sort and traverse
        // TC: O(nlogn)
        // SC: O(1)
        sort(nums.begin(), nums.end());
        int prev = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (prev == nums[i]) {
                return true;
            }
            prev = nums[i];
        }
        return false;
        */
        // hashset
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