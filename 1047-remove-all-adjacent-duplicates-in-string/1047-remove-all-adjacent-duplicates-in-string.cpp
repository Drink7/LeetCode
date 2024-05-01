class Solution {
public:
    string removeDuplicates(string s) {
        /*
        // use stack to remove adjacent letters
        // TC: O(n)
        // SC: O(n)
        stack<char> resultStack;
        string result = "";
        for (auto const& c : s) {
            if (resultStack.empty()) {
                resultStack.push(c);
            } else {
                if (resultStack.top() == c) {
                    resultStack.pop();
                } else {
                    resultStack.push(c);
                }
            }
        }

        // concat result
        int stackSize = resultStack.size();
        for (int i = 0; i < stackSize; i++) {
            result += resultStack.top();
            resultStack.pop();
        }
        reverse(result.begin(), result.end());
        return result;
        */

        // more elegant
        string result = "";
        for (auto const& c : s) {
            if (result.empty()) {
                result += c;
            } else {
                if (result.back() == c) {
                    result.pop_back();
                } else {
                    result += c;
                }
            }
        }
        return result;
    }
};