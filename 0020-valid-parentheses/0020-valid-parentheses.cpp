class Solution {
public:
    bool isValid(string s) {
        // Use stack
        // TC: O(n)
        // SC: O(n)
        int n = s.size();
        stack<char> parentheseStack;

        // start push from left
        int left = 0;
        while (left < n) {
            // Check when we push
            if (parentheseStack.empty()) {
                parentheseStack.push(s[left]);
            } else {
                if ((parentheseStack.top() == '(' && s[left] == ')') ||
                    (parentheseStack.top() == '[' && s[left] == ']') ||
                    (parentheseStack.top() == '{' && s[left] == '}')) {
                    parentheseStack.pop();
                } else {
                    parentheseStack.push(s[left]);
                }
            }
            left++;
        }

        return parentheseStack.empty();
    }
};