class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // Similar to Isomorphic Strings
        // Split string skill using stringstream
        // TC: O(n)
        // SC: O(n)

        // Skill 1
        vector<string> splitList;
        string token;
        stringstream ss(s);

        /*
        // Skill 1
        while (getline(ss, token, ' ')) {
            splitList.push_back(token);
        }
        */

        // Skill 2
        while (ss >> token) {
            splitList.push_back(token);
        }

        if (splitList.size() != pattern.size()) {
            return false;
        }

        unordered_map<string, char> pDict;
        unordered_map<char, string> sDict;
        for (int i = 0; i < pattern.size(); i++) {
            sDict[pattern[i]] = splitList[i];
            pDict[splitList[i]] = pattern[i];
        }

        for (int i = 0; i < pattern.size(); i++) {
            if (sDict[pattern[i]] != splitList[i] || pDict[splitList[i]] != pattern[i]) {
                return false;
            }
        }
        return true;
    }
};