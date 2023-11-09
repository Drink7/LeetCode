class Solution {
public:
    bool isValid(string s) {
        // stack
        // TC: O(n), n is the length of string
        // SC: O(n)
        stack<char> validStack;
        for (auto const& c : s) {
            if (c == '(' || c == '[' || c == '{') {
                validStack.push(c);
            } else {
                if (c == ')' && !validStack.empty() && validStack.top() == '(') {
                    validStack.pop();
                } else if (c == ']' && !validStack.empty() && validStack.top() == '[') {
                    validStack.pop();
                } else if (c == '}' && !validStack.empty() && validStack.top() == '{') {
                    validStack.pop();
                } else {
                    return false;
                }
            }
        }
        return validStack.empty();

    }
};