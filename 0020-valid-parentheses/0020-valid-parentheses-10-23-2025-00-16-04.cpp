class Solution {
public:
    bool isValid(string s) {
        // use stack for remove parentheses
        // TC: O(n)
        // SC: O(n)
        stack<char> stk;
        for (auto const& c : s) {
            if (stk.empty()) {
                stk.push(c);
            } else {
                if ((stk.top() == '(' && c == ')') ||
                    (stk.top() == '[' && c == ']') ||
                    (stk.top() == '{' && c == '}')) {
                    stk.pop();
                } else {
                    stk.push(c);
                }
            }
        }
        return stk.size() == 0;
    }
};