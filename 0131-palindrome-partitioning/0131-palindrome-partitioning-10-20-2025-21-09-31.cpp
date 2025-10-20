class Solution {
public:
    vector<vector<string>> partition(string s) {
        // backtrack, check if current path is palindrome
        // if yes, continue
        // if no, return
        // until index = last index
        // TC: O(2^16 * 16)
        // SC: O(1)
        vector<vector<string>> result;
        vector<string> path;
        partitionHelper(result, s, path, 0);
        return result;
    }

    void partitionHelper(vector<vector<string>>& result, string s, vector<string>& path, int start) {
        if (start == s.size()) {
            result.push_back(path);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                partitionHelper(result, s, path, i + 1) ;
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};