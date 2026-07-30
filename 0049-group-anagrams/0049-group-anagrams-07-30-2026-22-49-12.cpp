class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // use a unordered_map to store str
        // the unordered_map keys are sorted result
        // TC: O(n * mlogm), m is str length, n is strs.length
        // SC: O(n * m)
        unordered_map<string, vector<string>> dict;
        for (auto const& str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            dict[tmp].push_back(str);
        } 

        // store to result
        vector<vector<string>> result;
        for (auto const& p : dict) {
            result.push_back(p.second);
        }
        return result;
    }
};