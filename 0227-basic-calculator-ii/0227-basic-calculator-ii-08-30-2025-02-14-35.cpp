class Solution {
public:
    int calculate(string s) {
        // stack is used for num result
        // +, just push num
        // -, push the negative num
        // *, pop the stack and the current num, multiply then push back
        // /, pop the stack and the current num, divide then push back
        // stoi return int
        // TC: O(n)
        // SC: O(n)
        stack<int> numStack;
        string numStr = "";
        char sign = '+';
        for (int i = 0; i < s.size(); i++) {

            if (isdigit(s[i])) {
                numStr += s[i];
            }

            if (i == s.size() - 1 || (!isdigit(s[i]) && s[i] != ' ')) {
                if (sign == '+') {
                    numStack.push(stoi(numStr));
                } else if (sign == '-') {
                    numStack.push(-stoi(numStr));
                } else if (sign == '*') {
                    int numTop = numStack.top();
                    numStack.pop();
                    numStack.push(numTop * stoi(numStr));
                } else if (sign == '/') {
                    int numTop = numStack.top();
                    numStack.pop();
                    numStack.push(numTop / stoi(numStr));
                }
                numStr = "";
                sign = s[i];
            }
        }

        // sum up stack
        int result = 0;
        while (numStack.size() > 0) {
            result += numStack.top();
            numStack.pop();
        }
        return result;
    }
};