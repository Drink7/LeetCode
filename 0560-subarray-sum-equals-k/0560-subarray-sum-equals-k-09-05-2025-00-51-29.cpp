class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // prefix sum + hash table
        // TC: O(n), n is nums size
        // SC: O(n)
        unordered_map<int, int> prefixDict;
        prefixDict[0] = 1;

        int prefix = 0;
        int count = 0;
        for (auto const& num : nums) {
            prefix += num;

            if (prefixDict.count(prefix - k) > 0) {
                count += prefixDict[prefix - k];
            }

            prefixDict[prefix]++;
        }
        return count;
    }
};