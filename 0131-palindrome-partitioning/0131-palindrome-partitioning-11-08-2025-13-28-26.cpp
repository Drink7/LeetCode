class Solution {
public:
    vector<vector<string>> partition(string s) {
        // brute force
        // traverse all string and find pivot
        // check palindrome
        // check each substring is palindrome or not
        // if not, return
        // if true (start == s.size()), append to result
        vector<vector<string>> result;
        vector<string> path;
        dfs(result, s, path, 0);
        return result;
    }

    void dfs(vector<vector<string>>& result, string& s, vector<string>& path, int startId) {
        if (startId == s.size()) {
            result.push_back(path);
            return;
        }

        for (int i = startId; i < s.size(); i++) {
            string tmp = s.substr(startId, i - startId + 1);
            if (checkPalindrome(tmp)) {
                path.push_back(tmp);
                dfs(result, s, path, i + 1);
                path.pop_back();
            }
        }

    }

    bool checkPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
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