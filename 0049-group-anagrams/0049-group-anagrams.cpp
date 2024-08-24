class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // sort each str in strs
        // store vector in map
        // return result in vector<vector<string>> way
        // TC: O(m * nlogn)
        // SC: O(m * n)
        unordered_map<string, vector<string>> groupMap;
        vector<vector<string>> result;
        for (auto const& str : strs) {
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            groupMap[sorted].push_back(str);
        }

        // return result
        for (auto const& p : groupMap) {
            result.push_back(p.second);
        }
        return result;
    }
};