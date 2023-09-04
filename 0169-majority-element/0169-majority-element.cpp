class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // hash table
        // TC: O(n)
        // SC: O(n)
        unordered_map<int, int> dict;
        for (auto const& num : nums) {
            dict[num]++;
        }

        int majorityCount = 0;
        int majorityElement = 0;
        for (auto const& p : dict) {
            if (p.second > majorityCount) {
                majorityCount = p.second;
                majorityElement = p.first;
            }
        }
        return majorityElement;
    }
};