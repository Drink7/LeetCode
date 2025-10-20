class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // hash map store int, char
        // use combinations skill
        // only append when path = digits.size()
        // TC: O(2^4^3)
        // SC: O(2^4^3)
        vector<string> result;
        string path = "";
        helper(digits, 0, path, result);
        return result;  
    }

    void helper(string& digits, int start, string path, vector<string>& result) {
        if (start == digits.size()) {
            result.push_back(path);
            return;
        }

        int num = digits[start] - '0';
        for (auto const& c : dict[num]) {
            path += c;
            helper(digits, start + 1, path, result);
            path.pop_back();
        }
    }

private:
    vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};