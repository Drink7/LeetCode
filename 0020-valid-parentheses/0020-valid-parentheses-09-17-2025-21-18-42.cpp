class Solution {
public:
    bool isValid(string s) {
        // use stack
        // TC: O(n)
        // SC: O(n)
        stack<char> parenthesesStack;
        for (auto const& c : s) {
            if (parenthesesStack.size() == 0) {
                parenthesesStack.push(c);
            } else {
                char stackTop = parenthesesStack.top();
                if ((stackTop == '(' && c == ')') ||
                    (stackTop == '[' && c == ']') ||
                    (stackTop == '{' && c == '}')) {
                    parenthesesStack.pop();
                } else {
                    parenthesesStack.push(c);
                }
            }
        }
        return (parenthesesStack.size() == 0);
    }
};