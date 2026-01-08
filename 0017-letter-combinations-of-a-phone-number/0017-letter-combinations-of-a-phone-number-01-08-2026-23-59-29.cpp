class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // backtracking
        vector<string> result;
        string path = "";

        combinationHelper(digits, 0, path, result);
        return result;
    }

    void combinationHelper(string& digits, int start, string path, vector<string>& result) {
        if (start >= digits.size()) {
            result.push_back(path);
            return;
        }

        //traverse all char in digits[start]
        char curNum = digits[start];
        for (int i = 0; i < dict[curNum].size(); i++) {
            path += dict[curNum][i];
            combinationHelper(digits, start + 1, path, result);
            path.pop_back();
        }
    }
private:
    unordered_map<char, string> dict = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
};