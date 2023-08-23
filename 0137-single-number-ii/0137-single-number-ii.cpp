class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // hash table
        // TC: O(n)
        // SC: O(n)
        unordered_map<int, int> dict;
        for (auto const& num : nums) {
            dict[num]++;
        }

        for (auto const& p : dict) {
            if (p.second == 1) {
                return p.first;
            }
        }
        return -1;
    }
};