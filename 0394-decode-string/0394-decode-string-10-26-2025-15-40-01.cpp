class Solution {
public:
    string decodeString(string s) {
        // stk
        // num must before [
        // pop when the incoming is ]
        // then keep poping until the [, then pop the num
        // stoi num, calculate the number * string then push back to stk
        // keep doing until go through the s
        // stk.top is the ans
        // TC: O(n)
        // SC: O(n)
        stack<char> stk;
        string result;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == ']') {
                // pop the string
                string tmp = "";
                while (stk.top() != '[') {
                    tmp = stk.top() + tmp;
                    stk.pop();
                }

                stk.pop(); // pop '['

                // find num
                string numStr = "";
                while (!stk.empty() && isdigit(stk.top())) {
                    numStr = stk.top() + numStr;
                    stk.pop();
                }
                
                int num = stoi(numStr);
                string subStr = "";
                for (int i = 0; i < num; i++) {
                    subStr += tmp;
                } 


                for (auto const& c : subStr) {
                    stk.push(c);
                }
            } else {
                stk.push(s[i]);
            }
        }

        while (stk.size() > 0) {
            result = stk.top() + result;
            stk.pop();
        }
        return result;
    }
};