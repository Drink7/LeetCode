class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // TC: O(m + n), m is str1 length, n is str2 length
        // SC: O(m + n)
        if (str1.size() < str2.size()) {
            return gcdOfStrings(str2, str1);
        }

        if (str1 == str2) {
            return str1;
        }

        if (str1.find(str2) != 0) {
            return "";
        }
    
        str1 = str1.substr(str2.size());
        return gcdOfStrings(str1, str2);
    }
};