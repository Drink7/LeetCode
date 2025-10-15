class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        // traverse from back, if substring size == k, add dash
        // reverse at the end
        // TC: O(n)
        // SC: O(n)
        int n = s.size();
        string result = "";
        string subString = "";
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '-') {
                continue;
            } else {
                char c = s[i];
                if (isalpha(c)) {
                    c = toupper(c);
                }
                subString += c;

                if (subString.size() == k) {
                    result += subString;
                    result += '-';
                    subString = "";
                }
            }
        }

        if (subString.size() > 0) {
            result += subString;
        } else if (result != "") {
            result.pop_back(); // erase final dash
        }
        reverse(result.begin(), result.end());
        return result;
    }
};