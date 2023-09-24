class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // TC: (m * nlogn), m is strs length, n is average string length
        // SC: O(m)
        unordered_map<string, vector<string>> dict;
        for (auto const& str : strs) {
            string pattern = str;
            sort(pattern.begin(), pattern.end());
            dict[pattern].push_back(str);
        }

        vector<vector<string>> result;
        for (auto const& p: dict) {
            result.push_back(p.second);
        }
        return result;
    }
};