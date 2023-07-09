class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // TC: O(n)
        // SC: O(1)
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
    }
};