class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // hash table
        // TC: O(n)
        // SC: O(n)
        unordered_map<int, int> dict;
        vector<int> result;
        for (auto const& num : nums) {
            dict[num]++;
        }

        for (auto const& p : dict) {
            if (p.second > nums.size() / 3) {
                result.push_back(p.first);
            }
        }
        return result;
    }
};