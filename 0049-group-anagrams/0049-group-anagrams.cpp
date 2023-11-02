class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // TC: O(m * nlogn)
        // SC: (m * n)
        unordered_map<string, vector<string>> groupDict;
        vector<vector<string>> result;
        for (auto const& str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            groupDict[tmp].push_back(str);
        }

        // add to result
        for (auto const& p : groupDict) {
            result.push_back(p.second);
        }
        return result;
    }
};