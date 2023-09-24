class Solution {
public:
    bool isValid(string s) {
        // stack store index
        // TC: O(n)
        // SC: O(n)
        stack<int> validStack;
        for (int i = 0; i < s.size(); i++) {
            if (validStack.empty()) {
                validStack.push(i);
            } else {
                char c = s[i];
                if (c == ')' || c == '}' || c == ']') {
                    char top = s[validStack.top()];
                    if (top == '(' && c == ')' ||
                        top == '{' && c == '}' ||
                        top == '[' && c == ']') {
                        validStack.pop();
                    } else {
                        validStack.push(i);
                    }
                } else {
                    validStack.push(i);
                }
            }
        }
        return validStack.empty();
    }
};