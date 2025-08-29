class Solution {
public:
    string decodeString(string s) {
        // The encoding rule is: k[encoded_string]
        // TC: O(n)
        // SC: O(n)
        // assume input is valid
        stack<char> sStack;
        string result = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ']') {
                sStack.push(s[i]);
            } else {
                string substr = "";
                while (sStack.top() != '[') {
                    substr = sStack.top() + substr;
                    sStack.pop();
                }

                // now the sStack top would be '['
                sStack.pop();

                string numStr = "";
                while (!sStack.empty() && sStack.top() >= '0' && sStack.top() <= '9') {
                    numStr = sStack.top() + numStr;
                    sStack.pop();
                }

                int num = stoi(numStr);
                string tmp = "";
                for (int j = 0; j < num; j++) {
                    tmp += substr;
                }

                // add back to stack
                for (auto const& c : tmp) {
                    sStack.push(c);
                }
            }
        }

        // pop and join from stack
        while (!sStack.empty()) {
            result = sStack.top() + result;
            sStack.pop();
        }
        return result;
    }
};