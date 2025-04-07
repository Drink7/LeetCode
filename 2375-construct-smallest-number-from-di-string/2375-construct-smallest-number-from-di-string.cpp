class Solution {
public:
    string smallestNumber(string pattern) {
        // Easy breezy approach. Use a stack-based greedy method:
        // – Go through pattern, pushing numbers (1 to 9) onto a stack.
        // – Whenever you hit an 'I' (or reach the end), pop everything from the stack to maintain the correct order.
        // – Keep adding popped elements to the result, and boom – you’re done! :)
        // TC: O(1)
        // SC: O(1)
        stack<int> patternStack;
        string result = "";
        for (int i = 0; i <= pattern.size(); i++) {
            patternStack.push(i + 1);
            if (pattern[i] == 'I') {
                while (!patternStack.empty()) {
                    result += patternStack.top() + '0';
                    patternStack.pop();
                }
            }
        }

        while (!patternStack.empty()) {
            result += patternStack.top() + '0';
            patternStack.pop();
        }
        return result;
    }
};