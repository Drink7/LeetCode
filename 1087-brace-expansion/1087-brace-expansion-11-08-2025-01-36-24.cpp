class Solution {
public:
    vector<string> expand(string s) {
        // backtracking to find {}
        // enumerate all answer
        // TC: O(2^n), n is s.size()
        // SC: O((2^n)
        vector<string> result;
        string path = "";
        backtrack(result, path, s, 0);
        sort(result.begin(), result.end());
        return result;
    }

    void backtrack(vector<string>& result, string path, string& s, int index) {
        // backtrack stop condition
        // if the s[index] == '{', find all possible option and the next one after }
        // backtrack
        if (index == s.size()) {
            result.push_back(path);
            return;
        }

        vector<char> options;
        if (s[index] == '{') {
            // find '}'
            while (s[index] != '}') {
                if (isalpha(s[index])) {
                    options.push_back(s[index]);
                }
                index++;
            }

            for (auto const& c : options) {
                path.push_back(c);
                backtrack(result, path, s, index + 1);
                path.pop_back();
            }
        } else {
            path.push_back(s[index]);
            backtrack(result, path, s, index + 1);
        }
    }
};