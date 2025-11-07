class Solution {
public:
    string decodeString(string s) {
        // num will store in num stack
        // strin will store in str stack, the str stack is for prefix concat
        // curr record current string
        // num record current num
        // TC: O(n)
        // SC: O(n)
        stack<int> numStack;
        stack<string> prefixStack;
        string curr = "";
        int num = 0;

        for (auto const& c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                numStack.push(num);
                num = 0;
                prefixStack.push(curr);
                curr = "";
            } else if (c == ']') {
                // need to repeat curr with numStack top, and then concat prefixStack top with it
                string tmp = curr;
                curr = prefixStack.top();
                prefixStack.pop();

                int repeat = numStack.top();
                numStack.pop();

                for (int i = 0; i < repeat; i++) {
                    curr += tmp;
                }
            } else {
                curr += c;
            }
        }
        return curr;
    }
};