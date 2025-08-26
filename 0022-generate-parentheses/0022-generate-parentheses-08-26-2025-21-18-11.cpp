class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // TC: O(2^n)
        // SC: O(2^n)        
        vector<string> result;
        string path = "";
        helper (n, n, result, path);
        return result;
    }

    void helper(int left, int right, vector<string>& result, string path) {
        if (left == 0 && right == 0) {
            result.push_back(path);
            return;
        }

        // left must <= right
        if (left > 0) {
            helper(left - 1, right, result, path + '(');
        }

        if (right > left) {
            helper(left, right - 1, result, path + ')');
        }
    }
};