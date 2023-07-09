class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        /*
        // Hash Table
        // TC: O(n)
        // SC: O(n)
        unordered_set<int> nums1Set, intersecSet;
        vector<int> ans;
        for (auto const& num : nums1) {
            nums1Set.insert(num);
        }

        for (auto const& num : nums2) {
            if (nums1Set.count(num)) {
                intersecSet.insert(num);
            }
        }

        ans.assign(intersecSet.begin(), intersecSet.end());
        return ans;
        */

        // Hash Table + optimization
        // TC: O(n)
        // SC: O(n)
        unordered_set<int> nums1Set(nums1.begin(), nums1.end());
        vector<int> ans;
        for (auto const& num : nums2) {
            if (nums1Set.count(num)) {
                ans.push_back(num);
                nums1Set.erase(num);
            }
        }
        return ans;
    }
};