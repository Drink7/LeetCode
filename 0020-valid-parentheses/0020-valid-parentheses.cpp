class Solution {
public:
    bool isValid(string s) {
        // parentheses -> stack
        // TC: O(n)
        // SC: O(n)
        stack<char> s_stack;
        for (auto const& c : s) {
            if (s_stack.size() == 0) {
                s_stack.push(c);
            } else {
                char top = s_stack.top();
                if (top == '(' && c == ')') {
                    s_stack.pop();
                } else if (top == '{' && c == '}') {
                    s_stack.pop();
                } else if (top == '[' && c == ']') {
                    s_stack.pop();
                } else {
                    s_stack.push(c);
                }
            }
        }
        return s_stack.size() == 0;
    }
};