class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // unordered_map, and find count > n /2
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        unordered_map<int, int> dict;
        for (auto const& num : nums) {
            dict[num]++;
        }

        for (auto const& p : dict) {
            if (p.second >= n / 2 + 1) {
                return p.first;
            }
        }
        return -1; // impossible;
    }
};