class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // similar to Isomorphic Strings
        // TC: O(n)
        // SC: O(n)
        vector<string> strArr;
        string token = "";
        stringstream ss(s);

        while (ss >> token) {
            strArr.push_back(token);
        }

        if (pattern.size() != strArr.size()) {
            return false;
        }

        unordered_map<char, string> pDict;
        unordered_map<string, char> sDict;
        for (int i = 0; i < pattern.size(); i++) {
            pDict[pattern[i]] = strArr[i];
            sDict[strArr[i]] = pattern[i];
        }

        // check
        for (int i = 0; i < pattern.size(); i++) {
            if (pDict[pattern[i]] != strArr[i] || sDict[strArr[i]] != pattern[i]) {
                return false;
            }
        }
        return true;
    }
};