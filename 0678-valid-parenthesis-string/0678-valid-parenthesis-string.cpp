class Solution {
public:
    bool checkValidString(string s) {
        /*
        // way1: two pointer check
        // TC: O(n)
        // SC: O(1)
        int openCnt = 0;
        int closeCnt = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '*') {
                openCnt++;
            } else {
                openCnt--;
            }

            if (s[n - i - 1] == ')' || s[n - i - 1] == '*') {
                closeCnt++;
            } else {
                closeCnt--;
            }

            if (openCnt < 0 || closeCnt < 0) {
                return false;
            }
        }
        */

        // two stack
        // TC: O(n)
        stack<char> normalStack;
        stack<char> startStack;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                normalStack.push(i);
            } else if (s[i] == '*') {
                startStack.push(i);
            } else {
                if (normalStack.empty() && startStack.empty()) {
                    return false;
                }

                if (!normalStack.empty()) {
                    normalStack.pop();
                } else {
                    startStack.pop();
                }
            }
        }

        while (!normalStack.empty() && !startStack.empty()) {
            if (normalStack.top() > startStack.top()) {
                return false;
            }
            normalStack.pop();
            startStack.pop();
        }
        return normalStack.empty();
    }
};