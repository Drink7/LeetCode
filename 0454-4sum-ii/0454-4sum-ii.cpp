class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // similar concept as two sum
        // TC: O(n^2)
        // SC: O(n)
        // sum, count
        unordered_map<int, int> dict;
        int count = 0;
        for (auto const& num1 : nums1) {
            for (auto const& num2 : nums2) {
                dict[num1 + num2]++;
            }
        }

        // check if nums3 + nums4 match
        for (auto const& num3 : nums3) {
            for (auto const& num4 : nums4) {
                if (dict.count(-(num3 + num4))) {
                    count += dict[-(num3 + num4)];
                }
            }
        }
        return count;
    }
};