class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // TC: O(m + n)
        // SC: O(1)

        if (str1 + str2 != str2 + str1) {
            return "";
        }

        if (str1 == str2) {
            return str1;
        } else if (str1.size() > str2.size()) {
            return gcdOfStrings(str2, str1.substr(str2.size()));
        } else {
            return gcdOfStrings(str1, str2.substr(str1.size()));
        }
    }
};