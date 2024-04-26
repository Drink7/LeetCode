class Solution {
public:
    int findLHS(vector<int>& nums) {
        /*
        // unordered_map with two pass solution
        // TC: O(n)
        // SC: O(n)
        unordered_map<int, int> dict;
        int result = 0;
        for (auto const& num : nums) {
            dict[num]++;
        }

        // only find key - 1 to avoid counting twice
        for (auto const& p : dict) {
            if (dict.count(p.first - 1) > 0) {
                result = max(result, p.second + dict[p.first - 1]);
            }
        }
        return result;
        */

        // one pass
        // TC: O(n)
        // SC: O(n)
        unordered_map<int, int> dict;
        int result = 0;
        for (auto const& num : nums) {
            dict[num]++;
            if (dict.count(num - 1) > 0) {
                result = max(result, dict[num] + dict[num - 1]);
            }

            if (dict.count(num + 1) > 0) {
                result = max(result, dict[num] + dict[num + 1]);
            }
        }
        return result;
    }
};