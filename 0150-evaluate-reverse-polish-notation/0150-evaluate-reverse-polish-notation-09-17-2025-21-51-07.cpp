class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // TC: O(n)
        // SC: O(n)
        stack<int> intStack;
        for (auto const& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // pop two integer
                int second = intStack.top();
                intStack.pop();
                int first = intStack.top();
                intStack.pop();

                // calculate
                if (token == "+") {
                    intStack.push(first + second);
                } else if (token == "-") {
                    intStack.push(first - second);
                } else if (token == "*") {
                    intStack.push(first * second);
                }  else {
                    intStack.push(first / second);
                }
            } else {
                int tokenInt = stoi(token);
                intStack.push(tokenInt);
            }
        }
        return intStack.top();
    }
};