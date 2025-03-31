class Solution {
public:
    string clearDigits(string s) {
        // stack-based
        // TC: O(n)
        // SC: O(n)
        vector<char> clearStack;
        for (auto const& c : s) {
            if (clearStack.empty()) {
                clearStack.push_back(c);
            } else {
                if (isdigit(c)) {
                    clearStack.pop_back();
                } else {
                    clearStack.push_back(c);
                }
            }
        }
        string str(clearStack.begin(), clearStack.end());
        return str;
    }
};