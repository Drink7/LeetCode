class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // unordered_map<char, string>
        // dont use map, use string array
        // backtrack, start is digits start
        // TC: O(4^4)
        // SC: O(1)
        string dict[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        if (digits.empty()) {
            return result;
        }
        combinationHelper(dict, digits, result, "", 0);
        return result;
    }

    void combinationHelper(string dict[], string& digits, vector<string>& result, string tmp, int start) {
        if (start == digits.size()) {
            result.push_back(tmp);
            return;
        }

        int index = digits[start] - '0';
        string cur = dict[index];

        for (auto const& c : cur) {
            tmp += c;
            combinationHelper(dict, digits, result, tmp, start + 1);
            tmp.pop_back();
        }
    }
};