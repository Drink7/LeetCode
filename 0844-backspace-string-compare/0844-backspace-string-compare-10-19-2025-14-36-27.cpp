class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // '#' means pop
        // TC: O(m + n)
        // SC: O(1)
        string newS = "";
        string newT = "";
        for (auto const& c : s) {
            if (c == '#') {
                if (newS != "") {
                    newS.pop_back();
                }
            } else {
                newS += c;
            }
        }

        for (auto const& c : t) {
            if (c == '#') {
                if (newT != "") {
                    newT.pop_back();
                }
            } else {
                newT += c;
            }
        }
        return newT == newS;
    }
};