class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        // traverse all char
        // if nums, just go to next char
        // if char, go lower case and upper case
        // until the end, save and return
        // TC: O(n * 2^n) -> O(n * 2^n)
        // SC: O(n * 2^n) -> O(n)
        vector<string> result;
        permutationHelper(s, result, 0);
        return result;
    }

    void permutationHelper(string& s, vector<string>& result, int start) {
        if (start >= s.size()) {
            result.push_back(s);
            return;
        }

        char c = s[start];
        if (isdigit(c)) {
            permutationHelper(s, result, start + 1);
        } else {
            // lower
            s[start] = tolower(c);
            permutationHelper(s, result, start + 1);

            // upper
            s[start] = toupper(c);
            permutationHelper(s, result, start + 1);
        }

        s[start] = c;
    }
};