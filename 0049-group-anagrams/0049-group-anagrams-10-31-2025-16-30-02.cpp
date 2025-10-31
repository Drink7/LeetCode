class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*
        // hash map store <sorted string, original strings>
        // TC: O(mnlogn)
        // SC: O(mn)
        unordered_map<string, vector<string>> dict;
        vector<vector<string>> result;
        for (auto const& str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            dict[tmp].push_back(str);
        }

        for (auto const& [a, b] : dict) {
            result.push_back(b);
        }
        return result;
        */

        unordered_map<string, vector<string>> dict;
        vector<vector<string>> result;
        for (auto const& str : strs) {
            // counting char
            vector<int> charArr(26, 0);
            for (auto const& c : str) {
                charArr[c - 'a']++;
            }
            string key = "";
            for (auto const& n : charArr) {
                key += to_string(n) + ',';
            }
            dict[key].push_back(str);
        }

        for (auto const& [a, b] : dict) {
            result.push_back(b);
        }
        return result;
    }
};