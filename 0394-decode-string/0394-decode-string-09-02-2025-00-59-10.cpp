class Solution {
public:
    string decodeString(string s) {
        // only one stack
        // TC: O(n)
        // SC: O(n)
        stack<char> decodeStack;
        string result = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ']') {
                decodeStack.push(s[i]);
            } else {
                // start decode
                string base = "";
                while(decodeStack.top() != '[') {
                    base = decodeStack.top() + base;
                    decodeStack.pop();
                }

                // now the sStack top would be '['
                decodeStack.pop();

                string numStr = "";
                while(decodeStack.size() > 0 && decodeStack.top() >= '0' && decodeStack.top() <= '9') {
                    numStr = decodeStack.top() + numStr;
                    decodeStack.pop();
                }

                // start multiply
                int time = stoi(numStr);
                string tmp = "";
                for (int j = 0; j < time; j++) {
                    tmp += base;
                }

                // push back to stack
                for (auto const& c : tmp) {
                    decodeStack.push(c);
                }
            }
        }

        // concat the result
        while(decodeStack.size() > 0) {
            result = decodeStack.top() + result;
            decodeStack.pop();
        }
        return result;
    }
};