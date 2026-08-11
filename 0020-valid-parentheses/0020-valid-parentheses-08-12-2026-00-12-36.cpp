class Solution {
public:
    bool isValid(string s) {
        // stack
        // TC: O(n)
        // SC: O(n)
        stack<char> s_stack;
        for (auto const& c : s) {
            if (s_stack.size() == 0) {
                s_stack.push(c);
            } else {
                if ((c == ')' && s_stack.top() == '(') ||
                    (c == ']' && s_stack.top() == '[') ||
                    (c == '}' && s_stack.top() == '{')) {
                    s_stack.pop();
                } else {
                    s_stack.push(c);
                }
            }
        }
        return s_stack.size() == 0;
    }
};