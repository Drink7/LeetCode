class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        // traverse all char
        // if nums, just go to next char
        // if char, go lower case and upper case
        // until the end, save and return
        vector<string> result;
        string path = "";
        permutationHelper(s, result, path, 0);
        return result;
    }

    void permutationHelper(string& s, vector<string>& result, string path, int start) {
        if (start >= s.size()) {
            result.push_back(path);
            return;
        }

        char c = s[start];
        if (isdigit(c)) {
            path.push_back(c);
            permutationHelper(s, result, path, start + 1);
        } else {
            // lower
            char lowerC = tolower(c);
            path.push_back(lowerC);
            permutationHelper(s, result, path, start + 1);

            path.pop_back();

            // upper
            char upperC = toupper(c);
            path.push_back(upperC);
            permutationHelper(s, result, path, start + 1);
        }
    }
};