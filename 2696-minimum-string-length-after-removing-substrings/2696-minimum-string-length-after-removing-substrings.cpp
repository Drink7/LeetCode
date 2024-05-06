class Solution {
public:
    int minLength(string s) {
        // use stack
        stack<char> strStack;
        for (auto const& c : s) {
            if (strStack.size() > 0) {
                if (strStack.top() == 'A' && c == 'B') {
                    strStack.pop();
                    continue;
                } else if (strStack.top() == 'C' && c == 'D') {
                    strStack.pop();
                    continue;
                } else {
                    strStack.push(c);    
                }
            } else {
                strStack.push(c);
            }
        }
        return strStack.size();
    }
};