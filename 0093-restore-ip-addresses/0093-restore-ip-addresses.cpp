class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // use backtracking for all possible answer
        // TC: O(len(s)
        // SC: O(len(s)
        if (s.size() < 4 || s.size() > 12) {
            return result;
        }
        dfs(s, 0, "");
        return result;
    }

    void dfs(string s, int divided, string path) {
        if (divided == 4) {
            if (s.empty()) {
                result.push_back(path);
            }
        } else {
            for (int i = 1; i <= 3; i++) {
                if (s.size() >= i && isValid(s.substr(0, i))) {
                    string remain = s.substr(i);
                    if (divided == 3) {
                        dfs(remain, divided + 1, path + s.substr(0, i));
                    } else {
                        dfs(remain, divided + 1, path + s.substr(0, i) + ".");
                    }
                } 
            }
        }
    }

    bool isValid(string s) {
        if (s.size() > 3) {
            return false;
        }

        if (s.size() > 1 && s[0] == '0') {
            return false;
        }

        int val = stoi(s);
        return (val >= 0 && val <= 255);
    }

private:
    vector<string> result;
};