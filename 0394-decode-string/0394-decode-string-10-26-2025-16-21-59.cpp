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
        /*
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
        */

        stack<string> strStk;
        stack<int> numStk;
        string cur = "";
        int n = s.size();
        int num = 0;
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                num = num * 10 + s[i] - '0';
            } else if (s[i] == '[') {
                // store current num and str
                // current number is to repeat later str
                // current str is to concat later
                numStk.push(num);
                num = 0;
                strStk.push(cur);
                cur = "";
            } else if (s[i] == ']') {
                string tmp = cur; // repeat this tmp later
                cur = strStk.top();
                strStk.pop();

                int repeat = numStk.top();
                numStk.pop();
                for (int i = 0; i < repeat; i++) {
                    cur += tmp;
                }
            } else {
                cur += s[i];
            }
        }
        return cur;
    }
};